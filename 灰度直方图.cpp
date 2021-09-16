#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, L = 260;

int map[N][N];
int degree[L];
int n, m, l;

int main()
{
    cin >> n >> m >> l;

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            scanf("%d", &map[i][j]);
            degree[map[i][j]]++;
        }
    
    for(int i = 0; i < l; i ++)
        cout << degree[i] << ' ' ;
    
    return 0;
}