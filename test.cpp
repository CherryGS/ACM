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

int n;
char s[100100];
ll dp[100100][2];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> s;
        dp[1][0] = 1;
        for(int i=2; i<=n; i++) {
            if(i>2 && s[i-1-2] == 'A') {
                dp[i][0] += dp[i-2][0] + dp[i-2][1];
                dp[i][0] %= mod2;
            }
            dp[i][1] += dp[i-1][0]+dp[i-1][1];
            dp[i][1] %= mod2;
        }
        cout << (dp[n][0] + dp[n][1]) % mod2 << endl;
    }
    return 0;
}