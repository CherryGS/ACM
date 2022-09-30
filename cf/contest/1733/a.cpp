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
int a[1001];
vector<int> t[101];

bool solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=0; i<=k; i++) { t[i].clear(); }
    for(int i=1; i<=k; i++) {
        for(int j=i; j<=n; j+=k) {
            t[i-1].push_back(a[j]);
        }
    }
    for(int i=0; i<k; i++) { sort(t[i].begin(), t[i].end()); }
    for(int i=1; i<=k; i++) {
        for(int j=i; j<=n; j+=k) {
            a[j] = t[i-1][(j-i)/k];
        }
    }
    ll mx = 0;
    for(int i=n; i>=k; i--) {
        ll tmp = 0;
        for(int j=1; j<=k; j++) {
            tmp += a[i-j+1];
        }
        mx = max(mx, tmp);
    }
    cout << mx << '\n';
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