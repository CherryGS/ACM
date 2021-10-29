#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int r[100100];

int main() {
    r[1] = 1;
    r[2] = 1;
    int i = 3;
    while(r[i-1] <= 2e5) {
        r[i] = r[i-1] + r[i-2];
        cout << r[i] << ' ' << i << endl;
        ++i; 
    }
    cout << i << endl;
    return 0;
}