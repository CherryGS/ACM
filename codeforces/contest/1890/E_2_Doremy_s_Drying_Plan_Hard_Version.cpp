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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m, k;
vector<pii> q;
int dp[11][200200];
int mx[200200];
int num[200200];

void solve(cint T) {
    cin >> n >> m >> k;
    q.clear();
    int l, r;
    for(int i=1; i<=n; i++) { mx[i] = num[i] = 0; }
    for(int i=1; i<=m; i++) {
        cin >> l >> r;
        mx[l] = max(mx[l], r);
        ++num[l];
    }
    sort(q.begin(), q.end(), [](const pii&a, const pii&b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k-num[i]; j++) {
        }
    }
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
