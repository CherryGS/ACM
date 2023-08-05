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

int n, d;
int a[200200];

int mymove(cint x) {
    int ans = 0;
    int pre = inf_int;
    for(int i=0; i<n; i++) {
        if(i == x) continue;
        if(i == x-1) { pre = min(pre, a[i+2]-a[i]-1); }
        else { pre = min(pre, a[i+1]-a[i]-1); }
    }
    for(int i=0; i<n; i++) {
        ans = max(ans, (a[i+1]-a[i]-2)/2);
    }
    ans = max(ans, (a[x+1]-a[x-1]-2)/2);
    if(x == n) ans = max(ans, d-a[n-1]-1);
    else ans = max(ans, d-a[n]-1);
    // cout << ans << ' ' << pre << endl;
    return min(ans, pre);
}

void solve(cint T) {
    cin >> n >> d;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    a[0] = 0;
    a[n+1] = d;
    int val[2] = {inf_int, inf_int};
    int id[2] = {0, 0};
    for(int i=0; i<n; i++) {
        int r = a[i+1] - a[i] - 1;
        if(r < val[0]) {
            val[1] = val[0];
            val[0] = r;
            id[1] = id[0];
            id[0] = i;
        }
        else if(r < val[1]) {
            val[1] = r;
            id[1] = i;
        }
    }
    int ans = val[0];
    ans = max(ans, mymove(id[0]+1));
    if(id[0]) ans = max(ans, mymove(id[0]));
    cout << ans << endl;
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