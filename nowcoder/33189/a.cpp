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
int w[100100];
int q[100100];
double dp[21];

struct node {
    ll w, q;
};

void solve(cint T) {
    cin >> n >> m;
    vector<node> e;
    for(int i=1; i<=n; i++) { cin >> w[i]; }
    for(int i=1; i<=n; i++) { cin >> q[i]; }
    for(int i=1; i<=n; i++) { e.push_back({w[i], q[i]}); }
    stable_sort(e.begin(), e.end(), [](const node&a, const node&b) { 
        return b.w*(a.q-10000) == a.w*(b.q-10000) ? a.q > b.q : b.w*(a.q-10000) > a.w*(b.q-10000); 
    } );
    double ans = .0;
    for(int i=n; i>=1; i--) {
        for(int j=m; j>=1; j--) {
            dp[j] = max(dp[j], dp[j-1]*(double)e[i-1].q/10000+e[i-1].w);
        }
        ans = max(ans, dp[m]);
    }
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}