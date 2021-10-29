#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

struct stu {
    int x;
    int num;
    bool operator < (const stu&a) const {
        return x < a.x;
    }
} a[100100];

int solve(cint x, cint y) {
    int m = min(x, y);
    return ((m+1)*m)>>1;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].x;
    sort(a+1, a+1+n);
    int len = 0;
    for(int i = 1; i <= n; i++) 
        a[i].num += solve(i, n-i+1) + solve(n-i+1, i-1), len += a[i].num;
    len = (len+1)>>1;
    for(int i = 1; i <= n+1; i++)
        if(len > 0) {
            len -= a[i].num;
            cout << i << ' ' << len << endl;
        } else {
            cout << a[i-1].x << endl;
            break;
        }
    return 0;
}