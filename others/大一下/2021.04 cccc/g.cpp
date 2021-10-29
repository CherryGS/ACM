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
int mn = inf_int, mnn;
int mx, mxn;

int main() {
    cin >> n;
    int x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(x < mn) { mn = x; mnn = 1; }
        else if(x == mn) { ++ mnn; }
        if(x > mx) { mx = x; mxn = 1; }
        else if(x == mx) { ++ mxn; }
    }
    cout << mn << ' ' << mnn << endl;
    cout << mx << ' ' << mxn << endl;
    return 0;
}