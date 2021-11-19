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
typedef __int128_t iint;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll l, r, k;

iint sol1(ll x) {
    iint pre = x;
    iint ans = pre*(pre+1)/2;
    return ans;
}

iint sol(ll x) {
    iint pre = iint(sqrt(x));
    pre -= 1;
    iint ans = pre*(pre+1)*(pre*2+1)/3;
    ans += pre*(pre+1)/2;
    pre += 1;
    ans += (x-pre*pre+1)*pre;
    return ans;
}

iint sol2(ll x) {
    iint pre = x;
    iint ans = 0;
    iint lst = 1;
    iint tmp;
    for(iint i=1; ; i++) {
        iint r = i+1;
        tmp = i;
        for(int j=2; j<=k; j++) r*=(i+1);
        if(r > pre) break;
        ans += i*(r-lst);
        lst = r;
    }
    ans += (pre-lst+1)*tmp;
    return ans;
}

void print(iint x) {
    vector<int> s;
    while(x) {
        s.push_back(x%10);
        x /= 10;
    }
    for(int i=s.size()-1; i>=0; i--) cout << s[i];
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> l >> r >> k;
        if(k == 1) {
            print(sol1(r)-sol1(l-1));
        }
        else if(k == 2) {
            print(sol(r)-sol(l-1));
        }
        else {
            print(sol2(r)-sol2(l-1));
        }
    }
    return 0;
}