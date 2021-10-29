#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, m;
char mp[505][505];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> mp[i][j];
        if(m == 1) for(int i=1; i<=n; i++) mp[i][1] = 'X';
        for(int i=1+(m%3 != 1); i<=m; i+=3) {
            for(int j=1; j<=n; j++) mp[j][i] = 'X';
            if(i+3<=m)
            if(mp[1][i+1] == 'X' || mp[1][i+2] == 'X' || n == 1) {
                mp[1][i+1] = mp[1][i+2] = 'X';
            } else {
                mp[2][i+1] = mp[2][i+2] = 'X';
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++)
                cout << mp[i][j];
                cout << endl;
        }
    }
    return 0;
}