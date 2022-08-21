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

int m;
int a[101];

void solve(cint T) {
    cin >> m;
    if(m == 1) { cout << 1 << '\n' << 1 << '\n'; return; }
    vector<int> ans;
    for(int i=1; i<=100; i++) { a[i] = i; }
    int len = 0;
    for(int i=31; i>=0; i--) {
        if((1ll<<i) & m) {
            cout << i << ' ' << len << endl;
            // reverse(a+1+len, a+1+len+i*2);
            for(int j=len+1; j<len+i*2+1; j+=2) { swap(a[j], a[j+1]); }
            for(int i=1; i<=100; i++) { cout << a[i] << ' '; }
            cout << '\n';
            len += i*2;
        }
    }
    cout << 100 << '\n';
    for(int i=1; i<=100; i++) { cout << a[i] << ' '; }
    cout << '\n';
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