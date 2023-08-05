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
int sum[100100];

struct qu {
    int id, i, k, ans;
};

void solve(cint T) {
    cin >> n >> q;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) { sum[i] = 0; }
    vector<qu> qe;
    int t1, t2, t3;
    for(int i=1; i<=q; i++) {
        cin >> t1 >> t2;
        t3 = 0;
        if(a[t1] == n && t2 >= n) { t3 = t2-n+1; }
        t2 = min(t2, n-1);
        qe.push_back({i, t1, t2, t3});
    }
    // cout << " --- " << endl;
    sort(qe.begin(), qe.end(), [](const qu&a, const qu&b) { return a.k < b.k; } );
    deque<int> r;
    for(int i=1; i<=n; i++) { r.push_back(i); }
    int l = 0;
    for(int i=1; i<n; i++) {
        auto k1 = r.front();
        r.pop_front();
        auto k2 = r.front();
        r.pop_front();
        // cout << k1 << ' ' << k2 << endl;
        if(a[k1] < a[k2]) { swap(k1, k2); }
        ++sum[k1];
        r.push_front(k1);
        r.push_back(k2);
        // cout << k1 << ' ' << k2 << ' ' << sum[k1] << ' ' << l << ' ' << qe[0].i << endl;
        while(l < q && qe[l].k == i) { 
            qe[l].ans += sum[qe[l].i]; 
            ++l; 
            // cout << l << ' ' << qe[l-1].ans << ' ' << qe[l-1].i << ' ' << k1 << ' ' << k2 << ' ' << sum[k1] << endl;
        }
        // cout << qe[0].k << ' ' << l << endl;
        // cout << qe[l-1].i << ' ' << sum[qe[l-1].i] << ' ' << qe[l-1].ans << ' ' << l-1 << endl;
    }
    sort(qe.begin(), qe.end(), [](const qu&a, const qu&b) { return a.id < b.id; } );
    for(int i=1; i<=q; i++) { cout << qe[i-1].ans << '\n'; }
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