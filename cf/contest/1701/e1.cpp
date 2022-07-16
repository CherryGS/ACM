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

int n, m;
bool vis[5005];
char s[5005], t[5005];

void solve(cint T) {
    cin >> n >> m;
    cin >> s;
    cin >> t;
    int l1 = strlen(s);
    int l2 = strlen(t);
    if(l1 < l2) { cout << -1 << '\n'; return; }
    bool flag = false;
    int ans = inf_int;
    for(int l=0; l<l1; l++) {
        for(int i=0; i<=l1; i++) { vis[i] = 0; }
        for(int j=0, k=l; j<l2; j++) {
            if(k >= l1) {
                flag = true;
                break;
            }
            for(int i=k; i<l1; i++) {
                if(t[j] == s[i]) {
                    // cout << j << ' ' << i << endl;
                    k = i+1;
                    vis[i] = 1;
                    break;
                }
                else if(i == l1-1) {
                    flag = true;
                    break;
                }
            }
        }
        if(l == 0 && flag == true) { cout << -1 << '\n'; return; }
        else if(l != 0 && flag == true) { break; }
        vector<int> q;
        for(int i=0; i<l1; i++) {
            if(vis[i] == 0) {
                q.push_back(i);
            }
        }
        if(q.size() == 0) { cout << 0 << '\n'; return; }
        ans = min(l1 - q[0], 1 + (q[q.size()-1]+1) + int(q.size()));
        // cout << ans << endl;
        for(int i=1; i<q.size(); i++) {
            ans = min(ans, l1 - q[i] + 1 + (q[i-1]+1) + i);
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