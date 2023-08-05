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
int a[200200];
multiset<pair<int, int>> e;

void solve(cint T) {
    e.clear();
    cin >> n >> m;
    for(int i=1; i<=n; i++) { a[i] = 0; }
    for(int i=1; i<=m; i++) {
        int tmp;
        cin >> tmp;
        a[tmp] += 1;
    }
    for(int i=1; i<=n; i++) { e.insert({a[i], a[i]}); }
    while(true) {
        auto l = e.begin();
        auto r = e.rbegin();
        // cout << l->first << ' ' << r->first << '\n';
        if(r->second == 0 || r->first - l->first <= 2) { break; }
        auto k1 = pii{l->first+2, l->second}; 
        auto k2 = pii{r->first-1, r->second-1};
        e.erase(e.begin());
        e.erase((--e.end()));
        e.insert(k1);
        e.insert(k2);
    }
    cout << e.rbegin()->first << '\n';
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