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

ll x, y;
vector<int> ans;
void sol(cint x, cint y) {
    if(y == 0) return;
    ans.push_back(x/y);
    if(x == 1) { ans.push_back(y); return; }
    sol(y, x%y);
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ans.clear();
        cin >> x >> y;
        sol(x, y);
        cout << ans.size()-1 << ' ';
        for(int i: ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}