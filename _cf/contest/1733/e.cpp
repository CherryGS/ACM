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

bool vis[130][130];

void sim() {
    int x = 0, y = 0;
    string ans;
    while(x < 120 && y < 120) {
        ans += '0' + vis[x][y];
        vis[x][y] ^= 1;
        if(vis[x][y] == 1) { ++y; }
        else { ++x; }
    }
    // cout << ans << '\n';
    for(int i=0; i<120; i++) { cout << vis[2][i]; }
    cout << '\n';
}

bool solve(cint T) {
    for(int i=1; i<=100000; i++) { sim(); }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}