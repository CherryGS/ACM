#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ll a[4];

int main() {
    int t;
    cin >> t;
    while(t--) {
        for(int i = 0; i < 4; i++) cin >> a[i];
        int k = 0;
        if(a[3]-a[1] && a[2]-a[0]) k = 2;
        cout << abs(a[3]-a[1]) + abs(a[2]-a[0]) + k << endl;
    }
    return 0;
}