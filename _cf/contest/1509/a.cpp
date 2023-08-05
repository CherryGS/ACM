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
int q[2020][2], cnt[2];

int main() {
    cin >> t;
    while(t--) {
        int r;
        cnt[0] = cnt[1] = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> r;
            if(r&1) q[++cnt[0]][0] = r;
            else q[++cnt[1]][1] = r;
        }
        while(cnt[0]) { cout << q[cnt[0]--][0] << ' ';}
        while(cnt[1]) { cout << q[cnt[1]--][1] << ' ';}
        cout << endl;
    }
    return 0;
}