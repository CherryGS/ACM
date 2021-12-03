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

int n, e;
int a[200200];
const int mx_n = 1000000;
bool vis[mx_n+1000];
int prim[mx_n+1000], cnt;

void liner_sieve(cint x) {
    int rt = 0;
    vis[1] = vis[0] = 1;
    for(int i=2; i<=x; i++) {
        if(!vis[i]) {
            prim[++cnt] = i;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll*prim[j]*i > x) break;
            vis[prim[j]*i] = 1;
            if(!(i%prim[j])) break;
        }
    }
}

ll val[200200];

void solve(cint T) {
    cin >> n >> e;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll ans = 0;
    for(int i=1; i<=e; i++) {
        ll r = 0;
        int w = 0;
        for(int j=i; j<=n; j+=e) {
            if(a[j] != 1) { val[j] = r; r = 0; }
            else ++r;
            w = j;
        }
        r = 0;
        for(int j=w; j>=i; j-=e) {
            if(a[j] != 1) { if(!vis[a[j]]) ans += (r+1)*(val[j]+1)-1; r = 0; }
            else ++r;
        }
    }
    cout << ans << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    liner_sieve(1000000);
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}