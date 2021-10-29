#include <bits/stdc++.h>
using namespace std;
#define LL long long
int r, k;
LL a[300], b[30];
int main() {
    cin >> k >> r;
    LL inv = 256 / k;
    LL res = 256 % k;

    LL po = 0;
    for (LL i = 0; i < k; ++ i){
        b[i] = po;
        if (i < (k - res)){
            po += inv;
        }
        else{
            po += inv + 1;
        }
    }

    LL len = 512 / r;
    if (512 % r)
        len ++;

    if (b[r - 1] + len - 1 < 127){
        printf("-1");
    }
    else
        for (LL i = 0;i < k; ++ i){
            memset(a, 0, sizeof(a));
            for (LL k = 0; k < len; ++ k){
                a[(b[i] + k) % 256] = 1;
            };
            for (LL i = 0; i < 256; ++ i)
                printf("%lld", a[i]);
            if (i != k - 1)
                printf("\n");
        }
}