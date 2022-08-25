#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ull n;

ll check(ull m) {
    int num = 0;
    while(m%10 == 5) {
        m /= 5;
        ++num;
    }
    if(m != 1) return 0;
    else return num;
}

int main() {
    cin >> n;
    ull k = 3;
    for(ll i = 1; k < n; i++) {
        ll t = check(n-k);
        if(t) {
            cout << i << ' ' << t << endl;
            return 0;
        }
        k *= 3;
    }
    cout << -1 << endl;
    return 0;
}