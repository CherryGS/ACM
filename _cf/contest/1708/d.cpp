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
int a[100500];

void solve(cint T) {
    bool flag = false;
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int lst = 1;
    for(int i=n; i>1; i--) {
        lst = max(1, lst - 1);
        for(int j=lst; j<i; j++) {
            a[j] = a[j+1] - a[j];
        }
        sort(a+lst, a+i);
        for(int j=lst; j<i; j++) {
            if(a[j] != 0 && j != i-1) { lst = j; break; }
            else if(j == i-1) { a[1] = a[j]; flag = true; break; }
        }
        if(flag == true) { break; }
    }
    cout << a[1] << '\n';
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