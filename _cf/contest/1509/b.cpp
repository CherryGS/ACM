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
char a[100100];

int main() {
    cin >> t;
    while(t--) {
        bool flag = 0;
        cin >> n >> a;
        int s = 0, a1 = 0;
        for(int i=0; i<n && !flag; i++) {
            if(a[i] == 'T') ++ s, ++ a1;
            else -- s;
            if(s < 0) flag = 1;
        }
        if(a1&1 || a1+a1/2 != n) flag = 1;
        s = 0;
        for(int i=n-1; i>=0 && ! flag; i--) {
            if(a[i] == 'T') ++ s;
            else -- s;
            if(s < 0) flag = 1;
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}