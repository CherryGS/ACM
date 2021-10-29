#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll mp[9][9];
ll k;
bool bk[9];
int ans;

void dfs(cint loc, cint num, ll sum) {
    // cout << loc << ' ' << num << ' ' << sum << endl;
    if(sum > k) return;
    if(num == n) {
        if(sum+mp[loc][1] == k) ++ans;
        return;
    }
    for(int i=2; i<=n; i++) 
        if(!bk[i]) {
            bk[i] = 1;
            dfs(i, num+1, sum+mp[loc][i]);
            bk[i] = 0;
        }
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> mp[i][j];
    bk[1] = 1;
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}