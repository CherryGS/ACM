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

bool vis[101];
string s[100];

bool solve(cint T) {
    int n;
    cin >> n;
    string a;
    bool flag = true;
    for(int i=1; i<=n*2; i++) { vis[i] = 0; }
    for(int i=1; i<=n*2-2; i++) {
        cin >> a;
        int l = a.length();
        if(vis[l] == 1) {
            for(int j=0; j<l; j++) {
                if(a[j] != s[l][l-1-j]) { flag = false; }
            }
        }
        else {
            s[l] = a;
            vis[l] = 1;
        }
    }
    if(flag) { cout << "YES\n"; }
    else { cout << "NO\n"; }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}