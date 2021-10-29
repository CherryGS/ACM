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

int pri[101000], cnt;
bool mp[101000];

void init() {
    pri[++cnt] = 2;
    for(int i=3; i<=100000; i+=2)
        if(!mp[i]) {
            for(int j=2; i*j<=100000; j++)
                mp[i*j] = 1;
        }
    for(int i=3; i<=100000; i+=2) {
        if(!mp[i]) pri[++cnt] = i;
    }
}

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> n;
        int nn = n;
        int num = 0;
        int a = 0, b = 0;
        for(int i=1; i<=cnt && pri[i] < nn; i++) {
            while(!(n%pri[i])) {
                ++ num;
                b = a;
                a = pri[i];
                n /= pri[i];
            }
        }
        if(num == 0) {
            cout << 0 << endl;
        } else if(num > 2) {
            cout << a*b << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}