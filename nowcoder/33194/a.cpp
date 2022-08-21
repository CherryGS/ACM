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
int a[100100];
int num[100100];
int sum;

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    ll ans = 0, l = 1;
    while(sum < m && l <= n) {
        if(num[a[l]] == 0) { ++sum; }
        ++num[a[l]];
        ++l;
    }
    --l;
    // cout << l << endl;
    if(sum < m) { cout << 0 << '\n'; return; }
    int r = 1;
    while(num[a[r]] > 1 && r <= n) {
        --num[a[r]];
        ++r;
    }
    ans += r;
    for(int i=l+1; i<=n; i++) {
        if(num[a[i]] == 0) { ++sum; }
        ++num[a[i]];
        while(num[a[r]] > 1 && r <= i) {
            --num[a[r]];
            ++r;
        }
        ans = ans + r;
        // cout << r << endl;
    }
    cout << ans << '\n';
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