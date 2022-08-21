## 前缀函数

字符串 $s[0\cdots n]$ 的前缀函数 $\pi[i]$ 被定义为其子串 $s[0\cdots i]$ 最长相等的真前后缀的长度

### 线性求解前缀函数

假设已经求出了 $0$ 到 $i$ , 考虑 $i+1$  

如果 $s[\pi[i]] = s[i+1]$ 那么自然就求出了 $\pi[i+1]$  

否则 , 需要知道子串 $s[0\cdots i]$ 的第二长相等真前后缀的长度 , 显然 , 这既要严格小于最长 , 而且还需是最长的后缀 , 又因为 $s[0\cdots \pi[i]-1] = s[i-\pi[i]\cdots i]$ , 所以我们实际上就是在找 $s[0\cdots \pi[i]-1]$ 的最长相等真前后缀的长度 , 这是已知的

下标 $i$ 转移的过程可以用一个方程描述 , $i_{k} = \pi[i_{k-1}] - 1$ , 直到等于 $0$ , 过程停止

因为 $\pi[i] - \pi[i+1] \geq -1$ , 所以跳的次数的上界不会超过 $N$ 

### 前缀函数的树形结构

将 $0, \cdots ,n$ 看作点 , $(pi[i]-1,i)$ 看作边 , 那么容易发现这形成了一颗以 $0$ 为根的树 , 其中点 $i$ 到 $0$ 的路径对应的就是 $i_{k} = \pi[i_{k-1}] - 1$ 的过程 , 为了方便起见 , 在建树时可以选择将所有点的序号 $+1$

### 变式 : 线性求解最短相等真前后缀的长度

运用类似并查集的合并思路 , 每个点存能跳到的最远的点的位置

```cpp
// 大体思路
for(int i=0; i<n; i++) {
    int &r = pi[i];
    if(r == 0) { continue; }
    while(pi[r-1]) { r = pi[r-1]; }
    cout << r << ' ';
}
```

### 变式 : 线性求解满足某种条件的相等真前后缀的个数 (条件是否成立是单调的)

最基本的做法是倍增 , 运用单调性可以将倍增部分优化掉

考虑其前缀函数的树形结构 , 容易发现点 $i$ 的答案就是 $0$ 到 $i$ 的路径上满足条件的点的个数 , 因为单调性可以通过维护右边界来得到 , 显然这个右边界会随着 $i$ 的加深而向下 , 所以总复杂度是线性的 , 但是常数较大

对于某些特殊的条件(如前后缀要求不重叠) , 还有一种常数较小的写法 , 如果可以证明 $i+1$ 的右边界比 $i$ 的右边界至多多 $1$ , 那么先正常求出前缀函数 , 再假设当前已经求出 $0$ 到 $i$ 的答案 , 然后 $i+1$ 的答案就可以用类似 $KMP$ 的过程得到 , 常数会小很多

## KMP

前缀函数的应用之一

```cpp
struct KMP {
    int mx_n; int pi[2000100]; // 这里大小开到 n+m+1 就可以
    void init(char *s, int n) {
        fill(pi, pi+n+1, 0);
        mx_n = n;
        for(int i=1; i<n; i++) {
            int r = pi[i-1];
            while(r && s[r] != s[i]) { r = pi[r-1]; }
            if(s[r] == s[i]) { pi[i] = r + 1; }
        }
    }
    /* pattern + '#' + target */
    void kmp(char target[], char pattern[], char data[]) {
        int n1 = strlen(target), n2 = strlen(pattern);
        strcpy(data, pattern);
        strcpy(data+n2+1, target);
        data[n2] = '#';
        init(data, n1+n2+1);
    }
    int fd_nx(int i, int le) {
        while(i < mx_n) { if(pi[i] == le) { return i; } ++i; }
        return -1;
    }
    vector<int> fd_all(int s, int le) {
        static vector<int> q;
        while(true) { s = fd_nx(s, le); if(s == -1) { break; } q.push_back(s); ++s;}
        return q;
    }
};
```