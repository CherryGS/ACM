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

const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[200200];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod2;}
        bs = bs * bs % mod2;
        x >>= 1;
    }
    return ans;
}

bool check() {
    for(int i=2; i<=n; i++)
        if(a[i] != a[i-1]) return false;
    return true;
}

ll cacu(int x, int step) {
    while(x+step > 0 && x+step <= n && a[x] == a[x+step]) {
        x += step;
    }
    return x;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    if(check()) cout << (ksm(2, n) - 1 + mod2) % mod2 << endl;
    else {
        int num = 0;
        int lst = 0;
        bool trend = false;
        ll ans = 1;
        for(int i=1; i<=n; i++) {
            if(i == n) {
                int l = cacu(i, -1);
                int r = cacu(lst, 1);
                ans = ans * (ksm(2, i-l+1) - 1 + mod2) % mod2;
                if(l > r) {
                    ans = ans * (ksm(2, r-lst+1) - 1 + mod2) % mod2;
                    ans = ans * ksm(2, l-r-1) % mod2;
                }
                break;
            }
            if(a[i] > a[i+1] && trend == true) {
                trend = false;
                int l = cacu(i, -1);
                int r = cacu(lst, 1);
                ans = ans * (ksm(2, i-l+1) - 1 + mod2) % mod2;
                if(l > r) {
                    ans = ans * (ksm(2, r-lst+1) - 1 + mod2) % mod2;
                    ans = ans * ksm(2, l-r-1) % mod2;
                }
                lst = i;
            }
            else if(a[i] < a[i+1] && trend == false) {
                trend = true;
                int l = cacu(i, -1);
                int r = cacu(lst, 1);
                ans = ans * (ksm(2, i-l+1) - 1 + mod2) % mod2;
                if(l > r) {
                    ans = ans * (ksm(2, r-lst+1) - 1 + mod2) % mod2;
                    ans = ans * ksm(2, l-r-1) % mod2;
                }
                lst = i;
            }
            // cout << i << ' ' << num << endl;
            if(lst == 0) lst = 1;
        }
        // cout << ksm(2, num) << endl;
        cout << ans << endl;
    }
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