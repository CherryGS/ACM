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
int b[200200], p[200200];
int dis[200200];
int ans[200200];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> b[i];
        for(int i=1; i<=n; i++) cin >> p[i];
        bool flag = 0;
        for(int i=1; i<=n; i++) dis[i] = -1;
        if(b[p[1]] != p[1]) flag = 1;
        else { dis[p[1]] = 0; ans[p[1]] = 0; }
        for(int i=2; i<=n; i++) {
            if(flag) break;
            int fa = b[p[i]];
            if(dis[fa] < 0) flag = 1;
            else {
                dis[p[i]] = dis[p[i-1]] + 1;
                ans[p[i]] = dis[p[i]] - dis[fa];
            }
        }
        if(flag) cout << -1 << endl;
        else {
            for(int i=1; i<=n; i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}