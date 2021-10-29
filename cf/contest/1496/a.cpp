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
int n, k;
string a;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> a;
        int le = a.length()-1;
        bool flag = 0;
        for(int i=0; i<k; i++)
            if(a[i] != a[le-i]) flag = 1;
        if(flag || n==k*2) cout << "NO" << endl;
        else cout << "YES" << endl;
    } 
    return 0;
}