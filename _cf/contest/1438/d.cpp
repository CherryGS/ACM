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

int n;
int a[100100];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cout << (n-2) - (n&1);
    for(int i=1; i<=n-3; i+=2) {
        cout << i << ' ' << i+1 << ' ' << i+2 << endl;
        cout << i << ' ' << i+1 << ' ' << n << endl;
    }
    if(n&1) {
        cout << 
    }
    return 0;
}