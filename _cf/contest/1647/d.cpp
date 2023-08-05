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

ll x, d;

bool is_prime(ll x) {
    if(x == 1) return false;
    for(int i=2; i<=sqrt(x); i++) {
        if(!(x%i)) { return false; }
    }
    return true;
}

bool check(ll x, ll y) {
    for(int i=2; i<=sqrt(x); i++) {
        if(!(x%i)) {
            // cout << x << ' ' << i << ' ' << y << ' ' << x/i << ' ' << d << endl;
            // cout << ((i*y)%d) << ' ' << (((x/i)*y)%d) << endl;
            if(((i*y)%d) || (((x/i)*y)%d)) { return true; }
        }
    }
    return false;
}

void solve(cint T) {
    cin >> x >> d;
    int cnt = 0;
    ll tx = x;
    for(; !(tx%d); tx/=d) { ++cnt; }
    if(cnt == 1) { cout << "NO" << '\n'; return; }
    if(!is_prime(tx) && tx != 1) { cout << "YES" << '\n'; return; }
    if(cnt == 2) { cout << "NO" << '\n'; return; }
    if(is_prime(d)) { cout << "NO" << '\n'; return; }
    // cout << " --- " << d << ' ' << tx << ' ' << cnt << endl;
    if(check(d, tx)) { cout << "YES" << '\n'; return; }
    if(cnt == 3) { cout << "NO" << '\n'; return; }
    cout << "YES" << '\n';
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