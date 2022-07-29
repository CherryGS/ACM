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

struct node {
    ll d, s;
    void init() {
        cin >> d >> s;
        s = s - d;
    }
} a[100100];

ll n, s;
ll sum[100100];

void solve(cint T) {
    cin >> n >> s;
    vector<node> q1, q2;
    for(int i=1; i<=n; i++) { a[i].init(); if(a[i].d >= 0) { q1.push_back(a[i]); } else { q2.push_back(a[i]); } }
    sort(q1.begin(), q1.end(), [](const node&a, const node&b) { return a.s == b.s ? a.d < b.d : a.s < b.s; } );
    sort(q2.begin(), q2.end(), [](const node&a, const node&b) { return a.d == b.d ? a.s > b.s : a.d > b.d; } );
    int l = 0, r = q1.size()-1;
    int ans = 0;
    ll ss = s, t = s;
    for(int i=0; i<=r; i++) { sum[i] = a[i].d; if(i) { sum[i] += sum[i-1]; } }
    while(l <= r) {
        while(l <= r && sum[r]+t>=a[r].s+a[r].d)
         { --r; ++ans; }
        while(l <= r && s >= a[l].s) { s += a[l].d; ++ans; ++l; }
        if(l <= r) { t += a[r].d; s += a[r].d; --r; }
    }
    s = ss + sum[r];
    for(auto &k: q2) {
        if(k.s <= s) { ++ans; s += k.d; }
    }
    cout << ans << '\n';
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