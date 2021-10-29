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

int cnt;
ll dp[200200][21];
ll t, d;
int m;

ll query(cint le) {
    int n=0;
    while((1<<n) <= le) { ++n; }
    --n;
    t = max(dp[cnt][n], dp[cnt-le+(1<<n)][n]);
    return t;
}

void insert(ll x) {
    dp[++cnt][0]=x;
    for(int i=1; i<=20; i++)
        if(cnt-(1<<(i-1)) > 0)
            dp[cnt][i] = max(dp[cnt][i], max(dp[cnt][i-1], dp[cnt-(1<<(i-1))][i-1]));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> d;
    char a;
    int b;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        if(a=='Q') cout << query(b) << endl;
        else insert((b+t)%d);
    }
    return 0;
}