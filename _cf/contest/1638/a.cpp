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
int a[1001];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int l = -1;
    for(int i=1; i<=n; i++) if(a[i] != i) { l = i; break; }
    int r = 0;
    for(int i=1; i<=n; i++) if(a[i] == l) { r = i; break; }
    if(l != -1) {
        while(l < r) {
            swap(a[l], a[r]);
            ++l;
            --r;
        }
    }
    for(int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << endl;
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