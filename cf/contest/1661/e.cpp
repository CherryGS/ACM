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
char s[3][500500];
int l[500500];
int r[500500];
int dp[500500];

void solve(cint T) {
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    bool first = false;
    for(int i=0; i<n; i++) {
        if(s[0][i] == '1') {
            if(!first) { first = true; ++l[i]; }
            else if(i == 0 || s[0][i-1] != '1') {
                if(s[1][i] != '1') { ++l[i]; }
            }
        }
        if(s[1][i] == '1') {
            if(!first) { first = true; ++l[i]; }
            else if(s[0][i] != '1' && s[2][i] != 1) {
                ++l[i];
            }
        }
        if(s[2][i] == '1') {
            if(!first) { first = true; ++l[i]; }
            else if(i == 0 || s[2][i-1] != '1') {
                if(s[1][i] != '1') { ++l[i]; }
            }
        }
    }
    first = false;
    for(int i=n-1; i>=0; i--) {
        if(s[0][i] == '1') {
            if(!first) { first = true; ++r[i]; }
            else if(i == n-1 || s[0][i+1] != '1') {
                if(s[1][i] != '1') { ++r[i]; }
            }
        }
        if(s[1][i] == '1') {
            if(!first) { first = true; ++r[i]; }
            else if(s[0][i] != '1' && s[2][i] != 1) {
                ++r[i];
            }
        }
        if(s[2][i] == '1') {
            if(!first) { first = true; ++r[i]; }
            else if(i == 0 || s[2][i-1] != '1') {
                if(s[1][i] != '1') { ++r[i]; }
            }
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}