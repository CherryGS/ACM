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
int a[200200], b[200200];
int c[200200];
int bcj[200200];

int fd(int x) {
    return bcj[x] == x ? x : bcj[x] = fd(bcj[x]);
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i=1; i<=n; i++) { cin >> c[i]; bcj[i] = i; }
    bool ok = false;
    for(int i=1; i<=m; i++) {
        if(c[a[i]] != c[b[i]]) {
            int u = fd(a[i]), v = fd(b[i]);
            if(u != v) { bcj[u] = v; }
        }
    }
    for(int i=1; i<=m; i++) {
        if(c[a[i]] == c[b[i]]) {
            int u = fd(a[i]), v = fd(b[i]);
            if(u == v) { ok = true; }
        }
    }
    if(ok) { cout << "Yes\n"; }
    else { cout << "No\n"; }
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
