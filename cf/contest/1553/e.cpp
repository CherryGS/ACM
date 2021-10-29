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

int t, n, m;
int p[300300];
int bcj[300300];
int dt[300300];
int fd(cint x) { return bcj[x] == x ? x : bcj[x]=fd(bcj[x]); }

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) scanf("%d", &p[i]);
        for(int i=1; i<=n; i++) bcj[i] = i;
        for(int i=1; i<=n; i++) dt[i] = 0;
        for(int i=1; i<=n; i++) {
            if(fd(i) != fd[p[i]]) {
                bcj[fd(p[i])] = i;
            } 
            dt[(i-p[i]+n)%n]++;
        }
        for(int i=1; i<)
    }
    return 0;
}