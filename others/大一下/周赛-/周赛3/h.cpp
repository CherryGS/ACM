#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int bcj[1010000];
int n, m;

int num[2][1001001];
struct stu{
    int x, y;
    ll val;
    void init(cint r, cint s) {
        x = r; y = s;
        cin >> val;
    }
    bool operator < (const stu&a) const {
        return val > a.val;
    }
} a[1000100];

int find(cint x) {
    return bcj[x] == x? x: bcj[x] = find(bcj[x]);
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            bcj[(i-1)*m+j] = (i-1)*m+j;
            a[(i-1)*m+j].init(i,j);
        }
    }
    sort(a+1, a+1+n*m);
    for(int i=1; i<=n*m; i++) {
        stu r = a[i];
        cout << a[num[0][r.x]].val << ' ' << a[num[1][r.y]].val << ' ' << r.val << endl;
        if(num[0][r.x] && num[1][r.y])
        if((find(bcj[num[0][r.x]]) == find(bcj[num[1][r.y]]))) {
            cout << r.val << endl;
            return 0;
        }
        if(num[0][r.x]) bcj[find(bcj[i])] = find(bcj[num[0][r.x]]);
        if(num[1][r.y]) bcj[find(bcj[i])] = find(bcj[num[1][r.y]]);
        num[0][r.x] = i;
        num[1][r.y] = i;
    }
    
    return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9

4 4
1 3 1 1
3 2 2 1
1 1 1 3
1 3 1 2
*/