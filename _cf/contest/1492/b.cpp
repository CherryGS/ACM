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
int a[100100];
int q[100100], ed;

int main() {
    cin >> t;
    while(t--) {
        int st;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        st = a[1];
        ed = 1;
        q[1] = 1;
        for(int i=1; i<=n; i++) {
            if(a[i] > st) {
                q[++ed] = i;
                st = a[i];
            }
        }
        q[ed+1] = n+1;
        for(; ed; ed--) {
            for(int i = q[ed]; i < q[ed+1]; i++)
                cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}