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
int a[101], b[101];
int tm[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i] >> b[i];
        }
        for(int i=1; i<=n; i++) cin >> tm[i];
        int now = 0;
        for(int i=1; i<=n; i++) {
            now += tm[i];
            if(tm < (b[i]-a[i]+1)/2) tm = (b[i]-a[i]+1)/2;
            
        }
    }
    return 0;
}