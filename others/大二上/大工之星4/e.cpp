#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

char s[1000100];
ll dp[2];

void solve(cint T) {
    cin >> s;
    int n = strlen(s);
    dp[0] = dp[1] = 0;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 's') ++dp[0];
        else if(s[i] == 'o') dp[1] = (dp[1] + dp[0]) % mod1;
        else if(s[i] == 'n') ans = (ans + dp[1]) % mod1;
    }
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}