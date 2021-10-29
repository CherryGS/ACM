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
int q[100100], cnt;

void sol(int x) {
    if(x < 10) {
        q[++cnt] = x;
    } else {
        q[++cnt] = x/10;
        q[++cnt] = x%10;
    }
}

int main() {
    cin >> q[1] >> q[2] >> n;
    cnt = 2;
    int r = 1;
    while(cnt < n) {
        int x = q[r] * q[r+1];  
        sol(x);
        ++r;
    }
    for(int i=1; i<=n; i++) {
        cout << q[i];
        if(i!=n) cout << ' ';
    }
    cout << endl;
    return 0;
}