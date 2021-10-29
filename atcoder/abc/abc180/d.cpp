#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ull x, y, a, b;

int main() {
    cin >> x >> y >> a >> b;
    ull ans = 0;
    while((a-1) * x < b && x < y) {x *= a; ans++;}
    if(x < y) {
        ans += (y-x-1)/b;
    } else --ans;
    cout << ans;
    return 0;
}