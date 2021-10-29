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

int n, m;
int a[505], b[505];
int st[2][5050];

void sol() {
    for(int i=0; i<=a[1]-1; i++) st[0][i] = -1;
    for(int i=0; i<=b[1]-1; i++) st[1][i] = 1;
    for(int i=a[1]; i<=a[1]+b[1]-1; i++) st[0][i] = 1;
    for(int i=b[1]; i<=a[1]+b[1]-1; i++) st[1][i] = -1;
    for(int i=a[1]+b[1]; i<=n; i++) {
        for(int j=1; j<=m && a[j] <= i; j++) {
            if(st[1][i-a[j]] == 1) {
                st[0][i] = 1;
                break;
            }
        }
        if(st[0][i] != 1) st[0][i] = -1;
        for(int j=1; j<=m && b[j] <= i; j++) {
            if(st[0][i-b[j]] == -1) {
                st[1][i] = -1;
                break;
            }
        }
        if(st[1][i] != -1) st[1][i] = 1;
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
    sol();
    if(st[0][n] == 1) cout << "Long Long nb!" << endl;
    else cout << "Mao Mao nb!" << endl;
    return 0;
}