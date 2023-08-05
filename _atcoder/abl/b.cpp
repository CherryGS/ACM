#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&


int main() {
    ull a, b;
    ull c, d;
    cin >> a >> b >> c >> d;
    if(d < a) {cout << "No"; return 0;}
    if(c > b) {cout << "No"; return 0;}
    cout << "Yes";
    return 0;
}