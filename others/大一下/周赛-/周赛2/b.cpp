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

int t;
string a, b;

bool check() {
    int le = min(a.length(), b.length());
    for(int i=0; i<le; i++) {
        if(a[i] < b[i]) return 1;
        else if(a[i] > b[i]) return 0;
    }
    return a.length() < b.length();
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}