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

vector<int> to[100100]; // 邻接表
int son[100100]; // 子树大小
int bson[100100]; // 重儿子

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

void clear() { }

/* add current point's contribution  */
void ins(int loc) { }

/* caculate current point's answer  */
void cacu_ans(int loc) { }

/* add light subtree's contribution to main process */
void update(int loc, int fa) {
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
            clear();
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
    cacu_ans(loc);
}

void solve(cint T) {
    init_tree(1, 1);
    sol(1, 1);
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