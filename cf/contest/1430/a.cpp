#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        bool st = 1;
        cin >> n;
        for(int i = 0; i*7 <= n && st; i++) {
            int m = i*7;
            for(int j = 0; j * 5 + m <= n && st; j++)
                if(!((n-m-j*5)%3)) {
                    cout << ((n-m-j*5)/3) << ' ' << j << ' ' << i << endl;
                    st = 0;
                    break;
                }
        }
        if(st) cout << -1 << endl;
    }
    return 0;
}