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
int a[100100];
int r[100100];
int ans[100100];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { a[i] = 0; }
    for(int i=1; i<=n; i++) { cin >> r[i]; a[r[i]]++; }
    vector<pii> q;
    for(int i=1; i<=n; i++) { q.push_back({a[i], i}); }
    sort(q.begin(), q.end());
    int z = n-1, st = 0;
    for(int i=1; i<=n; i++) {
        cout << z << ' ' << q[z].second << endl;
        if(q[z].second != r[i]) { ans[i] = q[z].second; --z; }
        else if(z == 0) { st = 1; break; }
        else { ans[i] = q[z-1].second; q[z-1] = q[z]; --z; }
    }
    if(st == 0) { cout << "YES\n"; for(int i=1; i<=n; i++) { cout << ans[i] << ' '; } cout << '\n'; }
    else { cout << "NO\n"; }
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