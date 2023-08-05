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
int n, k;
int a[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> a[i];
        bool flag = 0;
        for(int i=2; i<=n; i++) if(a[i] != a[i-1]) flag = 1;
        if(!flag) {
            for(int i=1; i<=n; i++) cout << a[i] << ' ';
            cout << endl; 
        } else {
            for(int i=1; i<n && k; i++) if(a[i] > 0) {
                if(abs(a[i] - a[n]) & 1 || a[i] < a[n]) {
                    if(k > a[i]) {
                        a[n] += a[i];
                        k -= a[i];
                        a[i] = 0;
                    } else {
                        a[i] -= k;
                        a[n] += k;
                        k = 0;
                        break;
                    }
                } else {
                    int dt = abs(a[i] - a[n]) / 2;
                }
            }
            for(int i=1; i<=n; i++) cout << a[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}