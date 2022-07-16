#include <bits/stdc++.h>

using namespace std;

double dp[1001000];
double sum[1001000];

int main() {
    int n = 1000000;
    dp[1] = 0;
    for(int i=2; i<=n; i++) {
        double tmp = sum[i-1];
        dp[i] = tmp / (i-1) + (1.0*i) / (i-1);
        sum[i] = sum[i-1] + dp[i];
    }
    for(int i=1; i<=n; i++) {
        printf("%.9f\n",dp[i]);
    }
    cout << endl;
}