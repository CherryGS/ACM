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

int n, m;

struct node {
    ll x, w;
    int id;
    void init(cint i) {
        id = i;
        cin >> x >> w;
    }
} s[200200];

bool cmp1(const node&a, const node&b) {
    return a.x < b.x;
}

bool cmp2(const node&a, const node&b) {
    return a.w < b.w;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=m; i++) { s[i].init(i); }
    sort(s+1, s+1+m, cmp2);
    vector<node> q;
    ll sum = 0;
    for(int i=1; i<=2*n; i++) { q.push_back(s[i]); sum += s[i].w; }
    sort(q.begin(), q.end(), cmp1);
    cout << sum << '\n';
    for(int i=0; i<n; i++) {
        cout << q[i].id << ' ' << q[n*2-i-1].id << '\n';
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}