#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll c, d;

int main() {
    cin >> t;
    while(t--) {
        cin >> c >> d;
        if((c+d)&1) cout << -1 << endl;
        else {
            if(c == 0 && d == 0) cout << 0 << endl;
            else if(c == d) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}