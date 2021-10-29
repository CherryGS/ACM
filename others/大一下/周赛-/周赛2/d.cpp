#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, k;
int m1, m2;
int i1, i2;
int a;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        m1 = 0; m2 = 0;
        cin >> n >> k;
        if(n == k) {
            for(int i=1; i<=n; i++) {
                cin >> a;
                if(i&1) m1 = max(m1, a);
                else m2 = max(m2, a);
            }
        } else {
            for(int i=1; i<=n; i++) {
                cin >> a;
                if(a > m1) {m2 = m1; m1 = a;}
                else m2 = max(m2, a);
            }
        }
        cout << min(m2, m1) << endl;
    }
    return 0;
}