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
int h, m;
int s1, s2;
int mp[10] = {
    0, 1, 5, -1, -1, 2, -1, -1, 8, -1
};

int g(int tar) {
    int ans = 0, x;
    for(int i=1; i<=2; i++){
        x = tar%10;
        tar/=10;
        if(mp[x] == -1) return -1;
        ans = ans*10 + mp[x];
    }
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        scanf("%d %d", &h, &m);
        scanf("%d:%d", &s1, &s2);
        while(g(s2) == -1 || g(s2) >= h) {
            ++s2;
            if(s2 >= m) {++s1, s2 = 0;}
        }
        if(s1 >= h) {s1 = 0;}
        while(g(s1) == -1 || g(s1) >= m) {
            s2 = 0;
            ++s1;
            if(s1 >= h) {s1 = 0;}
        }
        if(s1 < 10) cout << '0';
        cout << s1 << ':';
        if(s2 < 10) cout << '0';
        cout << s2 << endl;
    }
    return 0;
}