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

int n, m;
int a[1001];
ll dp[1001][1001];

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dp[i][j] < dp[0][1]) {
                multiset<int> e;
                for(int k=i+1; k<=n; k++) {
                    int num = (k-i) - floor(0.05*(k-i)) - 1;
                    e.insert(a[k]);
                    auto r = e.begin();
                    while(num > 0) { ++r; --num; }
                    dp[k][j+1] = min(dp[k][j+1], dp[i][j] + *r);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}