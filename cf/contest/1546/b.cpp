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
int n, m;
int num[100100][27];
char s[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(num, 0, sizeof num);
        for(int i=1; i<=n; i++) {
            cin >> s;
            for(int j=1; j<=m; j++)
                ++num[j][s[j-1]-'a'];
        }
        for(int i=1; i<n; i++) {
            cin >> s;
            for(int j=1; j<=m; j++)
                --num[j][s[j-1]-'a'];
        }
        for(int i=1; i<=m; i++)
            for(int j=0; j<27; j++)
                if(num[i][j]) putchar('a'+j);
        cout << endl;
        cout.flush();
    }
    return 0;
}