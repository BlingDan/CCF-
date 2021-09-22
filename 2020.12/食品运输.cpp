#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110， M = 10;
typedef  pair<int, int> PII;

int need[N][M] // need[i][j] 判断第i个酒店是否需要食材j食材 0不需要，1需要
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx;
int d[N][M] // d[i][j] 从第i个酒店出发配送食材j食材的最大等待时间 

int n, m, k;   // n个酒店 m个检查站， k种食材

void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++；
} 

PII dfs(int u, int fa, int v)   
{
    //first表示特殊路径和的2倍， second表示与结点u距离最远的特殊结点的距离
    PII ans(0, -1); 

    if(need[u][v]) ans.second = 0; //如果结点u是特殊节点 说明以u为根结点的子树中存在特殊节点，那么将最远距离初始化为0；

    for(int i = h[u], i != -1; i ++)
    {
        int j = e[i];
        if(j == fa) continue; //跳过结点u的父节点

        auto t = dfs(j, u, v); //获得以u的子节点 v 为根结点的子树中的值
        if(t.second != -1) {
            ans.first = ans.first + 2 * w[i];
            ans.second = max(ans.second, t.second + w[i])
        }
    }

    return ans;
}

bool check(int mid)  //二分查找
{
    int state[N], f[1 << M][1 << K];

    memset(state, 0, sizeof state);
    for(int i = 1; i <= n; i ++) // 遍历酒店
        for(int j = 0; j < k; j ++) //遍历食材
            if(d[i][j] <= mid) state[i] |= 1 << j;   //酒店配送食材的最大时间小于mid,酒店i可以用于配送食材j
    
    memset(f, 0x3f3f, sizeof f);
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++)        //遍历酒店i，以i为出发点，查看食材的配送情况
        for(int j = 1; j <= m; j ++) {          //遍历检查点，酒店i在第j个检查点的配送情况
            for(int tmp = 0; tmp < (1 << k); tmp ++)

                f[j][tmp | state[i]] = f[j - 1][tmp];
        }

        
}

int main()
{
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < k; j ++)
            scanf("%d", &need[i][j]);

    memset(h, -1, sizeof -1); // 建树
    for(int i = 0; i < n - 1; i ++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

// 给定一张图（边数=点数-1），以及一些特殊标记的点，求出从图上某一点作为起点，求出从该起点出发，遍历完所有特殊标记的点所经过的最短的路程(不需要回到原点)
    for(int i = 1; i <= n; i ++) 
        for(int j = 0; j < m; j ++)
        {
            auto t = dfs(i, -1, j);
            if(t.second != -1) d[i][j] = t.first - t.second;
        }

    int l = 0, r = 2e8;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;
    return 0;



}