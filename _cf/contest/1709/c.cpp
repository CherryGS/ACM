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

char s[200200];
char r[200200];

void solve(cint T) {
    cin >> s;
    int n = strlen(s);
    if(n & 1) { cout << "NO" << '\n'; return; }
    int s1 = 0, s2 = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '?') { ++s1; }
        else if(s[i] == '(') { ++s2; }
    }
    // cout << s2 << ' ' << n << ' ' << s1 << endl;
    if(abs(s2 - (n-s1-s2)) > s1) { cout << "NO" << '\n'; return; }
    int num = n / 2 - s2, t = 0;
    for(int i=0; i<n; i++) {
        r[i] = s[i];
        if(s[i] == '?') {
            if(num > 0) { r[i] = '('; --num; }
            else { r[i] = ')'; }

        }
    }
    for(int i=0; i<n; i++) {
        if(r[i] == '(') {
            ++t;
        }
        else { --t; }
        if(t < 0) { break; }
    }
    if(t != 0) { cout << "NO" << '\n'; return; }
    else if(t == 0 && n/2-s2 == s1) { cout << "YES" << '\n'; return; }
    num = n / 2 - s2, t = 0;
    for(int i=0; i<n; i++) {
        r[i] = s[i];
        if(s[i] == '?') {
            if(num > 0) { r[i] = '('; }
            else {r[i] = ')'; }
            if(num == 1 && s1 - num > 0) { r[i] = ')'; }
            if(num == 0 && s1 - num > 0) { r[i] = '('; }
            --num;
        }
    }
    for(int i=0; i<n; i++) {
        if(r[i] == '(') {
            ++t;
        }
        else { --t; }
        if(t < 0) { break; }
    }
    // cout << t << endl;
    if(t != 0) { cout << "YES" << '\n'; }
    else { cout << "NO" << '\n'; }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}