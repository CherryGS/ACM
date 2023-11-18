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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m;
int a[200200];
int b[200200];
int c[200200];
map<int, int> e;
vector<int> q[200200];

void solve(cint T) {
    cin >> n >> m;
    for(int i=0; i<=n+1; i++) { q[i].clear(); }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    a[0] = inf_int; a[n+1] = -1;
    for(int i=1; i<=m; i++) { cin >> b[i]; }
    c[n+1] = a[n+1];
    for(int i=n; i>=1; i--) { c[i] = max(c[i+1], a[i]); }
    sort(b+1, b+1+m, [](const int&a, const int&b) { return a > b; } );
    for(int i=1; i<=m; i++) {
        int l = 0, r = n+1, mid;
        while(l < r) {
            mid = l + (r-l+1) / 2;
            if(c[mid] >= b[i]) { l = mid; }
            else { r = mid - 1; }
        }
        q[l].push_back(i);
    }
    for(auto &k: q[0]) { cout << b[k] << ' '; }
    for(int i=1; i<=n; i++) {
        cout << a[i] << ' ';
        for(auto &k: q[i]) { cout << b[k] << ' '; }
    }
    for(auto &k: q[n+1]) { cout << b[k] << ' '; }
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
