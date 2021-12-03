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
int a[200200];
int to[200200];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) to[a[i]] = i;
        vector<int> ans;
        if(to[n] != 1 && to[n] != n) cout << -1;
        else {
            if(to[n] == n) {
                for(int i=n-1; i>=1; i--) ans.push_back(a[i]);
                ans.push_back(n);
            }
            else {
                ans.push_back(n);
                for(int i=n; i>1; i--) ans.push_back(a[i]);
            }
        }
        for(int i: ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}