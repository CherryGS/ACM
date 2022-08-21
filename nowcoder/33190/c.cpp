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
int s[2][100100];

void solve(cint T) {
    n = 0;
    cin >> n;
    if(n == 0) { return; }
    for(int i=0; i<=n; i++) { s[0][i] = s[1][i] = 0; }
    for(int i=1; i<=n*3; i++) {
        int k;
        string t;
        cin >> k >> t;
        if(t[0] == 'N') { s[0][k]++; }
        else { s[1][k]++; }
    }
    bool flag = true;
    string ans;
    for(int i=0, st=0; i<n; i++) {
        if(s[0][i] != 0 && s[1][i] != 0) {
            if(st == 1) { flag = false; break; }
            if(s[0][i] == 1 && s[1][i] == 1) { flag = false; break; }
            if(s[0][i] > 1 && s[1][i] > 1) { flag = false; break; }
            if(s[0][i] == 1) { ans += '1'; }
            else { ans += '0'; }
            st = 1;
        }
        else if(s[0][i] != 0) { ans += '0'; }
        else { ans += '1'; }
    }
    if(flag) { cout << ans << '\n'; }
    else { cout << -1 << '\n'; }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1000;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}