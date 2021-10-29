#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll to[200200];
ll to1[200200];
ll sum[10][200200];

void init() {
    to[0] = to1[0] = 1;
    for(int i=1; i<=200000; i++) to[i] = to[i-1] * 2 % mod;
    for(int i=1; i<=200000; i++) to1[i] = to1[i-1] * 10 % mod;
    for(int i=1; i<=9; i++) {
        // sum[i][0] = to[n-1]*i%mod;
        for(int j=1; j<n; j++) {
            sum[i][j] = (sum[i][j-1] + to[n-1-j]*to1[j-1]*i % mod) % mod;
        }
    }
}

char s[200200];

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = strlen(s);
    init();
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll r = s[i] - '0';
        ans += sum[r][n-1-i];
        ans += r * to[i] * to1[n-i-1];
        ans %= mod;
    }
    // cout << sum[1][3] << endl;
    cout << ans << endl;
    return 0;
}