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
char s[200200];
char t[200200];

int cacu(int l1, int r1, int l2, int r2) {
    return abs(r2 - r1) + abs(l2 - l1);
}

void solve(cint T) {
    cin >> n;
    cin >> s;
    cin >> t;
    if(s[0] != t[0] || s[n-1] != t[n-1]) {
        cout << -1 << '\n';
        return;
    }
    vector<pii> q1, q2;
    int l = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '1' && (i == 0 || s[i-1] == '0')) { l = i; }
        if(s[i] == '1' && (i == n-1 || s[i+1] == '0')) {
            q1.push_back({l, i});
        }
    }
    l = 0;
    for(int i=0; i<n; i++) {
        if(t[i] == '1' && (i == 0 || t[i-1] == '0')) { l = i; }
        if(t[i] == '1' && (i == n-1 || t[i+1] == '0')) {
            q2.push_back({l, i});
        }
    }
    if(q1.size() != q2.size()) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for(int i=0; i<q1.size(); i++) {
        ans += cacu(q1[i].first, q1[i].second, q2[i].first, q2[i].second);
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