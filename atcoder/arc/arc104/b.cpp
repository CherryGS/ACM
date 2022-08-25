#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long
#define ull unsigned long long
#define cint const int&

using namespace std;

int num[5001][5];
// A G C T

int m(int i, int j, int a) {return num[i][a] - num[j][a];}

int main() {
    int n;
    char a;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a == 'A') num[i][1] += 1;
        else if(a == 'G') num[i][2] += 1;
        else if(a == 'C') num[i][3] += 1;
        else num[i][4] += 1;
        for(int j = 1; j <= 4; j++) num[i][j] += num[i-1][j];
    }
    // for(int i = 1; i <= n; i++)
    //     cout << num[i][1] << ' ' << num[i][2] << " " << num[i][3] << ' ' << num[i][4] << endl;
    int ans = 0;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++)
            if(m(i, j, 1) == m(i, j, 4))
                if(m(i, j, 2) == m(i, j, 3)) {
                    ans++;
                    // cout << i << ' ' << j << endl;
                }

    cout << ans;
    return 0;
}