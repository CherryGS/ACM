#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&


int main() {
    int ans = 50, a;
    for(int i = 1; i <= 7; i++) {cin >> a; ans += a;}
    cin >> a;
    if(a) ans += 5;
    cin >> a;
    if(a > ans) cout << "AFO";
    else cout << "AKIOI";
    return 0;
}