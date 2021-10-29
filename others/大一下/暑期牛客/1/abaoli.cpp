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
#define LL long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int pre[5050][2], cnt;
int al[2000], be[2000];

int main() {
    freopen("1.out", "w", stdout);
    const int n = 5000;
    pre[++cnt][0] = 0;
    pre[cnt][1] = 0;
    for(int i=2; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            bool flag = 1;
            for(int k=1; k<=cnt && flag; k++) {
                int r1 = i-pre[k][0];
                int r2 = j-pre[k][1];
                if(!(r1*r2)) {
                    flag = 0;
                    break;
                }
                if(r1 > 0 && r2 > 0) {
                    if(!(r1%r2) || !(r2%r1)) {
                        flag = 0;
                        break;
                    }
                }
                r1 = i-pre[k][1];
                r2 = j-pre[k][0];
                if(!(r1*r2)) {
                    flag = 0;
                    break;
                }
                if(r1 > 0 && r2 > 0) {
                    if(!(r1%r2) || !(r2%r1)) {flag = 0; break;}
                }
            }
            if(flag) {
                pre[++cnt][0] = i;
                pre[cnt][1] = j;
                al[cnt] = i;
                be[cnt] = j;
            }
        }
    }
    for (LL i = 1;i <= cnt; ++ i){
        printf("%d,", al[i]);
    }
    cout << endl;
    for (LL i = 1;i <= cnt; ++ i){
        printf("%d,", be[i]);
    }
    cout << endl;
    cout << cnt;
    return 0;
}