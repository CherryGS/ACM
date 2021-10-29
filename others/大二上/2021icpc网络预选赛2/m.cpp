#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL sig[100], a[100], b[100], c[100], d[100], e[100];
int main (){
    LL n;
    scanf("%lld", &n);
    for (LL i = 0; i < n; ++ i)
        scanf("%lld", &sig[i]);
    sig[n] = 1;
    for (LL i = 0; i < n; ++ i)
        scanf("%lld", &a[i]);
    for (LL i = 0; i < n; ++ i)
        scanf("%lld", &b[i]);
    for (LL i = 0; i < n; ++ i){
        c[i] += (a[i] + b[i]);
        LL p = (c[i] % 2 + 2 ) % 2;
        LL d = (c[i] - p) / 2;
        c[i] = p;
        if (sig[i] != sig[i + 1]){
            c[i + 1] = -d;
        }
        else{
            c[i + 1] = d;
        }
    }
    // for (LL i = 0; i <= n; ++ i){
    //     c[i] = c[i] * sig[i];
    // }
    // for (LL i = n; i >= 0; --i){
    //     if (c[i] == -1){
    //         for (LL j = 1; )
    //     }
    // }

    for (LL i = 0; i < n - 1; ++ i){
        printf("%lld ", c[i]);
    }
    printf("%lld", c[n - 1]);
}