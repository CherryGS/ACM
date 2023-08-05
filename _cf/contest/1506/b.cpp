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

int t, n, k;
char a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> a;
        int num = 0, la = 0, la1 = 0;
        for(int i=0; i<n; i++)
            if(a[i] == '*') {
                a[i] = 'x';
                la = i;
                ++num;
                break;
            }
        for(int i = la+1; i<n; i++) {
            if(a[i] == '*') {
                if(i - la > k) {
                    ++num;
                    la = la1;
                }
                la1 = i;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(a[i] == '*') {
                ++num;
                break;
            }
            if(a[i] == 'x') break;
        }
        cout << num << endl;
    }
    return 0;
}