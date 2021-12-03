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

const int mx_n = 10000000;
int n;
bool vis[mx_n+1000];
int prim[mx_n+1000], cnt;

void liner_sieve(cint x) {
    int rt = 0;
    vis[0] = 1;
    vis[1] = 1;
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

int ans[10000100];

void init() {
    liner_sieve(mx_n);
    for(int i=3; i<=mx_n; i++)
        ans[i] = ans[i-1] + (!vis[i] && !vis[i-2]); 
}

void solve(cint T) {
    int l, r;
    cin >> l >> r;
    int anss = ans[r] - ans[l-1] - (!vis[l]&&!vis[l-2]);
    if(r >= l+1) anss -= (!vis[l+1]&&!vis[l-1]);
    cout << anss << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}