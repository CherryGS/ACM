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

int main() {
    cin >> t;
    int x;
    while(t--) {
        int i, b=0;
        cin >> x;
        for(i=1; b<x; i++) {b+=i;}
        if(x == b) cout << i-1 << endl;
        else {
            if(b-x > 1) cout << i-1 << endl;
            else cout << i << endl;
        }
    }
    return 0;
}