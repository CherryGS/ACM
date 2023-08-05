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
int a[200200];
int val[200];
ll to[200200];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs % mod1;
        bs = bs * bs % mod1;
        x >>= 1; 
    }
    return ans;
}

void init() {
    to[0] = 1;
    for(int i=1; i<=200000; i++)
        to[i] = to[i-1] * 2 % mod1;
    
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        ll sum = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) {
            if(a[i]&1) ++ sum;
            else {
                int r = 0;
                while(!(a[i]%(1<<r))) ++r;
                ++val[r-1];
            }
        }
        ll ans = (to[n] - to[n-sum] + mod1) % mod1;
        // cout << ans << endl;
        int r = 0;
        for(int i=1; i<=33; i++) {
            if(!val[i]) continue;
            r += val[i];
            // cout << r << ' ' << i << endl;
            ans += (to[val[i]-1]-1) * to[n-sum-r];
            ans %= mod1;
        }
        cout << ans << endl;
    }
    return 0;
}