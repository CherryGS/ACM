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
ll r[11];

int cacu(ll x) {
    ll c = (x+1) % n;
    ll t = x % n;
    for(int i=0; ; i++) {
        if(t <= c) {
            ll w = c-t;
            if(w < r[i]) { return i; }
        }
        else if(t > c) {
            ll w = c+n - t;
            if(w < r[i]) { return i; }
        }
        t = t * 10;
        t %= n;
    }
}

void solve(cint T) {
    cin >> n;
    r[0] = 1;
    ll ans = 0;
    for(int i=1; i<10; i++) { r[i] = r[i-1] * 10; }
    for(int i=0; i<n; i++) { ans += cacu(i); }
    cout << ans << '\n';
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