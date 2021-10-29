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

ll n, p, k;
ll a[300100];

int main() {
    cin >> p >> k;
    // cin >> n >> p >> k;
    // for(int i=1; i<=n; i++) cin >> a[i];
    for(ll i=0; i<p; i++) {
        for(ll j=i; j<p; j++) {
            if((i+j)*(i*i+j+j)%p == k) {
                cout << i << "------" << j << endl;
            }
        }
    }
    return 0;
}