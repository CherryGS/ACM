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

int mp[100100];

void init() {
    for(int i=2; i<=100000; i++) {
        if(!mp[i]) {
            mp[i] = i;
            for(int j=i*2; j<=100000; j+=i)
                mp[j] = i;
        }
    }
}

int n;
int a;

int main() {
    init();
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a;
        if(mp[a] == a) cout << a << ' ';
    }
    cout << endl;
    return 0;
}