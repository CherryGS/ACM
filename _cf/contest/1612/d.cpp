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

ll a, b, x;
ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x%y); }

bool dfs(ll a, ll b, ll x) {
    // cout << a << ' ' << b << ' ' << x << endl;
    if(a == 0) return b == x;
    if(x > a && x > b) return 0;
    if(a == x || b == x) return 1;
    if(!((b-x)%a)) return 1;
    return dfs(b%a, a, x);
}

void sol(ll a, ll b, ll x) {
    if(a > b) swap(a, b);
    ll g = gcd(a, b);
    // cout << dfs(a, b, x) << endl;
    if((dfs(a, b, x) || dfs(b-a, b, x)) && !(x%g)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> a >> b >> x;
        sol(a, b, x);
    }
    return 0;
}
/*
1

*/