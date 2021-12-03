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
ll s;
ll a[200200];

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> s;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) a[i] += a[i-1];
        int r = 1, ans = -1, lst = -inf_int;
        int al, ar;
        for(int i=1; i<=n; i++) {
            if(r < i) { r = i; lst = -inf_int; }
            if(-a[i-1] >= lst && a[i]-a[i-1]+s >= 0) {
                while(r <= n && a[r]-a[i-1]+s >= 0) ++r;
                if(r-i+1 > ans) {
                    ans = r-i+1;
                    al = i;
                    ar = r-1;
                }
                lst = -a[i-1];
            }
        }
        if(ans <= 0) cout << -1 << endl;
        else cout << al << ' ' << ar << endl;
    }
    return 0;
}