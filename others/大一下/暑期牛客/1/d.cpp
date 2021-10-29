#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
char arr[3000][3000], al[3000];
LL n, m, ans = 0;
int main(){
    cin >> n >> m;
    for (LL i = 0; i < n; ++ i){
        LL cnt = 0;
        scanf("%s", arr[i]);
        for (LL j = 0; j < n; ++ j){
            if (arr[i][j] == '1'){
                ans += (cnt >= m ? cnt - m + 1 : 0);
                cnt = 0;
            }
            else{
                ++ cnt;
            }
        }
        ans += (cnt >= m ? cnt - m + 1 : 0);
        cnt = 0;
    }
    scanf("%s", al);
    cout << ans;
    return 0;
}