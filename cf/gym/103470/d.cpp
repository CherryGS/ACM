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
bool vis[200100];
ll a[200100];
ll node[200100];
ll sum;

int lb(int x) { return x & -x;}

void add(int x) {
    ++ sum;
    while(x <= n) {
        ++node[x];
        x += lb(x);
    }
}

ll query(int x) {
    ll pre = 0;
    while(x) {
        pre += node[x];
        x -= lb(x);
    }
    return pre;
}


void solve(cint T) {
    cin >> n;
    ll ans = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=0; i<=n; i++) node[i] = 0;
    for(int i=0; i<=n; i++) vis[i] = 0;
    sum = 0;
    ll lst = a[1], pre = 0;
    for(int i=1; i<=n; i++) {
        if(i != 1) {
            if(a[i] <= lst) { 
                ans += sum - query(a[i]);
                if(a[i] == lst) ++pre;
            }
            else {
                lst = a[i];
                ans += 2ll + pre;
                pre = 0;
            }
        }
        if(!vis[a[i]]) { add(a[i]); vis[a[i]] = 1; }
        cout << ans;
        if(i != n) cout << ' ';
    }
    cout << '\n';
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