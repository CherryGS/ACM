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

int n, m, q;
int a[200200];
int mx[26][200200];

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=m; i++) { cin >> a[i]; mx[0][i] = a[i]; }
    for(int j=1; j<26; j++) {
        for(int i=1; i<=m; i++) {
            mx[j][i] = max(mx[j-1][i], mx[j-1][min(m, i+(1<<(j-1)))]);
        }
    }
    // cout << mx[0][4] << endl;
    cin >> q;
    for(int i=1; i<=q; i++) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        if(abs(ys-yf) % k != 0 || abs(xs-xf) % k != 0) { cout << "NO" << '\n'; continue; }
        int l = 0;
        while((1<<l) <= abs(ys-yf)) { ++l; }
        --l;
        int r;
        if(l < 0) { r = mx[0][ys]; }
        else { r = max(mx[l][min(ys, yf)], mx[l][max(ys, yf)-(1<<l)]); }
        int t = ((n-xs) / k)*k+xs;
        // cout << r << ' ' << t << ' ' << max(ys, yf)-(1<<l) << ' ' << l << endl;
        if(r < t) { cout << "YES" << '\n'; continue; }
        else { cout << "NO" << '\n'; continue; }
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}