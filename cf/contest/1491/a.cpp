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

int n, q;
int zero, one;
bool a[100100];

int main() {
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(a[i]) ++ one;
        else ++ zero;
    }
    int t, r;
    for(int i=1; i<=q; i++) {
        cin >> t >> r;
        if(t == 1) {
            if(a[r]) {
                a[r] = 0;
                ++ zero;
                -- one;
            } else {
                a[r] = 1;
                ++ one;
                -- zero;
            }
        } else {
            if(one >= r) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}