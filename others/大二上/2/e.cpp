#include <bits/stdc++.h>
using namespace std;

//std::mt19937 rng(std::random_device{}());
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

int n, i, j;

void dfs(cint x, cint y, cint dx, cint dy) {
    if(x < 1 || x > n) return;
    if(y < 1 || y > n) return;
    cout << '(' << x << ',' << y << ')';
    dfs(x+dx, y+dy, dx, dy);
}

void solve(cint T) {
    cin >> n >> i >> j;
    dfs(i, 1, 0, 1);
    cout << endl;
    dfs(1, j, 1, 0);
    cout << endl;
    int r = min(i, j)-1;
    dfs(i-r, j-r, 1, 1);
    cout << endl;
    r = min(n-i, j-1);
    dfs(i+r, j-r, -1, 1);
    cout << endl;
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