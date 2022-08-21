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

ll n, m, p, x, a, b, c;
int s[1000100], t[1000100];
map<int, int> e;

void solve(cint T) {
    e.clear();
    cin >> n >> m >> p >> x >> a >> b >> c;
    for(int i=1; i<=n; i++) { x = (a*x%p*x%p+b*x%p+c) % p; s[i] = x; }
    for(int i=1; i<=m; i++) { x = (a*x%p*x%p+b*x%p+c) % p; t[i] = x; }
    int id = 0;
    for(int i=n; i>=1; i--) { e[s[i]] = i; }
    for(int i=1; i<=m; i++) {
        if(e.find(t[i]) != e.end()) {
            id = max((ll)id, min(n-e[t[i]], m-i)+1);
        }
    }
    cout << id << '\n';
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