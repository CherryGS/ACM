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

int n, m;
char s[101][101];

struct node {
    int a, b, c, d;
};

void solve(cint T) {
    cin >> n >> m;
    for(int i=0; i<n; i++) { cin >> s[i]; }
    vector<node> ans;  
    if(s[0][0] == '1') { cout << -1 << '\n'; return; }
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>0; j--) {
            if(s[i][j] == '1') { ans.push_back({i+1, j, i+1, j+1}); }
        }
    }
    for(int i=n-1; i>0; i--) {
        if(s[i][0] == '1') { ans.push_back({i, 1, i+1, 1}); }
    }
    cout << ans.size() << '\n';
    for(auto &k: ans) {
        cout << k.a << ' ' << k.b << ' ' << k.c << ' ' << k.d << '\n';
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}