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

int main() {
    cin >> n;
    if(n==1) cout << -1 << endl;
    else {
        if(n&1) {
            n-=3;
            for(int i=1; i<=n; i+=2) {
                cout << i+1 << ' ' << i << ' ';
            }
            n+=3;
            cout << n-1 << ' ' << n << ' ' << n-2 << endl;
        } else {
            for(int i=1; i<=n; i+=2) {
                cout << i+1 << ' ' << i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}