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


struct node {
    int id;
    ll t, d;
    void init(int x) {
        id = x;
        cin >> t >> d;
    }
    bool operator < (const node&a) const {
        return d == a.d ? t < a.t : d < a.d;
    }
};

int n;
bool vis[5050];
node a[5050];
int ans[5050];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { a[i].init(i); }
    sort(a+1, a+1+n);
    ll sum_t = 0;
    for(int i=1; i<=n; i++) {
        sum_t += a[i].t;
        if(sum_t > a[i].d) {
            cout << '*' << '\n';
            return;
        }
    }
    for(int i=1; i<=n; i++) {
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