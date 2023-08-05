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

int n;
int c[100100];
int num[100100];
ll ans[100100];
ll mx, sum;

vector<int> to[100100]; // 邻接表
int son[100100]; // 子树大小
int bson[100100]; // 重儿子
int q[100100], cnt;

/* 初始化轻重儿子 */
void init_tree(int loc, int fa) {
    son[loc] = 1;
    for(int v: to[loc]) {
        if(v != fa) {
            init_tree(v, loc);
            son[loc] += son[v];
            if(son[v] > son[bson[loc]]) { bson[loc] = v; }
        }
    }
}

void clear() {
    sum = mx = 0;
    while(cnt) { --num[q[cnt]]; --cnt; }
}

void ins(int loc) {
    q[++cnt] = c[loc];
    ++num[c[loc]];
    if(num[c[loc]] > mx) { mx = num[c[loc]]; sum = c[loc]; }
    else if(num[c[loc]] == mx) { sum += c[loc]; }
}

/* add light subtree's contribution to main process */
void update(cint loc, cint fa) {
    ins(loc);
    for(int v: to[loc]) {
        if(v != fa) { update(v, loc); }
    }
}

/* dsu on tree main process */
void sol(int loc, int fa) {
    // light son
    for(int &v: to[loc]) {
        if(v != fa && v != bson[loc]) {
            sol(v, loc);
            clear(); // 清空函数
        }
    }
    // big son
    if(bson[loc]) { sol(bson[loc], loc); }
    // add light subtree's contribution
    for(int &v: to[loc]) {
        if(v != fa && v != bson[loc]) {
            update(v, loc);
        }
    }
    ins(loc);
    ans[loc] = sum;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    init_tree(1, 1);
    sol(1, 1);
    for(int i=1; i<=n; i++) { cout << ans[i] << ' '; }
    cout << '\n';
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