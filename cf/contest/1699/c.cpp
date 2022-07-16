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
int a[100100];

bool cmp(cint x, cint y) {
    return a[x] < a[y];
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    vector<int> id;
    for(int i=1; i<=n; i++) { id.push_back(i); }
    sort(id.begin(), id.end(), cmp);
    int l = n+1, r = 0, t = 0;
    ll ans = 1;
    for(auto &k: id) {
        // cout << k << ' ' << a[k] << endl;
        if(k > l && k < r) {
            ans = ans * (r-l-t+1) % mod1;
        }
        else {
            r = max(k, r);
            l = min(k, l);
        }
        ++t;
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