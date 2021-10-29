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

int n, s;
int deg[100100];

int main() {
    cin >> n >> s;
    int a, b;
    for(int i=1; i<n; i++) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(deg[i] == 1) ++ ans;
    printf("%.9f\n", (double)s/ans*2.0);
    return 0;
}