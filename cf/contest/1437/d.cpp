#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int q[100100], cnt;

int main() {
    cin >> t;
    while(t--) {
        cnt=0;
        cin >> n;
        int a=1, b=0, tmp=0;
        for(int i=1; i<=n; i++) {
            cin >> b;
            if(a>=b) {
                q[++cnt] = tmp;
                tmp=0;
            }
            cout << a << ' ' << b << endl;
            ++tmp;
            a = b;
        }
        int num=1, st=2;
        int sum = q[1];
        while(st <= cnt) {
            int t=sum;
            sum=0;
            while(st <= cnt && t) {sum += q[st++]; --t;}
            ++num;
        }
        cout << num << endl;

    }
    return 0;
}