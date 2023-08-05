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
int ans[10010];
int pre[10010];
bool flag;
int cnt, cnt1;

int query(int i, int j, int x, int st) {
    cout << "? " << st << ' ' << i << ' ' << j << ' ' << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void pr1(cint x) {
    ans[x] = 1;
    for(int i=1; i<=n; i++)
        if(i != x) {
            ans[i] = query(x, i, n-1, 1);
        }
    flag = 1;
}


int main() {
    cin >> t;
    while(t--) {
        flag = 0;
        cin >> n;
        if(n&1 && query(n, 1, 1, 2) == 1) pr1(n);
        else if(!flag) {
            for(int i=2; i<=n; i+=2) {
                int x = query(i, i-1, 1, 2);
                if(x == 1) {
                    pr1(i);
                    break;
                }
                if(x == 2) {
                    x = query(i-1, i, 1, 2);
                    if(x == 1) {
                        pr1(i-1);
                        break;
                    }
                }
            }
        }
        cout << "!" << endl;
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
/*
1
4
3 1 4 2
*/