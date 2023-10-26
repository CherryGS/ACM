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
int a[100100];
int b[100100];
int to[100100];
bool vis[100100];

void solve(cint T) {
    cin >> n >> m;
    for(int i=2; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) { cin >> b[i]; }
    for(int i=1; i<=n; i++) { to[i] = 0; vis[i] = 0; }
    a[1] = 1;
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    int pre = n;
    int l = n;
    to[0] = -1;
    for(int i=n; i>=1; i--) {
        while(l && a[l] >= b[i]) { --l; }
        if(l == 0) { break; }
        to[i] = l;
        --l;
        --pre;
    }
    to[1] = 0;
    for(int i=1; i<=n; i++) {
        if(a[to[i]] < b[i-1] && (to[i-1] == 0 || vis[to[i-1]] == 1)) { vis[to[i]] = 1; }
    }
    ll ans = pre;
    int lst = 1, d;
    for(int i=1; i<=n; i++) {
        if(b[i] > m) { break; }
        if(b[i] > lst+1) {
            ans += (pre + (vis[to[i]]^1)) * (b[i]-lst);
            lst = b[i];
        }
    }
    cout << ans << '\n';
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
