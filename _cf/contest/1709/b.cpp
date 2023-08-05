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

int n, m;
ll a[100100];
ll b[100100];
ll c[100100];

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<n; i++) { b[i] = max(0ll, a[i] - a[i+1]) + b[i-1]; }
    for(int i=n; i>1; i--) { c[i] = max(0ll, a[i] - a[i-1]) + c[i+1]; }
    for(int i=1; i<=m; i++) {
        int s, t;
        cin >> s >> t;
        if(s <= t) {
            cout << b[t-1] - b[s-1] << '\n';
        }
        else {
            cout << c[t+1] - c[s+1] << '\n';
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}