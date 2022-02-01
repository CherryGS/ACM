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

vector<bool> s[2];

void init(ll x, int st) {
    vector<bool> tmp;
    for(int i=63; i>=0; i--) {
        if((1ull<<i) <= x) { x -= (1ull<<i); tmp.push_back(1); }
        else tmp.push_back(0);
    }
    int l = 0, r = 63;
    while(tmp[l] == 0) ++l;
    while(tmp[r] == 0) --r;
    // cout << l << ' ' << r << endl;
    for(; l<=r; l++) s[st].push_back(tmp[l]);
}

void solve(cint T) {
    ll tmp;
    cin >> tmp;
    init(tmp, 0);
    cin >> tmp;
    init(tmp, 1);
    for(int a: s[0]) cout << a;
    cout << endl;
    for(int a: s[1]) cout << a;
    cout << endl;
    bool st = 0;
    for(int i=0; i<s[1].size(); i++) {
        if(s[1][i] == s[0][0] && s[1].size() > s[0].size()+i) {
            for(int j=0; j<s[0].size(); j++) {
                if(s[1][i+j] != s[0][j]) break;
                if(j == s[0].size()-1) {
                    st = 1;
                }
            }
        }
    }
    for(int i=s[1].size()-1; i>=0; i--) {
        if(s[1][i] == s[0][0] && i+1 >= s[0].size()) {
            for(int j=0; j<s[0].size(); j++) {
                if(s[1][i-j] != s[0][j]) break;
                if(j == s[0].size()-1) {
                    st = 1;
                }
            }
        }
    }
    if(st == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}