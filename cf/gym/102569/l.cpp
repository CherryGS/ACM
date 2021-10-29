#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define ull unsigned long long
using namespace std;

struct stu{
    ull arr;
    int num;
    bool operator < (stu a) const {
        return arr > a.arr;
    }
} nm[200200];

int main() {
    ios::sync_with_stdio(false);
    int n;
    ull ans = 0;
    ull t = 0, m = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nm[i].arr;
        nm[i].num = i;
    }
    sort(nm + 1, nm + 1 + n);
    for(int i = 1; i <= n; i++) 
        if(nm[i].arr > m) {
            ans += nm[i].arr - m;
            m++;
        }
    cout << ans;
    return 0;
}