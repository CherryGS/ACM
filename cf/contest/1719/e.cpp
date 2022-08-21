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

int k;
int c[101];
ll fib[51];

void init() {
    fib[1] = fib[2] = 1;
    for(int i=3; i<=50; i++) { fib[i] = fib[i-1] + fib[i-2]; }
    // cout << fib[50] << endl;
}

void solve(cint T) {
    cin >> k;
    for(int i=1; i<=k; i++) { cin >> c[i]; }
    ll num = 0, sum = 0;
    for(int i=1; i<=k; i++) {
        if(c[i]) {
            ++num;
            sum += c[i];
        }
    }
    int id = 0;
    for(int i=1; i<=48; i++) { if(fib[i+2]-1 == sum) { id = i; break; } }
    if(num > id) { cout << "NO" << '\n'; return; }
    priority_queue<pii> q;
    for(int i=1; i<=k; i++) { if(c[i]) { q.push({c[i], i}); } }
    int lst = 0;
    for(int i=id; i>=1; i--) {
        // cout << i << ' ' << q.size() << ' ' << q.top().first << endl;
        if(q.empty()) { cout << "NO\n"; return; }
        auto k = q.top();
        q.pop();
        if(k.second == lst) {
            if(q.empty()) { cout << "NO\n"; return; }
            auto r = q.top();
            q.pop();
            q.push(k);
            k = r;
        }
        lst = k.second;
        if(k.first >= fib[i]) {
            k.first -= fib[i];
            if(k.first > 0) { q.push({k.first, k.second}); }
        }
        else { cout << "NO\n"; return; }
    }
    cout << "YES\n";
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