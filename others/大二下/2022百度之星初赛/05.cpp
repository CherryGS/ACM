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

ll h;
ll a[11];
bool dp[10010];

bool solve(cint T) {
    cin >> h;
    for(int i=1; i<=10; i++) { cin >> a[i]; }
    ll p = 0;
    for(int i=10; i>=1; i--) {
        if(h <= 1000) { break; }
        ll t = h - 1000;
        ll s = min((t+i-1)/i, a[i]);
        h -= s * i;
        p += s * i;
        a[i] -= s;
    }
    if(h > 1000) { cout << p << '\n'; return true; }
    dp[0] = 1;
    for(int i=1; i<=10; i++) {
        if(dp[h] == 1) { break; }
        if(a[i]*i < h) {
            while(a[i]) {
                --a[i];
                for(int j=h; j>=i; j--) {
                    dp[j] |= dp[j-i];
                }
                if(dp[h] == 1) { break; }
            }
        }
        else { for(int j=0; j+i<=h; j++) { dp[j+i] |= dp[j]; } }
    }
    for(int i=h; i>=0; i--) {
        if(dp[i] == 1) { cout << p + i << '\n'; break; }
    }
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