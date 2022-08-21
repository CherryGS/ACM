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

int ans[1000100], mx;
int id[1000100];
int qe[1000100], ct;

const int N = 1000000;
struct trie {
    int node[26][N+100], cnt;
    int val[N+100];
    void clear() { memset(node, 0, sizeof node); memset(val, 0, sizeof val); cnt = 0; }
    /* 字符串下标从 0 开始 */
    void insert(const char *s, int n) {
        int t = 0, v;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
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
    void clear() { memset(fail, 0, sizeof fail); }
    void build() {
        // fail[0] = -1;
        auto tr = p->node;
        queue<int> q;
        for(int i=0; i<26; i++) { if(tr[i][0]) { q.push(tr[i][0]); } }
        while(!q.empty()) {
            int u = q.front();
            qe[++ct] = u;
            q.pop();
            for(int i=0; i<26; i++) {
                if(tr[i][u]) { fail[tr[i][u]] = tr[i][fail[u]]; q.push(tr[i][u]); }
                else { tr[i][u] = tr[i][fail[u]]; }
            }
        }
    }
    void query(char *s, int n) {
        int t = 0, v;
        auto tr = p->node;
        auto val = p->val;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
            t = tr[v][t];
            ++ans[t];
        }
    }
} B;

char s[1000100];
string p[200];

void solve(cint T) {
    int n;
    cin >> n;
    if(n == 0) { return; }
    A.clear();
    B.clear();
    mx = 0;
    memset(ans, 0, sizeof ans);
    memset(id, 0, sizeof id);
    for(int i=1; i<=n; i++) {
        cin >> p[i];
        A.insert(p[i].c_str(), p[i].size());
        id[A.cnt] = i;
    }
    cin >> s;
    B.init(A);
    B.build();
    B.query(s, strlen(s));
    while(ct) { ans[B.fail[qe[ct]]] += ans[qe[ct]]; if(A.val[qe[ct]]) { mx = max(mx, ans[qe[ct]]); } --ct; }
    // for(int i=A.cnt; i>=1; i--) { ans[B.fail[i]] += ans[i]; if(A.val[i]) { mx = max(mx, ans[i]); } }
    cout << mx << endl;
    for(int i=1; i<=A.cnt; i++) { if(id[i] && ans[i] == mx) { cout << p[id[i]] << '\n'; } }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=100;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}