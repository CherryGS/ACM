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

int n, m;
char s[5005], t[5005];
int dp[5005][5005];

void solve(cint T) {
    cin >> n >> m;
    cin >> s;
    cin >> t;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i] == t[j]) {
                if(i == 0 || j == 0) { dp[i][j] = 1; }
                else { dp[i][j] = dp[i-1][j-1] + 1; }
            }
        }
    }
    int l = 0;
    for(int i=0; i<n; i++) {
        if(l < m && s[i] == t[l]) { ++l; }
        for(int j=-1; j<l; j++) {

        }
    }
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