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

int vis[5005];

int main() {
    int t;
    cin >> t;
    int n, m;
    vis[0] = 0;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<min(n, m); i++) {
            bool flag = 1;
            for(int j=i-1; j && flag; j--) {
                for(int k=1; j*k <= max(n, m); k++) {
                    if(vis[i-j] && vis[i-j]+j*k <= max(n, m)) {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) vis
        }
    }
    return 0;
}