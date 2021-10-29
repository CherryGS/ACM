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

int n;
char a[300300];

int main() {
    cin >> n >> a;
    for(int i=0; i<n-1; i++)
        if(a[i] > a[i+1]) {
            cout << "YES" << endl << i+1 << ' ' << i+2 << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}