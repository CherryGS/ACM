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
typedef __int128_t i128;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
string d;
ll x;
ll s1, s2;

i128 cacu_sum(ll l, ll r) {
    i128 sum = 0;
    i128 t1 = r;
    t1 = t1 * s1;
    t1 = (t1+1) * t1 / 2;
    i128 t2 = l-1;
    t2 = t2 * s1;
    t2 = (t2+1) * t2 / 2;
    return t1 - t2;
}

void solve(cint T) {
    cin >> n >> m;
    cin >> d;
    cin >> x;
    s1 = (1ll << n); s2 = (1ll << m);
    i128 ans = 0;
    if(d[0] == 'l' || d[0] == 'r') {
        if(d[0] == 'r') { x = s1 * s2 - x + 1; }
        ll id = (x + s2 - 1) / m;
        id = id + (x - (id-1) * m - 1) * s1;
        ll num = id / s1;
        ll idv = id - num * s1;
        ll key = num + 1;
        for(int i=n+m, st=0; i>=0; i--) {
            if(key & (1ll<<i)) { st = 1; }
            if(st) {
                if(key & (1ll<<i)) {
                    ans += cacu_sum((1ll<<i), (1ll<<(i+1))-1);
                }
            }
        }

    }
    else {
        if(d[0] == 'b') { x = (1ll<<(m+n)) - x + 1; }
    }
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