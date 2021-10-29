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

int n;
int a[1010];
int num[10010];

int main() {
    cin >> n;
    int a;
    for(int i=1; i<=n; i++) {
        cin >> a;
        for(int i=2; i<=a; i++)
            if(!(a%i)) {
                ++num[i];
                while(!(a%i)) a /= i;
            }
    }
    int key, s=0;
    for(int i=2; i<=1000; i++)
        if(num[i] > s) {
            key=i;
            s=num[i];
        }
    cout << key;
    return 0;
}