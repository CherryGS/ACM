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

#define ls (u<<1)
#define rs ((u<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;


int n;
const int mx_n=100000;
vector<int> to[mx_n+100];
int son[10010]; // 经过处理后的每个点的儿子个数
bool vis[10010]; // 该点是否在分治时作为子树的根

void add(int f, int t) {
    to[f].push_back(t);
}

/* 获取通过 vis 分隔的当前子树的大小 */
int get_size(int u, int fa) {
    int sum = 1;
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(v != fa && !vis[v]) {
            sum += get_size(v, u);
        }
    }
    return sum;
}

/* 获取通过 vis 分隔的当前子树的重心 */
int get_root(int u, int fa, int n) {
    int pre = 0, weight = 0, id = 0;
    son[u] = 1;
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(v != fa && !vis[v]) {
            id = get_root(v, u, n);
            if(id != 0) { return id; }
            son[u] += son[v];
            weight = max(weight, son[v]);
        }
    }
    pre = max(pre, n - son[u]);
    // 树的重心可能有两个，此处任取了一个
    if(pre <= n/2) { return u; }
    return 0;
}

void clear() { }

void cacu(int u, int fa) { }

void update(int u, int fa) { }

void sol(int u) {
    vis[u] = 1;
    clear();
    // 计算当前节点为根的答案
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(!vis[v]) {
            cacu(v, u);
            update(v, u);
        }
    }
    // 向子树递归
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(!vis[v]) {
            sol(get_root(v, u, get_size(v, u)));
        }
    }
}

void solve(int T) {
    sol(get_root(1, 1, n));
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