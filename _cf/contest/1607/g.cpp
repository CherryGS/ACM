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

int t, n;
ll m;
ll a[200200], b[200200];
ll r1[200200], r2[200200];

void print() {
    ll ans = 0;
    for(int i=1; i<=n; i++) ans += r1[i] - r2[i];
    cout << abs(ans) << endl;
    for(int i=1; i<=n; i++) {
        cout << a[i] - r1[i] << ' ' << b[i] - r2[i] << endl;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
        ll s1 = 0, s2 = 0;
        for(int i=1; i<=n; i++) {
            r1[i] = a[i] - m;
            r2[i] = b[i];
            if(r1[i] < 0) r2[i] += r1[i], r1[i] = 0;
        }
        for(int i=1; i<=n; i++) { s1 += r1[i]; s2 += r2[i]; }
        if(s1 >= s2) print();
        else {
            ll p = (s2-s1)/2;
            for(int i=1; i<=n; i++) {
                if(p == 0) break;
                ll x = min(a[i]-r1[i], r2[i]);
                x = min(x, p);
                p -= x;
                r1[i] += x;
                r2[i] -= x;
            }
            print();
        }
    }
    return 0;
}