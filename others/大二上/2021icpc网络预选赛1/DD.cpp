#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct node{
    LL x, idx;
    bool in;
    bool operator < (const node &be)const{
        return x == be.x ? in < be.in : x < be.x;
    }
}nodes[300000];
struct node_{
    LL val, i;
    bool operator < (const node_ &be)const{
        return val > be.val;
    }
};
LL w[200000];
bool instack[200000];
LL size_;
priority_queue<node_> h;
int main()
{
    LL T;
    scanf("%lld", &T);	
    LL id = 0;
    LL n, m, l, r;
    while(T--) {
        ++ id;
        LL cnt = 0;
        scanf("%lld%lld", &n, &m);
        for (LL i = 1; i <= n; ++ i)
            instack[i] = 0;
        size_ = 0;
        while (h.size())
            h.pop();
        LL sum_ = 0;
        for (LL i = 1 ; i <= m; ++ i){
            scanf("%lld%lld%lld", &l, &r, &w[i]);
            nodes[++cnt] = node{l, i, 1};
            nodes[++cnt] = node{r, i, 0};
            sum_ += (r - l + 1) * (r - l) / 2 * w[i];
        };
        sort(nodes + 1, nodes + 1 + cnt);
        LL j = 1, k = 1;
        LL ans = 0;
        bool flag = 1;
        if (nodes[1].x != 1 || nodes[cnt].x != n)
            flag = 0;
        for (LL i = 1;i <= cnt; ++ i){
            if (k != nodes[i].x){
                // cout << nodes[i].in<<"--"<<endl;
                if (size_ == 0 && i != 1){
                    flag = 0;
                    break;
                }
                k = nodes[i].x;
            }
            if (nodes[i].in){
                h.push(node_{w[nodes[i].idx], nodes[i].idx});
                instack[nodes[i].idx] = 1;
                size_ ++;
            }
            else{
                if (nodes[i].x > j){
                    while (h.size() && !instack[h.top().i]){
                        h.pop();
                    }
                    LL tmp = (nodes[i].x - j);
                    ans += h.top().val * tmp;
                    j = nodes[i].x;
                }
                instack[nodes[i].idx] = 0;
                size_ --;
            }
            
        }
        
		printf("Case #%lld: ", id);
 		if(!flag) printf("Gotta prepare a lesson");
		else printf("%lld", sum_ - ans);
		if(T) putchar('\n');
    }
    return 0;	
}
