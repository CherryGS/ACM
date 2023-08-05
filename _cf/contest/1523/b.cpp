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
int a[1010];

void change(cint x, cint y) {
    cout << 1 << ' ' << x << ' ' << y << endl;
    a[x] += a[y];
    cout << 2 << ' ' << x << ' ' << y << endl;
    a[y] -= a[x];
    cout << 1 << ' ' << x << ' ' << y << endl;
    a[x] += a[y];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << n*3 << endl;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i+=2) {
            change(i, i+1);
            change(i, i+1);
        }
        // for(int i=1; i<=n; i++) cout << a[i] << ' ';
        // cout << endl;
    }
    return 0;
}