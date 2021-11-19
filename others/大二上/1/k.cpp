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

char s[1001000];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> s;
        int n = strlen(s);
        ll ans = 0;
        ll pre = 1;
        for(int i=n-1; i>=0; i--) {
            ans = (ans + pre*(s[i]-'0')) % 101;
            pre = (pre * 10) % 101;
            // cout << ans << ' ' << pre << endl;
        }
        if(ans == 0) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}