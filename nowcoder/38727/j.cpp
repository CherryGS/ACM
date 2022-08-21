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
int a[1000100];
int b[1000100];

bool sol(int x) {
    int u, v;
    for(int i=1; i<=n; i++) { b[i] = (x-a[i]+3) % 3; }
    for(int i=1; i<=n; i++) {
        if(i == 1) { v = n; }
        else { v = i-1; }
        if(b[v]-b[i] >= 2) { b[i] += 3*((b[v]-b[i]+1)/3); }
    }
    int l=0;
    for(int i=1; i<=n; i++) { if(b[i] == 0) { l = i; } }
    if(l == 0) { return false; }
    // cout << " --- " << endl;
    // for(int i=0; i<n; i++) {
    //     u = (l-i+n) % n;
    //     v = (u-1+n) % n;
    //     if(u == 0) { u = n; }
    //     if(v == 0) { v = n; }
    //     if(b[v]-b[u] > 1) { return false; } 
    // }
    return true;
}

void solve(cint T) {
    cin >> n;
    int u, v;
    bool flag = false;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    flag |= sol(0);
    flag |= sol(1);
    flag |= sol(2);
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