#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n, k;

int main() {
    cin >> n >> k;
    n -= k;
    cout << (n+k-2)/(k-1) + 1;
    return 0;
}