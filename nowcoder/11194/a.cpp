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
int sum[2][300100];

bool check(bool st, cint r, cint s) {
    return (sum[st][n] - 2*sum[st][r] + 2*sum[st][s-1]) == 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    char st;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> st;
            if(st == '0') sum[1][i]++;
            else sum[0][i]++;
            sum[0][i] += sum[0][i-1];
            sum[1][i] += sum[1][i-1];
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int r = i+n/2-1;
            int s = i;
            if(r > n) {
                r -= n;
                ++r; --s;
            }
            if(s > r) swap(s, r);
            // cout << i << ' ' << check(0, r, s) << ' ' <<  check(1, r, s) << ' ' << s << ' ' << r << endl;
            if(check(0, r, s) && check(1, r, s)) ++ ans;
        }
        cout << ans << std::endl;
    }
    return 0;
}