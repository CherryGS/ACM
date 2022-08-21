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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int sig = 10;
const int N = 6000;
struct trie {
    int node[sig][N+100], cnt;
    int val[N+100];
    /* 字符串下标从 0 开始 */
    void insert(char *s, int n) {
        int t = 0, v;
        for(int i=0; i<n; i++) {
            v = s[i] - '0';
            if(node[v][t] == 0) { node[v][t] = ++cnt; }
            t = node[v][t];
        }
        ++val[t];
    }
} A;

struct AC {
    trie *p;
    int fail[N+100];
    void init(trie &a) { p = &a; }
    void build() {
        // fail[0] = -1;
        auto tr = p->node;
        queue<int> q;
        for(int i=0; i<sig; i++) { if(tr[i][0]) { q.push(tr[i][0]); } }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i=0; i<sig; i++) {
                if(tr[i][u]) { fail[tr[i][u]] = tr[i][fail[u]]; q.push(tr[i][u]); }
                else { tr[i][u] = tr[i][fail[u]]; }
            }
            p->val[u] += p->val[fail[u]];
        }
    }
} B;

void mo(int &x) {
    while(x < 0) { x += mod; }
    while(x > mod) { x -= mod; }
}

int m;
char s[2002];
char t[2002];
int dp[1501][1202][2];

void solve(cint T) {
    cin >> t;
    cin >> m;
    int n = strlen(t);
    for(int i=1; i<=m; i++) { cin >> s; A.insert(s, strlen(s)); }
    B.init(A);
    B.build();
    auto tr = A.node;
    auto val = A.val;
    int u, v;
    for(int j=1; j<=n; j++) {
        u = t[j-1]-'0';
        for(int l=1; l<sig; l++) {
            v = tr[l][0];
            if(l > u && j == 1) { break; }
            if(l == u && j == 1) { dp[v][j][1] += 1; }
            else { dp[v][j][0] += 1; }
            if(val[v]) { dp[v][j][0] = dp[v][j][1] = 0; }
        }
        for(int i=0; i<=A.cnt; i++) {
            for(int l=0; l<sig; l++) {
                v = tr[l][i];
                if(l > u) {
                    dp[v][j][0] += dp[i][j-1][0];
                }
                else if(l < u) {
                    dp[v][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
                }
                else {
                    dp[v][j][0] += dp[i][j-1][0];
                    dp[v][j][1] += dp[i][j-1][1];
                }
                if(val[v]) { dp[v][j][0] = dp[v][j][1] = 0; }
                else { dp[v][j][0] %= mod; dp[v][j][1] %= mod; }
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<=A.cnt; i++) { ans += dp[i][n][0] + dp[i][n][1]; ans %= mod;}
    cout << ans << '\n';
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