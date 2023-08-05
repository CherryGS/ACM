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
map<int, int> e;

void solve(cint T) {
    cin >> n;
    e.clear();
    if(n == 2) { cout << "NO\n"; return; }
    if(n & 1) { e[2] = 1; e[3] = 1; e[6] = 1; }
    else { e[2] = 1; e[4] = 1; e[6] = 1; e[12] = 1; }
    int k, v;
    for(int i=1; i<=(n-3)/2; i++) {
        auto r = e.begin();
        k = r->first;
        v = r->second;
    }
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
