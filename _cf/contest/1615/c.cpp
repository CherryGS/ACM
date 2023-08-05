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
char a[100100];
char b[100100];


void solve(cint T) {
    cin >> n;
    cin >> a >> b;
    int a1 = 0, a2 = 0;
    int s1 = 0, s2 = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == b[i]) {
            if(a[i] == '1') ++ a1;
            else -- a1;
            ++s1;
        }
        else {
            if(a[i] == '1') ++ a2;
            else -- a2;
            ++s2;
        }
    }
    int ans = inf_int;
    if(a2 == 0) ans = min(ans, s2);
    if(a1 == 1) ans = min(ans, s1);
    if(ans > n) cout << -1 << endl;
    else cout << ans << endl;
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