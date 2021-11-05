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

int t;
int n;
ll a[100100];

ll gcd(cll x, cll y) {
    return y == 0 ? x : gcd(y, x%y);
}

ll cacu(ll x, ll y) {
    if(y == 0) return 0;
    if(!(x%y)) return 0;
    return y - x%y;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    int TT = t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        for(int i=2; i<=n; i++) a[i] -= a[1];
        ll ans = 0;
        for(int i=2; i<=n; i++) ans = gcd(a[i], ans);
        cout << "Case " << TT-t << ": ";
        if(n == 1 && a[1] != 1) cout << 0 << endl;
        else if(ans == 1) { cout << -1 << endl; }
        else {
            ll pre = ans;
            ll anss = inf_int;
            for(int i=2; i<=sqrt(pre); i++) {
                if(!(ans % i)) {
                    while(!(ans % i)) ans /= i;
                    anss = min(anss, cacu(a[1], i));
                }
            }
            if(ans != 1) anss = min(anss, cacu(a[1], ans));
            if(ans == 0 && a[1] == 1) anss = 1;
            cout << anss << endl;
        }
    }
    return 0;
}
