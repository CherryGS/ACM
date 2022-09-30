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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[100100];
int dp[2][100100];

bool solve(cint T) {
    cin >> n;
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;
    dp[1][1] = inf_int;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<n; i++) {
        if(dp[0][i+1] < 0) { dp[0][i+1] = inf_int; }
        if(dp[1][i+1] < 0) { dp[1][i+1] = 0; }
        if(a[i+1] >= dp[0][i]) {
            dp[1][i+1] = max(dp[1][i+1], a[i]);
        }
        if(a[i+1] >= a[i]) {
            dp[1][i+1] = max(dp[1][i+1], dp[1][i]);
        }
        if(a[i+1] <= dp[1][i]) {
            dp[0][i+1] = min(dp[0][i+1], a[i]);
        }
        if(a[i+1] <= a[i]) {
            dp[0][i+1] = min(dp[0][i+1], dp[0][i]);
        }
    }
    if(dp[0][n] < inf_int || dp[1][n] > 0) { cout << "yes\n"; }
    else { cout << "no\n"; }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}