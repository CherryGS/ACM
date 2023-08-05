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

int n, k;
map<int, int> e[2];

void solve(cint T) {
    cin >> n >> k;
    int tmp;
    e[0].clear();
    e[1].clear();
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        if(e[0].find(tmp) == e[0].end()) { e[0][tmp] = i; }
        e[1][tmp] = i;
    }
    int a, b;
    for(int i=1; i<=k; i++) {
        cin >> a >> b;
        if(e[0].find(a) != e[0].end() && e[0].find(b) != e[0].end()) {
            if(e[0][a] < e[1][b]) { cout << "YES" << '\n'; }
            else { cout << "NO" << '\n'; }
        }
        else { cout << "NO" << '\n'; }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}