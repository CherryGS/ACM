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

struct KMP {
    int pi[1000100]; // 这里大小开到 n+m+1 就可以
    int mx_n;
    void init(char *s, int n) {
        fill(pi, pi+n+1, 0);
        mx_n = n;
        for(int i=1; i<n; i++) {
            int r = pi[i-1];
            while(r && s[r] != s[i]) { r = pi[r-1]; }
            if(s[r] == s[i]) { pi[i] = r + 1; }
        }
    }
} A;

char s[1000100];
vector<int> to[1000100];
int st[1001000], cnt;
int ans = 1;

void dfs(int r, int u, int fa) {
    while(r < cnt && st[r]*2 <= u) { ++r; }
    st[cnt++] = u;
    // cout << u << ' ' << fa << ' ' << to[u].size() << ' ' << r << ' ' << cnt << ' ' << st[r] << endl;
    ans = 1ll * ans * max(1, r) % mod1;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(r, v, u);
        }
    }
    --cnt;
}

void solve(cint T) {
    cin >> s;
    ans = 1;
    int n = strlen(s);
    for(int i=0; i<=n; i++) { to[i].clear(); }
    A.init(s, n);
    // for(int i=0; i<n; i++) { cout << A.pi[i] << ' '; }
    // cout << endl;
    for(int i=0; i<n; i++) {
        to[A.pi[i]].push_back(i+1);
    }
    dfs(0, 0, 0);
    cout << ans << '\n';
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