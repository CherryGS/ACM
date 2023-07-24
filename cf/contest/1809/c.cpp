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

int n, k;
int ans[31];

bool solve(cint T) {
    cin >> n >> k;
    int st = 1;
    if(n*(n+1)/2 <= k*2) { st = -1; k = n*(n+1)/2 - k; }
    int p = sqrt(k)+1, l = 1;
    for(int i=1; i<=n; i++) { ans[i] = -999; }
    for(int i=p; i>=1; i--) {
        int r = i*(i+1)/2;
        // cout << i << ' ' << l << ' ' << r << endl;
        if(k == 2) {
            ans[l] = 2; ++l;
            ans[l] = -1; ++l;
            k -= 2;
        }
        while(k >= r) {
            for(int j=1; j<=i; j++) { ans[l] = 1; ++l; }
            ++l;
            k -= r;
        }
    }
    for(int i=1; i<=n; i++) { cout << ans[i]*st << ' '; }
    cout << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}