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

int n, q;
char s[100100];

bool check(cint i) {
    return s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c';
}

void solve(cint T) {
    cin >> n >> q;
    cin >> s;
    int r = 0;
    for(int i=0; i<n; i++) {
        if(i <= n-3) {
            if(check(i)) ++ r;
        }
    }
    int x;
    char t;
    for(int i=1; i<=q; i++) {
        cin >> x >> t;
        --x;
        if(s[x] != t) {
            if(x <= n-3) r -= check(x);
            if(x <= n-2 && x >= 1) r -= check(x-1);
            if(x <= n-1 && x >= 2) r -= check(x-2);
            s[x] = t;
            if(x <= n-3) r += check(x);
            if(x <= n-2 && x >= 1) r += check(x-1);
            if(x <= n-1 && x >= 2) r += check(x-2);
        }
        cout << r << endl;
    }
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