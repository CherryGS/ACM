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

int x, n;
int t[10010];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> x >> n;
        x *= 60;
        for(int i=1; i<=n; i++) cin >> t[i];
        t[++n] = x;
        sort(t+1, t+1+n);
        int ans = 0;
        int lst = 0;
        for(int i=1; i<=n; i++) {
            if(t[i] > x) break;
            if(t[i] - lst > 20) ans += t[i] - lst - 20;
            lst = t[i];
        }
        cout << ans << endl;
        if(!ans) cout << "Stay Up Late." << endl;
    }
    return 0;
}