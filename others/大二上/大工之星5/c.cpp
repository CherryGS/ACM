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
char s[1001];
bool vis[1001];
string r = "acyclic";

bool check(char ss, int i) {
    if(ss == r[i]) return true;
    if(char(r[i] - 'a' + 'A') == ss) return true;
    // cout << char(ss - 'a' + 'A') << ' ' << r[i] << endl;
    return false;
}

void solve(cint T) {
    cin >> s;
    n = strlen(s);
    // cout << check(s[1], 0) << endl;
    for(int i=0; i<n-6; i++) {
        for(int j=0; j<7; j++) {
            // cout << j << endl;
            if(!check(s[i+j], j)) break;
            if(j == 6) {
                for(int k=0; k<=6; k++) vis[i+k] = 1;
                i += 5;
            }
        }
    }
    for(int i=0; i<n; i++) if(!vis[i]) cout << s[i];
    cout << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}