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
    for(int i=1; i<=n; i++) cin >> a[i];
    if(n == 2) { cout << 0 << endl; return; }
    bool flag = false;
    bool f1 = false, f2 = false;
    for(int i=2; i<n; i++) if(a[i] > 0) {
        if(!(a[i] & 1)) flag = true;
        else {
            if(a[i] > 1 && !f1) f1 = true;
            else f2 = true;
        }
    }
    flag |= (f1 && f2);
    if(!flag) { cout << -1 << endl; return; }
    ll ans = 0, num = 0;
    for(int i=2; i<n; i++) {
        ans += a[i];
        num += a[i] & 1;
    }
    cout << ans / 2 + (num+1) / 2 << endl;
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