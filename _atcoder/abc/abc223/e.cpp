#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll x, y, a, b, c;

bool sol() {
    if((a+y-1)/y+(b+y-1)/y+(c+y-1)/y <= x) return 1;
    int r = y-(a+x-1)/x;
    if((b+r-1)/r+(c+r-1)/r <= x) return 1;
    r = y-(b+x-1)/x;
    if((a+r-1)/r + (c+r-1)/r <= x) return 1;
    r = y-(c+x-1)/x;
    if((b+r-1)/r + (a+r-1)/r <= x) return 1;
    return 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x >> y >> a >> b >> c;
    if(x*y < a+b+c) cout << "No" << endl;
    else {
        if(sol()) cout << "Yes" << endl;
        else {
            swap(x, y);
            if(sol()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}