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

int g(int x) {
    return x ? g(x/10) + 1 : 0;
}

void solve(cint T) {
    cin >> n;
    int ans = inf_int, val;
    for(int i=7; i<=n*10; i+=7) {
        int num = 0;
        if(g(i) < g(n) || g(i) > g(n)) continue;
        if(n%10 != i%10) ++num;
        if(n%100 != i%100) ++num;
        if(n%1000 != i%1000) ++num;
        if(num < ans) {
            ans = num;
            val = i;
        }
    }
    cout << val << endl;
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