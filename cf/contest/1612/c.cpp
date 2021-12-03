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

ll k, x;

ll cacu(ll x, ll y) {
    if(y > x*2-1) return inf_ll;
    if(x >= y) return y*(y+1)/2;
    else {
        ll bs = x*x;
        y = x*2-1-y;
        if(y > 0) bs -= y*(y+1)/2;
        return bs;
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> k >> x;
        ll l = 1, r = x*2, mid;
        while(l < r) {
            mid = l + (r-l+1)/2;
            // cout << l << ' ' << mid << ' ' << r << endl;
            if(cacu(k, mid) <= x) l = mid;
            else r = mid-1;
        }
        if(cacu(k, l) < x && l != k*2-1) ++l;
        cout << l << endl;
    }
    return 0;
}