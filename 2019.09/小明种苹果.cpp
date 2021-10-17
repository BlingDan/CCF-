/*
 * @Author: Awesome_Zdc 
 * @Date: 2021-10-12 10:27:10 
 * @Last Modified by:   Awesome_Zdc 
 * @Last Modified time: 2021-10-12 10:27:10 
 */
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;

int tree[N];
int Count[N];
int n, m; // n苹果树个数， 进行m轮操作
int t, k, p; // t结束操作后苹果树总和， k疏果个数最多的苹果树编号， p该苹果树的疏果个数

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> tree[i];

        for(int j = 1;  j<= m; j ++)
        {
            int tmp;
            cin >> tmp;
            Count[i] += tmp;
            tree[i] += tmp;
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        t += tree[i];
        
        if(Count[k] > Count[i]) 
            k = i;
    }

    cout << t << ' ' << k << " " << -Count[k] << endl;

    return 0;
}