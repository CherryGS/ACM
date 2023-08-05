#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int t, n;
int f[2000100];
queue<int> zero, one;

int main() {
    cin >> t ;
    while(t--) {
        while(!zero.empty()) {zero.pop();}
        while(!one.empty()) {one.pop();}
        char a;
        int num = 1;
        int znum = 0, onum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            if(a == '0') {
                znum++;
                if(!onum) {
                    f[i] = num;
                    zero.push(num++);
                } else {
                    onum--;
                    int tmp = one.front();
                    f[i] = tmp;
                    one.pop();
                    zero.push(tmp);
                }
            } else {
                onum++;
                if(!znum) {
                    f[i] = num;
                    one.push(num++);
                } else {
                    znum--;
                    int tmp = zero.front();
                    f[i] = tmp;
                    zero.pop();
                    one.push(tmp);
                }
            }
        }
        cout << num - 1 << endl;
        for(int i = 1; i <= n; i++) cout << f[i] << ' ';
        cout << endl;
    }
    return 0;
}