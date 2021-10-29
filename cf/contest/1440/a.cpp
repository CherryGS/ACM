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

int t, n, c0, c1, h;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> c0 >> c1 >> h;
        cin >> s;
        int n1=0, n2=0;
        c0 = min(c0, c1+h);
        c1 = min(c1, c0+h);
        int ans=0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') ans += c0;
            else ans += c1;
        }
        cout << ans << endl;
    }
    return 0;
}