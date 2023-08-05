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
ll l, r;

int main() {
    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(l*2 > r) {
            cout << r%l << endl;
        } else {
            cout << (r+1)/2-1 << endl;
        }
    }
    return 0;
}