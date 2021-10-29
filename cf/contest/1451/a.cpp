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

int t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n==1) cout << 0 << endl;
        else if(n==2) cout << 1 << endl;
        else if(n==3) cout << 2 << endl;
        else if(!(n%2)) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}