#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;



int main() {
    int t;
    cin >> t;
    srand(t);
    int n = rand() % 11, m = rand() % 11;
    cout << n << ' ' << m << endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << abs(abs(rand()*1001ll) % (ll)(1000)) << ' ';
        }
        cout << endl;
    }
    return 0;
}