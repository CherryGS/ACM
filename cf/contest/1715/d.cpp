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

int n, q;
int a[100100];
int ans[100100];
int p[100100];
bool vis[100100];
vector<int> to[100100];
vector<int> w[100100];

void solve(cint T) {
    cin >> n >> q;
    for(int i=1; i<=n; i++) { a[i] = (1<<30)-1; }
    int x, y, v;
    for(int i=1; i<=q; i++) {
        cin >> x >> y >> v;
        a[x] &= v; a[y] &= v;
        if(x > y) { swap(x, y); }
        if(x == y) { ans[x] = v; }
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        for(int j=30; j>=0; j--) {
            if(((a[i]>>j)%2==0) || (ans[i]>>j)%2==1) { continue; }
            bool flag = 1;
            for(auto &v: to[i]) {
                flag &= (a[v] >> j);
            }
            if(flag) {
                for(auto &v: to[i]) {
                    ans[v] |= (1<<j);
                }
                a[i] ^= (1<<j);
            }
        }
    }
    for(int i=1; i<=n; i++) { cout << (a[i]|ans[i]) << ' '; }
    
    cout << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}