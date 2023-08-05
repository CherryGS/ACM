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

int n, q;
int a[100100];
int ans[100100];
int p[100100];
bool vis[100100];

struct node {
    int x, y, v;
};

void solve(cint T) {
    cin >> n >> q;
    vector<node> e;
    for(int i=1; i<=n; i++) { a[i] = (1<<30)-1; }
    int x, y, v;
    for(int i=1; i<=q; i++) {
        cin >> x >> y >> v;
        if(x > y) { swap(x, y); }
        a[x] &= v;
        a[y] &= v;
        e.push_back({x, y, v});
        vis[x] = 1;
        vis[y] = 1;
    }
    sort(e.begin(), e.end(), 
        [](const node&a, const node&b) { return a.x == b.x ? a.y > b.y : a.x < b.x; } );
    for(auto &k: e) {
        for(int i=29; i>=0; i--) {
            if(((a[k.x]>>i)&1) && (a[k.y]>>i)&1 && ((ans[k.y]>>i)^1)) {
                p[k.x] |= (1<<i);
                ans[k.y] |= (1<<i);
            }
        }
    }
    for(int i=1; i<=n; i++) { cout << ((a[i]^p[i])|ans[i])*vis[i] << ' '; }
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}