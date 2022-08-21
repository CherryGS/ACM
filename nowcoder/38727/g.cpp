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
char s[300100];
int q[300100], cnt;

bool sol(char x, char y) {
    cnt = 0;
    int sum = 0;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == '?') { q[++cnt] = i; }
        else if(s[i] == y) { ++sum; }
        else if(s[i] == x){
            if(sum > 0) { --sum; }
            else { if(cnt == 0) { return false; } s[q[cnt--]] = y; }
        }
    }
    return true;
}

bool sol1(char x, char y) {
    cnt = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '?') { q[++cnt] = i; }
        else if(s[i] == y) { ++sum; }
        else if(s[i] == x){
            if(sum > 0) { --sum; }
            else { if(cnt == 0) { return false; } s[q[cnt--]] = y; }
        }
    }
    return true;
}

void solve(cint T) {
    cin >> s;
    n = strlen(s);
    int s1 = 0;
    for(int i=0; i<n; i++) { if(s[i] == 'r') { ++s1; } }
    s1 = n/3 - s1;
    // cout << "---" << endl;
    bool flag = true;
    flag &= sol1('d', 'e');
    if(s1 < 0) { flag = false; }
    for(int i=0; i<n; i++) { if(s1 == 0) { break; } if(s[i] == '?') { s[i] = 'r'; --s1; } }
    if(s1 > 0) { flag = false; }
    flag &= sol('r', 'e');
    flag &= sol('e', 'd');
    int r[3] = {0, 0, 0};
    for(int i=0; i<n; i++) {
        if(s[i] == '?') { flag = false; break; }
        if(s[i] == 'r') { ++r[0]; }
        else if(s[i] == 'e') { ++r[1]; }
        else { ++r[2]; }
    }
    // cout << r[0] << ' ' << r[1] << ' ' << r[2] << endl;
    // cout << s << endl;
    if(r[0] != r[1] || r[0] != r[2] || r[1] != r[2]) { flag = false; }
    if(flag) { cout << "Yes" << '\n'; }
    else { cout << "No" << '\n'; }
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