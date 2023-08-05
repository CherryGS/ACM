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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n;

ll cacu(ll x) {
    if(x == 0) { return 1;}
    if(x & 1) {
        return (x*4+1*4) * ((x-1)/2+1) / 2;
    }
    return (x*4+2*4) * (x/2) / 2 + 1;
}

bool solve(cint T) {
    cin >> n;
    ll l = 0, r = sqrt(n), mid;
    // cout << l << ' ' << r << endl;
    while(l < r) {
        mid = l + (r-l) / 2;
        if(cacu(mid) < n) { l = mid + 1; }
        else { r = mid; }
    }
    cout << r << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}