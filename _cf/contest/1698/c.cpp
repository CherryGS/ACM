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
ll a[200100];

bool check() {
    ll x = a[1] + a[2] + a[3];
    if(x == a[1]) { return false; }
    if(x == a[2]) { return false; }
    if(x == a[3]) { return false; }
    return true;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int s1 = 0;
    ll s2 = 0;
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++) {
        if(a[i] == 0) { ++s1; }
        else { s2 += a[i]; }
    }
    if(s1 >= 1) {
        if(n - s1 >= 3) { cout << "NO" << '\n'; }
        else {
            if(n-s1 == 0 || n-s1 == 1 || s2 == 0) { cout << "YES" << '\n'; }
            else { cout << "NO" << '\n'; }
        }
    }
    else if(n == 4 && a[1] == -a[4] && a[2] == -a[3]) { cout << "YES" << '\n'; }
    else if(n != 3 || check()) { cout << "NO" << '\n'; }
    else { cout << "YES" << '\n'; }
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