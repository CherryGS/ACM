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
int n;
int a[100100];

bool check(int x, int y) {
    return (x&1) == (y&1);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        int st = 0;
        a[0] = inf_int;
        for(int i=1; i<=n; i++)
            if(a[i] < a[st]) st = i;
        cout << n-1 << endl;
        for(int i=st-1; i>0; i--) {
            // a[i] = a[st]+st-i;
            cout << st << ' ' << i << ' ' << a[st] << ' ' << a[st]+st-i << endl;
        }
        for(int i=st+1; i<=n; i++) {
            // a[i] = a[st]-st+i;
            cout << st << ' ' << i << ' ' << a[st] << ' ' << a[st]-st+i << endl;
        }
        // for(int i=1; i<=n; i++) {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}