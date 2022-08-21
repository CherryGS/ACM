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
int a[1000100];
int k1, k2, p;

void solve(cint T) {
    string ans;
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    cin >> k1 >> k2 >> p;
    ll s1 = 0, s2 = 0;
    for(int i=1; i<=n; i++) {
        s1 += a[i];
        s2 += a[i];
        if(i > k1) { s1 -= a[i-k1]; }
        if(i > k2) { s2 -= a[i-k2]; }
        if(i < k2) { ans += '0'; }
        else { ans += ((double(s2)/k2*p/100)>=(double(s1)/k1)) + '0'; }
    }
    cout << ans << '\n';
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