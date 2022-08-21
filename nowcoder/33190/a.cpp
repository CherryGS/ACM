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
ll x[2002], y[2002];
int dis[2002];

ll cacu(int i, int j) {
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> x[i] >> y[i]; }
    vector<pair<ll, pii>> q;
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=n; j++) if(i != j) {
            q.push_back({cacu(i, j), {i, j}});
        }
    }
    int ass = 0;
    sort(q.begin(), q.end(), [](auto &a, auto &b) { return a.first == b.first ? a.second.first < b.second.first : a.first > b.first; } );
    queue<pii> e;
    for(int i=0; i<q.size(); i++) {
        auto k = q[i].second;
        cout << k.first << ' ' << k.second << ' ' << q[i].first << endl;
        if(i > 0) {
            if(q[i].first != q[i-1].first) {
                while(!e.empty()) { auto r = e.front(); e.pop(); dis[r.first] = max(dis[r.first], r.second); }
            }
        }
        if(k.first == 0) { dis[k.second] = 1; }
        else if(dis[k.first] != 0) { e.push({k.second, dis[k.first]+1}); }
    }
    while(!e.empty()) { auto r = e.front(); e.pop(); dis[r.first] = max(dis[r.first], r.second); }
    for(int i=1; i<=n; i++) { ass = max(ass, dis[i]); }
    cout << ass << '\n';
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