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

int n, k;
int a[100100];
bool vis[100100];

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { vis[i] = 0; }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    if(n == 2) {
        if(k == 0) { cout << min(a[1], a[2]) << '\n'; }
        else if(k == 1) { cout << max(a[1], a[2]) << '\n'; }
        else { cout << int(1e9) << '\n';}
        return;
    }
    int ans = 0;
    set<pii> e1, e2;
    for(int i=1; i<=2; i++) { e1.insert({a[i], i}); }
    for(int i=3; i<=n; i++) { e2.insert({a[i], i}); }
    int num = k;
    while(num) {
        auto k1 = *e1.begin();
        auto k2 = *e2.begin();
        if(k1.first < k2.first*2) {
            if(k1.first == 1e9) { break; }
            vis[k1.second] = 1;
            e1.insert({int(1e9), k1.second});
            e1.erase(e1.begin());
            --num;
        }
        else {
            if(k2.first == 1e9) { break; }
            vis[k2.second] = 1;
            e2.insert({int(1e9), k2.second});
            e2.erase(e2.begin());
            --num;
        }
        ans = max(ans, min(e1.begin()->first, e2.begin()->first*2));
    }
    // for(int i=1; i<=n; i++) { cout << vis[i] << ' '; }
    // cout << endl;
    for(int i=1; i<=n-2; i++) {
        // cout << e1.begin()->first << ' ' << e2.begin()->first << ' ' << e1.begin()->second << ' ' << e2.begin()->second << endl;
        if(vis[i]) { ++num; e1.erase({int(1e9), i}); vis[i] = 0; }
        else { e1.erase({a[i], i}); }
        if(vis[i+2]) { ++num; e2.erase({int(1e9), i+2}); vis[i+2] = 0; }
        else { e2.erase({a[i+2], i+2}); }
        e1.insert({a[i+2], i+2});
        e2.insert({a[i], i});
        while(num) {
            auto k1 = *e1.begin();
            auto k2 = *e2.begin();
            if(k1.first < k2.first*2) {
                if(k1.first == 1e9) { break; }
                vis[k1.second] = 1;
                e1.insert({int(1e9), k1.second});
                e1.erase(e1.begin());
                --num;
            }
            else {
                if(k2.first == 1e9) { break; }
                vis[k2.second] = 1;
                e2.insert({int(1e9), k2.second});
                e2.erase(e2.begin());
                --num;
            }
            ans = max(ans, min(e1.begin()->first, e2.begin()->first*2));
        }
    }
    cout << ans << '\n';
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