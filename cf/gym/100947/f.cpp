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

int t, n, w, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> w >> b;
        if(abs(w-b) & 1) cout << "Mikael" << endl;
        else cout << "Steven" << endl;
    }
    return 0;
}