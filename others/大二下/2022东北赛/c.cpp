#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int rdi(){
   int s=0;
   int ff=1;
   char w=getchar();
   while(!isdigit(w)) 
    ff^=w=='-',w=getchar();
    while(isdigit(w))
        s=s*10+w-'0',w=getchar();
    return ff?s:-s;
}
ll rdl(){
   ll s=0;
   int ff=1;
   char w=getchar();
   while(!isdigit(w)) 
    ff^=w=='-',w=getchar();
    while(isdigit(w))
        s=s*10+w-'0',w=getchar();
    return ff?s:-s;
}

int m, q;

int main() {
    int T = rdi();
    while(T--) {
        int m = rdi(), k = rdi();
        int r = 0;
        while((1ll<<r) <= m) { ++r; }
        --r;
        ll ans = 0;
        for(int i=r; i>=1; i--) {
            int r = ((m>>(i-1))-(m>>i));
            if(r >= k) {
                ans = (m>>i) + 1ll * k * i;
                break;
            }
        }
        cout << ans << '\n';
    }
}