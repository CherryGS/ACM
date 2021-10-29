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

int n, k;
int a[200200];

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int num = 0, l = 1;
    for(int i=1; i<=n; i++)
        if(a[i] > a[l]) {
            // cout << i << endl;
            while(l < i) {
                if(a[l]+k >= a[i]) ++ num;
                ++l;
            }
        }
    cout << n - num << endl;
    return 0;
}