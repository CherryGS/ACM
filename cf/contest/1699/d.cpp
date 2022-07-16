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
int a[5005];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        map<int, int> e;
        int now = 0;
        a[n+1] = i;
        for(int j=1; j<=n+1; j++) {
            if(a[j] != i) { e[a[j]]++; }
            else {
                int sum = 0;
                int mx = 0, id;
                for(auto &k: e) {
                    sum += k.second;
                    if(k.second > mx) {
                        mx = k.second;
                        id = k.first;
                    }
                }
                int d = mx * 2 - sum;
                if(d <= 0) {
                    if(sum % 2 == 0) { ++now; }
                    e.clear();
                }
                else {
                    e.clear();
                    if(d > 1) {
                        e[id] = d-1;
                    }
                }
            }
        }
        int sum = 1;
        for(auto &k: e) { sum += k.second; }
        cout << now << ' ' << i << ' ' << sum << endl;
        ans = max(ans, now-sum);
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