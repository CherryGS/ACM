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
int b[100100];
bool vis[100100];

bool check(int x) {
    bool flag = true;
    for(int i=1; i<=x; i++) { vis[a[i]] = 1; }
    for(int i=1; i<=n; i++) { if(vis[a[i]]) { b[i] = 0; } else { b[i] = a[i]; } }
    for(int i=1; i<=n; i++) { if(b[i] < b[i-1]) { flag = false; break; } }
    for(int i=1; i<=x; i++) { vis[a[i]] = 0; }
    return flag;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int l = 0, r = n, mid;
    while(l < r) {
        mid = l + ((r-l)>>1);
        if(check(mid)) { r = mid; }
        else { l = mid + 1; }
    }
    int ans = 0;
    for(int i=1; i<=r; i++) { if(!vis[a[i]]) { ++ans; vis[a[i]] = 1; } }
    for(int i=1; i<=r; i++) { vis[a[i]] = 0; }
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