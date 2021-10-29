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

int n;
int a[1001];
bool mp[2000001];

int main() {
    int mx = 0;
    cin >> n;
    mp[0] = 1;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int j=mx; j>=0; j--)
            if(mp[j]) { mp[j+a[i]] = 1; mx = max(mx, j+a[i]); }
    }
    int id = 0;
    for(int i=1; i<11; i++) {
        for(int j=1; j<=n; j++)
            if(a[j]%(1<<i)) {
                id = j;
                break;
            }
        if(id) break;
    }
    if(mx&1 || !mp[mx/2]) cout << 0 << endl;
    else cout << 1 << endl << id << endl;
    return 0;
}