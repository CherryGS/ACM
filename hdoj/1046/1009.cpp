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

ll n, k;
ll l[100100], r[100100];

bool cmp(cint x, cint y) {
    return l[x] == l[y] ? r[x] < r[y] : l[x] < l[y];
}

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> l[i] >> r[i]; }
    vector<int> id;
    for(int i=1; i<=n; i++) { id.push_back(i); }
    sort(id.begin(), id.end(), cmp);
    // for(int &k: id) { cout << k << ' '; }
    // cout << endl;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    int ans = 0;
    for(int &t: id) {
        while(!q.empty() && q.top() < l[t]) {
            // cout << k << ' ' << q.size() << endl;
            ++ans;
            for(int i=1; i<=k; i++) { q.pop(); if(q.empty()) { break; } }
        }
        q.push(r[t]);
    }
    // cout << ans << ' ' << q.size() << endl;
    ans += (ll(q.size())+k-1) / k;
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        solve(_T); 
    }
    return 0;
}