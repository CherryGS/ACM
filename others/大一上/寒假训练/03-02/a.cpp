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

int t;
int a, b, c, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> n;
        int r = (a+b+c+n);
        if(r%3) {
            cout << "NO" << endl;
        } else if(a <= r/3 && b <= r/3 && c <= r/3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}