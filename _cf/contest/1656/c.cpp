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
int a[100100];


void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    sort(a+1, a+1+n);
    bool zero = false, one = false, two = false;
    for(int i=1; i<=n; i++) {
        if(a[i] == 0) { zero = true; }
        if(a[i] == 1) { one = true; }
        if(a[i] == 2) { two = true; }
    }
    bool t = false;
    for(int i=1; i<n; i++) {
        if(a[i+1] - a[i] == 1) { t = true; }
    }
    if(zero && one) { cout << "NO" << '\n'; return; }
    if(one && two) { cout << "NO" << '\n'; return; }
    if(one && t) { cout << "NO" << '\n'; return;}
    cout << "YES" << '\n';
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