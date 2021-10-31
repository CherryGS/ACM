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
int s[100100];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x[2], y[2];
    for(int i=1; i<=n; i++) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        s[min(x[0], x[1])]++;
        s[max(x[0], x[1])]--;
    }
    int ans = 0;
    int r = 0;
    for(int i=1; i<=100000; i++) {
        r += s[i];
        if(r != 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}