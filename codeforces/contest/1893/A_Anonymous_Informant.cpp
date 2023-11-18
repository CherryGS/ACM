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

int n, k;
int b[200200];
set<int> e;

void solve(cint T) {
    e.clear();
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> b[i]; }
    int s = 0; e.insert(0);
    while(k) {
        int r = (n-1-s+n) % n + 1;
        int c = b[r];
        if(c > n) { break; }
        s = (s + c) % n;
        if(e.count(s) == 1) { k = 0; break; }
        else { e.insert(s); }
        --k;
    }
    // cout << k << endl;
    if(k == 0) { cout << "Yes\n"; }
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
