#include <bits/stdc++.h>
using namespace std;

//mt19937 rng(std::random_device{}());
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

int t, m;
int dp[1001];

void solve(cint T) {
    cin >> t >> m;
    dp[0] = 1;
    int ans = 1;
    int co, w;
    for(int i=1; i<=m; i++) {
        cin >> co >> w;
        for(int j=t-co; j>=0; j--) {
            if(dp[j]) dp[j+co] = max(dp[j+co], dp[j] + w);
            ans = max(ans, dp[j+co]);
        }
    }
    cout << ans - 1 << endl;
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