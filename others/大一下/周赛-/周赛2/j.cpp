#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int a[4];

int main() {
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+1+3);
    for(int i=1; i<=3; i++) cout << a[i] << ' ';
    return 0;
}