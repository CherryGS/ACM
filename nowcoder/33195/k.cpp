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
int a[5005];
int b[5005];
int h[5005], nx[10010], to[10010], w[10010], cnt;
ll dp[(1<<5)][5001];

void add(int f, int t, int co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

ll sol() {
    for(int i=1; i<=n; i++) { b[i] = rand() % k + 1; }
    memset(dp, 0, sizeof dp);
    
}

bool solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int u, v, c;
    for(int i=1; i<n; i++) {
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }

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