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

pii get_mx(int l, int r) {
    bool flag = true;
    for(int i=l; i<=r; i++) { if(a[i] < 1) { flag ^= true; } }
    if(flag) { return {0, 0}; }
    int dl = 0, dr = 0;
    int nl = 0, nr = 0;
    for(int i=l; i<=r; i++) {
        if(a[i] == 2 || a[i] == -2) { ++dl; }
        if(a[i] < 0) { nl = i; break; }
    }
    for(int i=r; i>=l; i--) {
        if(a[i] == 2 || a[i] == -2) { ++dr; }
        if(a[i] < 0) { nr = i; break; }
    }
    if(dl > dr) { return {0, r-nr+1}; }
    else { return {nl-l+1, 0}; }
}

int cacu(int l, int r) {
    ++l; --r;
    bool flag = true;
    for(int i=l; i<=r; i++) { if(a[i] < 1) { flag ^= true; } }
    int dl = 0, dr = 0, sum = 0;
    for(int i=l; i<=r; i++) {
        if(a[i] == 2 || a[i] == -2) { ++sum; }
    }
    for(int i=l; i<=r; i++) {
        if(a[i] == 2 || a[i] == -2) { ++dl; }
        if(a[i] < 0) { break; }
    }
    for(int i=r; i>=l; i--) {
        if(a[i] == 2 || a[i] == -2) { ++dr; }
        if(a[i] < 0) { break; }
    }
    if(flag) { return sum; }
    else { return max(sum - dl, sum - dr); }
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    a[n+1] = 0;
    int l = 0;
    int ans[2] = {0, 0};
    int mx = 0;
    for(int i=1; i<=n+1; i++) {
        if(a[i] == 0) {
            // cout << i << " --- " << endl;
            int t = cacu(l, i);
            if(t > mx) {
                mx = t;
                ans[0] = l+1;
                ans[1] = i-1;
            }
            l = i;
        }
    }
    pii tt = get_mx(ans[0], ans[1]);
    // cout << ans[0] << ' ' << ans[1] << endl;
    // cout << tt.first << ' ' << tt.second << endl;
    cout << ans[0]-1+tt.first << ' ' << n-ans[1]+tt.second << '\n';
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