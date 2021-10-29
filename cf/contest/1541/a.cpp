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
int a[1001];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) a[i] = i;
        if(n&1) {
            swap(a[n], a[n-1]);
        }
        for(int i=2; i<=n; i+=2)
            swap(a[i], a[i-1]);
        for(int i=1; i<=n; i++)
            cout << a[i] << ' ';
            cout << endl;
    }
    return 0;
}