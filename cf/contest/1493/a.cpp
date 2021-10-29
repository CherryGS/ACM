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

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << max(0, n-k) + k/2 << endl;
        for(int i=k+1; i<=n; i++) cout << i << ' ';
        for(int i=k-1; i>=(k+1)/2; i--) cout << i << ' ';
        cout << endl;
    }
    return 0;
}