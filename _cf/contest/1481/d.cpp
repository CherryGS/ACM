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
char mp[1001][1001];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int x = 0, y = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin >> mp[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j && mp[i][j] == mp[j][i]) { x = i, y = j; break;}
        
        if(x) {
            cout << "YES" << endl;
            cout << y << ' ';
            for(int i=1; i<=m; i++)
                if(i&1) cout << x << ' ';
                else cout << y << ' ';
            cout << endl;
        } else {
            if(m&1) {
                cout << "YES" << endl;
                cout << 1 << ' ';
                for(int i=1; i<=m; i++)
                    if(i&1) cout << 2 << ' ';
                    else cout << 1 << ' ';
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}