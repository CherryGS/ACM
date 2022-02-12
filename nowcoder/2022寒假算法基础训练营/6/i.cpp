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

int k;
char a[200200];
char b[200200];

void solve(cint T) {
    cin >> k;
    cin >> a;
    cin >> b;
    vector<int> ans;
    int le1 = strlen(a);
    int le2 = strlen(b);
    int lst = 0;
    int le = max(le1, le2);
    for(int i=1; i<=le; i++) {
        int r1 = le1 - i;
        int r2 = le2 - i;
        int b1, b2;
        if(r1 < 0) b1 = 0;
        else b1 = a[r1] - '0';
        if(r2 < 0) b2 = 0;
        else b2 = b[r2] - '0';
        int res = b1 + b2 + lst;
        ans.push_back(res % k);
        lst = res / k;
        // cout << r1 << ' ' << r2 << ' ' << b1 << ' ' << b2 << ' ' << res << endl;
    }
    if(lst) ans.push_back(lst);
    
    for(auto k = ans.rbegin(); k != ans.rend(); ++k) cout << *k;
    cout << '\n';
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