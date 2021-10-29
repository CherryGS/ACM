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

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int mn = inf_int, loc_mn;
        int mx = 0, loc_mx;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            if(a[i] < mn) {
                mn = a[i];
                loc_mn = i;
            }
            if(a[i] > mx) {
                mx = a[i];
                loc_mx = i;
            }
        }
        // cout << min(max(loc_mn, loc_mx), max(n-loc_mn, n-loc_mx)+1) << "---" << endl;
        cout << min( min(max(loc_mn, loc_mx), max(n-loc_mn, n-loc_mx)+1) , min(loc_mn, loc_mx)+min(n-loc_mn, n-loc_mx)+1) << endl;
    }
    return 0;
}