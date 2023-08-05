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

int t, n;
int k1, k2;
int w, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> k1 >> k2;
        cin >> w >> b;
        if(w*2 > (k1+k2) || b*2 > (2*n-k1-k2)) cout << "NO" << endl;
        else if(k1 == k2) cout << "YES" << endl;
        else {
            if((k1+k2)/2 >= w && (2*n-k1-k2)/2 >= b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}