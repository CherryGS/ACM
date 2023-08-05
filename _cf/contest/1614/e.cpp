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

#define ls lson[loc]
#define rs rson[loc]

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll t, lst;
ll pre = -1;

int root = 1;
int node[200200<<6], lson[200200<<6], rson[200200<<6], cnt = 1;

void update(cll l, cll r, int& loc, cll des) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        ++node[loc];
        // cout << l << ' ' << r << ' ' << loc << ' ' << des << ' ' << node[loc] << endl;
        return;
    }
    ll mid = (l+r)>>1;
    if(des <= mid) update(l, mid, ls, des);
    else update(mid+1, r, rs, des);
    node[loc] = 0;
    if(ls) node[loc] += node[ls];
    if(rs) node[loc] += node[rs];
}

ll query(cll l, cll r, int& loc, cll dl, cll dr) {
    if(!loc) return 0;
    if(dl <= l && dr >= r) {
        // cout << l << ' ' << r << ' ' << node[loc] << ' ' << dl << endl;
        return node[loc];
    }
    ll mid = (l+r)>>1;
    int ans = 0;
    if(dl <= mid) ans += query(l, mid, ls, dl, dr);
    if(dr >= mid+1) ans += query(mid+1, r, rs, dl, dr);
    // cout << l << ' ' << r << ' ' << loc << ' ' << dl << ' ' << dr << ' ' << ans << endl;
    return ans; 
}

void sol(ll x) {
    if(pre == -1) pre = x;
    else if(pre < x) pre = x+1;
    else if(pre > x) pre = x-1;
    // cout << "pre: " << pre << endl;
    update(0, 1e9+1, root, pre);
    // cout << query(1, 1e9+1, root, 50, 1e9+1) << " - - - - " << endl;
}

void solve(cll T) {
    cin >> t;
    cin >> k;
    sol(t);
    // return;
    ll tmp;
    for(int i=1; i<=k; i++) {
        cin >> tmp;
        tmp = (lst + tmp) % int(1e9+1);
        // cout << "tmp: " << tmp << endl;
        // cout << query(0, 1e9, root, 0, tmp) << " --- " << query(0, 1e9, root, tmp, 1e9) << endl;
        lst = tmp - query(0, 1e9+1, root, 0, tmp) + query(0, 1e9+1, root, tmp, 1e9+1);
        cout << lst << endl;
    }
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}