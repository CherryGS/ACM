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
bool ok1[2002][2002];
bool ok2[2002][2002];
int mp[2002][2002];


void solve(cint T) {
    cin >> n >> k;
    int loc[2] = {0, 0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> mp[i][j];
            if(mp[i][j] > mp[loc[0]][loc[1]]) { loc[0] = i, loc[1] = j; }
        }
    }
    int nl[2] = {0, 0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(abs(i-loc[0]) + abs(j-loc[1]) <= k) {
                ok1[i][j] = 1;
                if(mp[i][j] > mp[nl[0]][nl[1]] && (i != loc[0] || j != loc[1])) { nl[0] = i, nl[1] = j; }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(abs(i-nl[0]) + abs(j-nl[1]) <= k) {
                ok2[i][j] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(ok1[i][j] && ok2[i][j]) { cout << 'M'; }
            else { cout << 'G'; }
        }
        cout << '\n';
    }
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