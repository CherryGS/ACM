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

char s[20000010];
int pi[20000100];
int qi[20000100];

bool solve(cint T) {
    cin >> s;
    int n = strlen(s);
    for(int i=1; i<n; i++) {
        int r = pi[i-1];
        while(r && s[r] != s[i]) { r = pi[r-1]; }
        if(s[r] == s[i]) { pi[i] = r + 1; }
    }
    for(int i=1; i<n; i++) {
        int r = qi[i-1];
        while(r && (s[r] != s[i] || (i-r+1)*2 < (i+1))) { r = pi[r-1]; }
        if(s[r] == s[i]) { qi[i] = r + 1; }
    }
    int ans = 1;
    for(int i=1; i<n; i++) { ans = ans ^ (i-qi[i]+1); }
    cout << ans;
    return true;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}