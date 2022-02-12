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

int val[2020];
bool vis[2020];

bool check(cint x, cint y) {
    if(x <= y) return false;
    if((x & 1) && x-1 == y) return true;
    int r = x ^ y, num=0;
    for(int i=1; i<=r; i<<=1) {
        if(r&i) {
            ++num;
        }
    }
    if(num == 2) return true;
    return false;
}

bool dfs(cint x) {
    if(val[x] >= 0) return val[x];
    bool ans = false;
    for(int j=0; j<x; j++)
        if(check(x, j)) {
            ans |= dfs(j)^1;
        }
    val[x] = ans;
    return ans;
}

void init() {
    memset(val, -1, sizeof val);
    dfs((1<<10)-1);
    // cout << check(0b1001001, 0b1000011) << endl;
}

void solve(cint T) {
    int n;
    cin >> n;
    char s[11];
    cin >> s;
    int ans = 0;
    for(int i=0; i<n; i++)
        if(s[i] == 'w') ans += 1<<i;
    if(val[ans] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}