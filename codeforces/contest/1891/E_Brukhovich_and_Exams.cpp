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
#define ifor(s, e, t) for(int i=s;i<=e;i+=t)
#define jfor(s, e, t) for(int j=s;j<=e;j+=t)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x%y); }

int n, k;
int a[100100];

void solve(cint T) {
    cin >> n >> k;
    ifor(1, n, 1) { cin >> a[i]; }
    ifor(2, n-1, 1) {
        if(k <= 0) { break; }
        if(a[i] == 1) {
            --k;
            a[i] = 0;
        }
    }
    ifor(2, n-1, 1) {
        if(k <= 0) { break; }
        if(gcd(a[i], a[i-1]) == 1 && gcd(a[i], a[i+1]) == 1) {
            --k;
            a[i] = 0;
        }
    }
    ifor(2, n, 1) {
        if(k <= 0) { break; }
        if(gcd(a[i], a[i-1]) == 1) {
            --k;
            if(a[i] == 1) { a[i] = 0; }
            else { a[i-1] = 0; }
        }
    }
    ifor(1, n, 1) {
        if(k <= 0) { break; }
        if(a[i] == 1) {
            --k;
            a[i] = 0;
        }
    }
    // cout << k << endl;
    // ifor(1, n, 1) { cout << a[i] << ' '; }
    // cout << endl;
    int ans = 0;
    ifor(2, n, 1) {
        if(gcd(a[i], a[i-1]) == 1) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
