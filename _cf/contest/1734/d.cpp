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
int a[200200];

bool solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    ll mx1 = 0, mx2 = 0;
    ll sum1 = 0, sum2 = 0;
    int l = k-1, r = k+1;
    int cnt = n;
    while(cnt--) {
        while(l > 0 && sum1+mx2+a[k]+a[l]>=0) { sum1 += a[l--]; mx1 = max(mx1, sum1); }
        while(r < n+1 && sum2+mx1+a[k]+a[r]>=0) { sum2 += a[r++]; mx2 = max(mx2, sum2); }
        if(l <= 0 || r >= n+1) { break; }
    }
    if(l <= 0 || r >= n+1) { cout << "YES\n"; }
    else { cout << "NO\n"; }
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