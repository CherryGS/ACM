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
#define ifor(s, e, t) for(int i=s;i<=e;i+=t)
#define jfor(s, e, t) for(int j=s;j<=e;j+=t)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, q;
ll a[200200];
int x[200200];
ll val[33];

void solve(cint T) {
    memset(val, 0, sizeof val);
    vector<int> r;
    cin >> n >> q;
    ifor(1, n, 1) { cin >> a[i]; }
    ifor(1, q, 1) { cin >> x[i]; }
    ifor(1, q, 1) {
        if(val[x[i]] == 0) {
            r.push_back(x[i]);
            val[x[i]] += (1<<(x[i]-1));
            jfor(i+1, q, 1) {
                if(x[j] < x[j-1]) {
                    val[x[i]] += (1<<(x[j]-1));
                }
            }
        }
    }
    r.push_back(0);
    ifor(1, n, 1) {
        for(auto &k: r) {
            if((a[i] % (1<<k)) == 0) {
                cout << val[k] + a[i] << ' ';
                break;
            }
        }
    }
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
