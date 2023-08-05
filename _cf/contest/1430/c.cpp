#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        int k = n;
        if(n == 2) cout << 2 << endl;
        else cout << ((n+1) >> 1) << endl;
        for(int i = n-1; i >= 1; i--) {
            cout << i << ' ' << k << endl;
            k = (k+1+i) >> 1;
        }
    }
    return 0;
}