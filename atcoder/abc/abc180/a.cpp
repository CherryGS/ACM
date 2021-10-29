#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)


int main() {
    int n, a;
    cin >> n;
    cin >> a;
    n -= a;
    cin >> a;
    n += a;
    cout << n;    
    return 0;
}