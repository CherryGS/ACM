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
ll cnt[1000010];
ll x[100010];
ll val[2][1000010];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> x[i];
    sort(x+1, x+1+n);
    ll a = 0, b = 0, c = 0;
    int r = 1;
    for(int i=x[1]; i<=x[n]; i++) {
        val[0][i] = val[0][i-1] + c + b;
        b += a;
        while(i == x[r]) {
            ++ r;
            ++ c;
            a += 2;
        }
    }
    r = n;
    a = b = c = 0;
    for(int i=x[n]; i>=x[1]; i--) {
        val[1][i] = val[1][i+1] + c + b;
        b += a;
        while(i == x[r]) {
            -- r;
            ++ c;
            a += 2;
        }
    }
    ll ans = inf_ll;
    int id;
    for(int i=x[1]; i<=x[n]; i++) {
        // cout << i << " --- " << val[0][i] + val[1][i] << endl;
        if(val[0][i] + val[1][i] <= ans) {
            ans = val[0][i] + val[1][i];
            id = i;
        }
    }
    cout << id << endl;
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