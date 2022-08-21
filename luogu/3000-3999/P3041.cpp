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

const int sig = 3;
const int N = 300;
struct trie {
    int node[sig][N+100], cnt;
    int val[N+100];
    /* 字符串下标从 0 开始 */
    void insert(char *s, int n) {
        int t = 0, v;
        for(int i=0; i<n; i++) {
            v = s[i] - 'A';
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

int n, k;
char s[1001];
int dp[303][1001];

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> s; A.insert(s, strlen(s)); }
    B.init(A);
    B.build();
    auto tr = A.node;
    auto val = A.val;
    dp[0][0] = 1;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<=A.cnt; j++) {
            if(dp[j][i-1] == 0) { continue; }
            for(int l=0; l<3; l++) {
                if(tr[l][j]) {
                    dp[tr[l][j]][i] = max(dp[tr[l][j]][i], dp[j][i-1]+val[tr[l][j]]);
                }
            }
        }
    }
    int ans = 0;
    for(int j=1; j<=A.cnt; j++) { ans = max(ans, dp[j][k]); }
    cout << ans-1 << '\n';
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