#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, m;
char tab[101][101];
queue<pair<int,int>>q;

void sol() {
    while(!q.empty()) {
        auto k = q.front();
        q.pop();
        int x=k.first, y=k.second;
        int x1 = x+1, y1=y+1;
        if(x == n-1) x1=x-1;
        if(y == m-1) y1=y-1;
        ++x, ++y, ++x1, ++y1;
        cout << x << ' ' << y << ' ' << x1 << ' ' << y << ' ' << x1 << ' ' << y1 << endl;
        cout << x << ' ' << y << ' ' << x << ' ' << y1 << ' ' << x1 << ' ' << y1 << endl;
        cout << x << ' ' << y << ' ' << x1 << ' ' << y << ' ' << x << ' ' << y1 << endl;
    }
}

int main() {
    cin >> t;
    while(t--) {
        int ans=0;
        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> tab[i];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(tab[i][j]=='1') {
                    q.push(make_pair(i,j));
                    ++ans;
                }
        cout << ans*3 << endl;
        sol();
    }
    return 0;
}