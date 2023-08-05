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
int a[21];
vector<pii> q;

void solve(cint T) {
    q.clear();
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int mx = -21, mn = 21, s1 = 0, s2 = 0, i1, i2;
    for(int i=1; i<=n; i++) {
        if(a[i] > mx) {
            mx = a[i];
            i1 = i;
        }
        if(a[i] < mn) {
            mn = a[i];
            i2 = i;
        }
        if(a[i] < 0) { ++s2; }
        else if(a[i] > 0) { ++s1; }
    }
    if(mx > 0 && mn < 0) {
        if(mx + mn <= 0) {
            if(s1 <= 12) {
                for(int i=1; i<=n; i++) {
                    if(a[i] > 0) { q.push_back({i, i2}); }
                }
                mx = 0;
            } else {
                for(int i=1; i<=5; i++) {
                    q.push_back({i1, i1});
                }
                for(int i=1; i<=n; i++) {
                    if(a[i] < 0) { q.push_back({i, i1}); }
                }
                mn = 0;
            }
        }
        else {
            if(s2 <= 12) {
                for(int i=1; i<=n; i++) {
                    if(a[i] < 0) { q.push_back({i, i1}); }
                }
                mn = 0;
            } else {
                for(int i=1; i<=5; i++) {
                    q.push_back({i2, i2});
                }
                for(int i=1; i<=n; i++) {
                    if(a[i] > 0) { q.push_back({i, i2}); }
                }
                mx = 0;
            }
        }
    }
    if(mx > 0) {
        for(int i=1; i<n; i++) { q.push_back({i+1, i}); }
    }
    else {
        for(int i=n; i>1; i--) { q.push_back({i-1, i}); }
    }
    cout << q.size() << '\n';
    for(auto &k: q) {
        cout << k.first << ' ' << k.second << '\n';
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
