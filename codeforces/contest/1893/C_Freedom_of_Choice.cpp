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
typedef __int128_t i8;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int m;
int n[100100];
ll l[100100], r[100100];
i8 sum[100100];
vector<ll> a[100100], c[100100];
map<ll, i8> mn, mx;

void solve(cint T) {
    cin >> m;
    ll tmp;
    i8 sl = 0, sr = 0;
    for(int i=1; i<=m; i++) {
        a[i].clear(); c[i].clear(); sum[i] = 0;
        cin >> n[i] >> l[i] >> r[i];
        sl += l[i]; sr += r[i];
        for(int j=1; j<=n[i]; j++) {
            cin >> tmp; a[i].push_back(tmp);
        }
        for(int j=1; j<=n[i]; j++) {
            cin >> tmp; c[i].push_back(tmp);
            sum[i] += tmp;
        }
    }
    mn.clear(); mx.clear();
    for(int i=1; i<=m; i++) {
        for(int j=0; j<n[i]; j++) {
            mn[a[i][j]] += max((i8)0, (i8)l[i] - (sum[i]-c[i][j]));
        }
        for(int j=0; j<n[i]; j++) {
            mx[a[i][j]] += max((i8)0, (i8)r[i] - (sum[i]-c[i][j]));
        }
    }
    i8 ans = inf_ll;
    ans *= inf_ll;
    if(sr - sl > 100000) { ans = 0; }
    else {
        for(auto i=sl; i<=sr; i++) {
            if(mn.find(i) == mn.end()) {
                ans = 0;
                break;
            }
        }
    }
    for(auto &it: mn) {
        ll k = it.first;
        if(k >= sl && k <= sr) {
            i8 num = mx[k] - mn[k];
            ans = min(ans, mx[k]-min(sr-k, num));
        }
    }
    cout << (ll)ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
