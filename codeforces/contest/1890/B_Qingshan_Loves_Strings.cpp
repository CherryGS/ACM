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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m;
char s[1010], t[1010];

void solve(cint T) {
    cin >> n >> m;
    cin >> s;
    cin >> t;
    bool flag = true;
    for(int i=0; i<m-1; i++) {
        if(t[i] == t[i+1]) { flag = false; break; }
    }
    bool ans = true;
    for(int i=0; i<n-1; i++) {
        if(s[i] == s[i+1]) {
            if(!flag) { ans = false; break; }
            if(s[i] == t[0] || s[i] == t[m-1]) { ans = false; break; }
        }
    }
    if(ans) { cout << "Yes\n"; }
    else { cout << "No\n"; }
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
