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

int x[5], y[5];
double len[5][5];

void solve(cint T) {
    for(int i=1; i<=3; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<=3; i++) {
        for(int j=0; j<=3; j++) {
            len[i][j] = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
        }
    }
    double ans = 100000000;
    ans = min(ans, max(len[2][0], len[2][1]));
    ans = min(ans, max(len[3][0], len[3][1]));
    ans = min(ans, max(len[2][0], max(len[2][3]/2, len[3][1])));
    ans = min(ans, max(len[3][0], max(len[2][3]/2, len[2][1])));
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
