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
int a[100100], b[100100];
ll num[100100];
ll sum[100100];
bool vis[100100];

void solve(cint T) {
    n = 0;
    cin >> n >> m;
    if(n == 0) { return; }
    int mx = max(n, m);
    for(int i=0; i<=mx; i++) { sum[i] = num[i] = 0; }
    for(int i=0; i<=mx; i++) { vis[i] = 0; }
    for(int i=0; i<n; i++) { cin >> a[i]; }
    for(int i=0; i<m; i++) { cin >> b[i]; }
    for(int i=0; i<m; i++) {
        if(!vis[i]) {
            int s = 0, t = i;
            while(true) {
                vis[t] = 1;
                ++s;
                if(vis[b[t]]) { break; }
                t = b[t];
            }
            ++num[s];
        }
    }
    for(int i=1; i<=mx; i++) {
        for(int j=i; j<=mx; j+=i) {
            sum[j] += num[i] * i;
        }
    }

    ll ans = 1;
    for(int i=0; i<=mx; i++) { vis[i] = 0; }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            int s = 0, t = i;
            while(true) {
                vis[t] = 1;
                ++s;
                if(vis[a[t]]) { break; }
                t = a[t];
            }
            ans = ans * sum[s] % mod1;
        }
    }
    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=10000;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}