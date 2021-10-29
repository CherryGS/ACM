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

int n;
int a[500500];
bool mp[500500];

bool check(cint x) {
    int r = 0;
    for(int i=0; i<x; i++) mp[i] = 0;
    for(int i=1; i<=n; i++) {
        r = a[i] % x;
        if(mp[r]) return 0;
        mp[r] = 1;
    }
    return 1;
}

int main() {
    cin >> n;
    int mx = 0;
    for(int i=1; i<=n; i++) { cin >> a[i]; mx = max(mx, a[i]); }
    for(int i=n; i<=n+500000/n*400; i++) {
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    for(int i=mx; i>=max(n+500000/n*400, mx-n/5000); i++) {
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}