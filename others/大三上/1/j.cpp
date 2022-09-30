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

ll n, k;

bool solve(cint T) {
    cin >> n >> k;
    if(n == 1) { cout << 0.5 << '\n'; return true; }
    if(k == 1) { cout << n << '\n'; return true; }
    ld l = 1.5, r = 1e9+1, mid;
    int cnt = 100;
    while(r-l>=1e-7) {
        mid = l+((r-l)/2);
        ld tmp = 1.0;
        for(int i=1; i<=k; i++) {
            tmp *= mid;
            if(tmp >= n) { break; }
            tmp = ll(tmp+0.5);
        }
        if(tmp >= n) { r = mid; }
        else { l = mid; }
        // cout << mid << endl;
    }
    cout << mid << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}