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
int node[500500];
int ans[300300];

int lb(int x) { return x & -x; }

void add(int x) {
    while(x <= 50000) {
        ++node[x];
        x += lb(x);
    }
}

int query(int x) {
    int ans = 0;
    while(x) {
        ans += node[x];
        x -= lb(x);
    }
    return ans;
}

struct node {
    int a, b;
    void init() {
        cin >> a >> b;
        ++a;
        ++b;
    }
    bool operator < (const node&s) const {
        return a == s.a ? b < s.b : a < s.a;
    }
} s[300300];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) s[i].init();
    sort(s+1, s+1+n);
    for(int i=1; i<=n; i++) {
        int r = query(s[i].b) + 1;
        ++ ans[r];
        add(s[i].b);
    }
    for(int i=1; i<=n; i++) cout << ans[i] << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}