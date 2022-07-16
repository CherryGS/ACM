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

int n, c, q;
char s[200200];
vector<pair<ll,ll>> qe;

ll cacu(ll k) {
    ll sum = n;
    for(int j=0; j<=c; j++) {
        // cout << sum << ' ' << c << ' ' << j << endl;
        if(sum >= k) {
            // cout << sum << ' ' << k << ' ' << qe[j-1].second - (sum - k) << endl;
            return qe[j-1].second - (sum - k);
        }
        else { sum += qe[j].second - qe[j].first + 1; }
    }
    // cout << " --- " << endl;
    //creamii re ea reamiire
}

void solve(cint T) {
    cin >> n >> c >> q;
    cin >> s;
    qe.clear();
    for(int i=1; i<=c; i++) {
        ll l, r;
        cin >> l >> r;
        qe.push_back({l, r});
    }
    for(int i=1; i<=q; i++) {
        ll k;
        cin >> k;
        while(k > n) { k = cacu(k);  }
        // cout << s[k-1] << ' ' << k << '\n';
        cout << s[k-1] << '\n';
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