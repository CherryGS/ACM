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

int mp[10][10];
int bk[10];
int n, k;
int ans;

void dfs(cint loc, cint co, cint num) {
    if(co > k) return;
    if(co + mp[loc][1] == k && num==n) {++ans;return;}
    for(int i=1; i<=n; i++) {
        if(i!=loc && !bk[i]) {
            bk[i] = 1;
            dfs(i, co+mp[loc][i], num+1);
            bk[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> mp[i][j];
    bk[1] = 1;
    dfs(1, 0, 1);
    cout << ans;
    return 0;
}