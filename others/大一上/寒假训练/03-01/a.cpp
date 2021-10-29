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

string a;
int n1, n2;

int main() {
    cin >> a;
    for(int i=0; i<a.length(); i++) {
        if(a[i] == '-') ++n1;
        else ++n2;
    }
    if(n2 && (n1%n2)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}