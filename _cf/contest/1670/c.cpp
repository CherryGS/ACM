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
int c[100100];
int to[100100];
bool vis[100100];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) { cin >> b[i]; }
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    for(int i=1; i<=n; i++) { to[i] = vis[i] = 0; }
    for(int i=1; i<=n; i++) { to[a[i]] = i; }
    ll sum = 1;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            int r = i;
            bool flag = false;
            int len = 0;
            while(true) {
                vis[r] = 1;
                r = to[b[r]];
                if(c[r] != 0) { flag = true; }
                ++len;
                if(r == i) { break; }
            }
            if(!flag && len > 1) { sum = (sum * 2) % mod1; }
        }
    }
    cout << sum << '\n';
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