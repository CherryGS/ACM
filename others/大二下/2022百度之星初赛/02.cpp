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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
int c[100100];
bool vis[100100];

bool solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    ll ans = 0;
    for(int i=1; i<=n; i++) { ans -= 1ll*i*i*c[i]; }
    priority_queue<pii> e;
    for(int i=1; i<=k; i++) { e.push({c[i], i}); }
    for(int i=1; i<=n; i++) {
        if(k+i <= n) { e.push({c[k+i], k+i}); }
        auto u = e.top();
        e.pop();
        // cout << u.first << ' ';
        ans += 1ll * (u.first) * (k+i) * (k+i);
    }
    // cout << endl;
    cout << ans << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}