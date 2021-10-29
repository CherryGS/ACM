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

char a[1001];

int main() {
    cin >> a;
    for(int i=strlen(a); i; i--)
        cout << a[i-1];
    for(int i=1; i<=strlen(a); i++)
        cout << a[i-1];
        cout << endl;
    return 0;
}