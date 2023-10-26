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

char s[1000100];
char st[1000100];
ll x;
int c;

void solve(cint T) {
    c = 0;
    cin >> s;
    cin >> x;
    int n = strlen(s);
    ll sum = 1ll * n * (n+1) / 2;
    int l = 1, r = n, mid;
    while(l < r) {
        mid = l + (r-l) / 2;
        if(sum - 1ll * mid * (mid+1) / 2 >= x) { l = mid+1; }
        else { r = mid; }
    }
    x -= sum - 1ll * r * (r+1) / 2;
    // cout << " --- " << x << ' ' << c << ' ' << r << ' ' << sum << endl;
    for(int i=0; i<n; i++) {
        while(c && r < n && st[c] > s[i]) {
            --c;
            ++r;
        }
        st[++c] = s[i];
    }
    // for(int i=1; i<=c; i++) { cout << st[i] << ' '; }
    // cout << endl;
    cout << st[x];
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
