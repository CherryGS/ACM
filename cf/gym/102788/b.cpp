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

ll n, sum;
map<ll, int> e;
vector<pair<ll, int>> q;
vector<pair<ll, ll>> ans;

void pre(ll x) {
    ll p = sqrt(x);
    for(int i=2; i<=p && i<=x; i++) {
        while(!(x%i)) {
            e[i]++;
            x /= i;
        }
    }
    if(x != 1) e[x]++;
}

ll cacu(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs;
        bs = bs * bs;
        x >>= 1;
    }
    return ans;
}

void dfs(cint x, ll val) {
    if(sum / val / val < 1) return;
    if(x == q.size()) {
        ans.push_back({val, sum/val});
        return;
    }
    for(int i=0; i<=q[x].second; i++) {
        ll r = cacu(q[x].first, i);
        // cout << x << ' ' << val << ' ' << r << ' ' << sum << endl;
        if(sum / val / val / r / r < 1) return;
        dfs(x+1, val*r);
    }
}

void solve(cint T) {
    cin >> n;
    sum = n*(n+1)*4ll;
    pre(4);
    pre(n);
    pre(n+1);
    for(auto k: e) {
        // cout << k.first << ' ' << k.second << endl;
        q.push_back(k);
    }
    dfs(0, 1);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto k: ans) {
        cout << k.first + n*2 + 2 << ' ' << k.second + n*2 + 2 << endl;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}