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

int t, n;
int ans[101][101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1) {
            cout << 1 << endl;
            continue;
        } else if(n == 2) {
            cout << -1 << endl;
            continue;
        }
        ll tmp = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ans[j][i] = ++tmp;
        for(int i=1; i<=n; i+=2) {
            for(int j=1; j<n; j++) {
                tmp = ans[i][j];
                ans[i][j] = ans[i][j+1];
                ans[i][j+1] = tmp;
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++)
                cout << ans[i][j] << ' ';
                cout << endl;
        }
    }
    return 0;
}