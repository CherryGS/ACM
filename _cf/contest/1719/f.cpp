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

int n, q;
int a[200200];
bool vis[200200];
vector<ll> val[200200];

void init() {
    vis[1] = 1;
    for(int i=2; i<=200000; i++) {
        if(vis[i]) { continue; }
        for(int j=i+i; j<=200000; j+=i) { vis[j] = 1; }
    }
}

bool solve(cint T) {
    cin >> n >> q;
    for(int i=0; i<n; i++) { cin >> a[i]; }
    for(int i=0; i<=n; i++) { val[i].clear(); }
    int tmp = n;
    vector<int> e;
    for(int i=2; i<=sqrt(n); i++) { if(vis[i] == 0 && (tmp % i == 0)) { e.push_back(i); } while(tmp % i == 0) { tmp /= i; } }
    if(tmp > 1) { e.push_back(tmp); }
    multiset<ll> p;
    for(auto &k: e) {
        int t = n/k;
        for(int i=0; i<t; i++) {
            ll sum = 0;
            for(int j=0; j<k; j++) { sum += a[(j*t+i)%n]; }
            sum = sum * t;
            // cout << sum << ' ' << i << ' ' << k << endl;
            val[k].push_back(sum);
            p.insert(-sum);
        }
    }
    cout << -*p.begin() << '\n';
    ll x, y;
    for(int i=1; i<=q; i++) {
        cin >> x >> y;
        --x;
        for(auto &k: e) {
            int t = n/k;
            ll s = val[k][x%t];
            // cout << k << ' ' << x%t << ' ' << a[x] << ' ' << s << endl;
            if(p.find(-s) == p.end()) { while(1) {} }
            p.erase(p.find(-s));
            s += (y-a[x])*t;
            val[k][x%t] = s;
            p.insert(-s);
        }
        a[x] = y;
        cout << -*p.begin() << '\n';
    }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}