#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int a, b, n;

int main() {
    cin >> a >> b >> n;
    int k = b - a;
    cout << ((n-b+k-1)/k<<1)+1;
    return 0;
}