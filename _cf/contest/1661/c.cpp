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
int h[300300];

ll sol(int mx) {
    ll one = 0, two = 0;
    for(int i=1; i<=n; i++) {
        two += (mx - h[i]) / 2;
        if((mx - h[i]) & 1) { ++one; }
    }
    if(two > one) {
        ll r = (two - one) / 3;
        ll dr = (two - one) % 3;
        one += r*2;
        two -= r;
        if(dr == 2) {
            two --;
            one += 2;
        }
    }
    one = max(one, two);
    two = max(two, one - 1);
    return one + two;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> h[i]; }
    int mx = 0;
    for(int i=1; i<=n; i++) { mx = max(mx, h[i]); }
    cout << min(sol(mx), sol(mx+1)) << '\n';
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