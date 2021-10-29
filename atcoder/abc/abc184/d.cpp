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

int a, b, c;
double dp[101][101][101];
double ans=0.0;

double dfs(cint x, cint y, cint z) {
    if(x==100||y==100||z==100) return 0;
    if(dp[x][y][z]) return dp[x][y][z];
    double ans=0.0;
    ans += (dfs(x+1, y, z)+1.0) * ((double)x/(double)(x+y+z));
    ans += (dfs(x, y+1, z)+1.0) * ((double)y/(double)(x+y+z));
    ans += (dfs(x, y, z+1)+1.0) * ((double)z/(double)(x+y+z));
    dp[x][y][z] = ans;
    return ans;
}

int main() {
    cin >> a >> b >> c;
    printf("%.9f", dfs(a,b,c));
    return 0;
}