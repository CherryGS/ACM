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

int m, k;
int a[505];
int sum;
int ans[2][505];

bool check(cint x) {
    memset(ans, 0, sizeof ans);
    int s = m;
    for(int i=1; i<=m; i++)
        if(a[i] > x) return 0;
    for(int i=k; i>=1; --i) {
        int sum = 0;
        ans[1][i] = s;
        while(s >= 1 && sum + a[s] <= x) {
            sum += a[s];
            --s;
        }
        ans[0][i] = s+1;
    }
    return s < 1;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> m >> k;
        for(int i=1; i<=m; i++)
            cin >> a[i];
        for(int i=1; i<=m; i++)
            sum += a[i];
        int l = 0, r = sum, mid;
        while(l < r) {
            mid = l + (r - l) / 2;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        check(r);
        for(int i=1; i<=k; i++)
            cout << ans[0][i] << ' ' << ans[1][i] << endl;
    }
    return 0;
}