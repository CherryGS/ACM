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
int k;

bool query(cint x) {
    cout << x << endl;
    cout.flush();
    int tmp;
    cin >> tmp;
    return tmp;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(query(0)) continue;
        for(int i=1; i<n; i++)
            if(query(i^(i-1))) { break; }
    }
    return 0;
}