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

const int mx = 2e5;
int q, d;
bool vis[200200];
int lowbit(int x) { return x & -x; }

struct bit {
    int n = mx;
    int node[200200];
    void add(int x) {
        while(x <= n) {
            ++node[x];
            x += lowbit(x);
        }
    }
    int query(int x) {
        int ans = 0;
        while(x) {
            ans += node[x];
            x -= lowbit(x);
        }
        return x;
    }
    int qr(int l, int r) {
        return query(r) - query(l-1);
    }
    int qp(int x) {
        return query(x) - query(x-1);
    }
};

void solve(cint T) {
    bit A, L, R;
    cin >> q >> d;
    int ans = 0;
    for(int i=1; i<=q; i++) {
        int t;
        cin >> t;
        int d = L.qr(max(1, t-d+1), t-1) - A.qr(max(1, t-d+1), t-1);

    }
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