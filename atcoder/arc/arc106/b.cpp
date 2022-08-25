#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n, m;

int bcj[200200];
ll value[200200][2];

inline int find(cint x) {return bcj[x] == x ? x: bcj[x] = find(bcj[x]);}

int main() {
    int a,b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) bcj[i] = i, cin >> value[i][0];
    for(int i = 1; i <= n; i++) cin >> value[i][1];
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        bcj[find(bcj[a])] = find(bcj[b]);
    }
    for(int i = 1; i <= n; i++) bcj[i] = find(bcj[i]);
    ll x1 = 0, x2 = 0;
    for(int i = 1; i <= n; i++)
        if(bcj[i] == 1) x1 += value[i][0], x2 += value[i][1];
    for(int i = 1; i <= n; i++)
        if(bcj[i] != i) value[bcj[i]][0] += value[i][0], value[bcj[i]][1] += value[i][1];
    for(int i = 1; i <= n; i++)
        if(bcj[i] == i)
            if(value[i][0] != value[i][1]) {
                cout << "No";
                return 0;
            }
    cout << "Yes";
    return 0; 
}