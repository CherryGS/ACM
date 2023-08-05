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

int l, r;
int a[200200];
bool vis[200200];
int id[200200];

bool check(int x) {
    for(int i=l; i<=r; i++) { vis[i] = 0; }
    for(int i=0; i<=r-l; i++) {
        int k = a[i] ^ x;
        if(vis[k]) { return false; }
        else if(k < l || k > r) { return false; }
        else { vis[k] = 1; }
    }
    return true;
}

void solve(cint T) {
    cin >> l >> r;
    int sum = 0, sarr = 0;
    for(int i=0; i<=r-l; i++) { cin >> a[i]; }
    for(int i=0; i<=r-l; i++) { sarr ^= a[i]; }
    for(int i=l; i<=r; i++) { sum ^= i; }
    if((r-l+1)&1) {
        cout << (sarr ^ sum) << '\n';
        return ;
    }
    sum ^= r;
    for(int i=0; i<=r-l; i++) { id[i] = i; }
    shuffle(id, id + (r-l+1), rng);
    for(int k=0; k<=r-l; k++) {
        int i = id[k];
        int narr = sarr ^ a[i];
        int nx = narr ^ sum;
        if(check(nx)) {
            cout << nx << '\n';
            return;
        }
    }
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