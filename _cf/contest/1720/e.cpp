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
int a[505][505];
int num[505*505];
int x[2][505*505];
int y[2][505*505];
int val[502][502];

void solve(cint T) {
    cin >> n >> k;
    int sum = 0;
    memset(x[0], 1, sizeof x[0]);
    memset(y[0], 1, sizeof y[0]);
    memset(x[1], -1, sizeof x[1]);
    memset(y[1], -1, sizeof y[1]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
            ++num[a[i][j]];
            x[0][a[i][j]] = min(x[0][a[i][j]], i);
            x[1][a[i][j]] = max(x[1][a[i][j]], i);
            y[0][a[i][j]] = min(y[0][a[i][j]], j);
            y[1][a[i][j]] = max(y[1][a[i][j]], j);
            if(num[a[i][j]] == 1) { ++sum; }
        }
    }
    if(sum <= k) { cout << k-sum << '\n'; }
    else {
        int mx;
        bool flag = false;
        for(int l=1; l<=n; l++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    val[i][j] = 0;
                }
            }
            for(int i=1; i<=n*n; i++) {
                if(y[1][i] <= 0 || x[1][i] <= 0) { continue; }
                mx = max(y[1][i]-y[0][i], x[1][i]-x[0][i]) + 1;
                if(mx <= l) { 
                    val[max(x[1][i], l)][max(y[1][i], l)] += 1;
                    val[min(x[0][i]+l, n+1)][min(y[0][i]+l, n+1)] += 1;
                    val[max(x[1][i], l)][min(y[0][i]+l, n+1)] -= 1;
                    val[min(x[0][i]+l, n+1)][max(y[1][i], l)] -= 1;
                }
            }
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    val[i][j] += val[i][j-1] + val[i-1][j] - val[i-1][j-1];
                    if(sum-val[i][j] <= k && sum-val[i][j] >= k-1) { flag = true; break; }
                }
            }
            if(flag) { break; }
        }
        if(flag) { cout << 1 << '\n'; }
        else { cout << 2 << '\n'; }
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}