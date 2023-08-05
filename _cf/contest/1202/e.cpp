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

int sum[2][200200];

const int sig = 26;
const int N = 200000;
struct trie {
    int node[sig][N+100], cnt;
    int val[N+100];
    /* 字符串下标从 0 开始 */
    void insert(char *s, int n) {
        int t = 0, v;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
            if(node[v][t] == 0) { node[v][t] = ++cnt; }
            t = node[v][t];
        }
        ++val[t];
    }
} A, C;

struct AC {
    trie *p;
    int fail[N+100];
    void init(trie &a) { p = &a; }
    void clear() { memset(fail, 0, sizeof fail); }
    void build() {
        // fail[0] = -1;
        auto tr = p->node;
        queue<int> q;
        for(int i=0; i<sig; i++) { if(tr[i][0]) { q.push(tr[i][0]); } }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0; i<sig; i++) {
                if(tr[i][u]) { fail[tr[i][u]] = tr[i][fail[u]]; q.push(tr[i][u]); }
                else { tr[i][u] = tr[i][fail[u]]; }
            }
            p->val[u] += p->val[fail[u]];
        }
    }
    void query(char *s, int n, bool st) {
        int ans = 0, t = 0, v;
        auto tr = p->node;
        auto val = p->val;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
            t = tr[v][t];
            if(st == 0) { sum[0][i+1] = val[t]; }
            else { sum[1][n-i] = val[t]; }
        }
    }
} B;

int n;
char t[200200];
char s[200200];

void solve(cint T) {
    cin >> t;
    cin >> n;
    for(int i=1; i<=n; i++) { 
        cin >> s; 
        int l = strlen(s);
        A.insert(s, l); 
        reverse(s, s+l);
        C.insert(s, l); 
    }
    int le = strlen(t);
    B.init(A);
    B.build();
    B.query(t, le, 0);
    B.clear();
    B.init(C);
    B.build();
    reverse(t, t+le);
    B.query(t, le, 1);
    ll ans = 0;
    // for(int i=1; i<=le; i++) { cout << sum[0][i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=le; i++) { cout << sum[1][i] << ' '; }
    // cout << endl;
    for(int i=1; i<le; i++) { ans = ans + 1ll * sum[0][i] * sum[1][i+1]; }
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