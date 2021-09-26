/*
 * @Author: Awesome_Zdc 
 * @Date: 2021-09-26 18:46:46 
 * @Last Modified by:   Awesome_Zdc 
 * @Last Modified time: 2021-09-26 18:46:46 
 */
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e2+10, M = 2e3 + 10;

double hole[N], p[M][N], ans[M];
double r, d[M], rd[M]; //d[]中存所有点到黑洞的距离， rd[]存点与黑洞相切的线段长
double n, m;


double square(double a)  //平方
{
    return a * a;
}

int main()
{
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i ++) // 黑洞坐标
    {
        cin >> hole[i];
    }

    for(int i = 1; i <= m; i ++)   
    {
        double dis = 0;
        for(int j = 1; j <= n; j ++)
        {
            cin >> p[i][j]; //点p坐标
            dis += square(hole[j] - p[i][j]);
        }
        d[i] = sqrt(dis);
        rd[i] = sqrt(square(d[i]) - square(r));     
    }    

    for(int i = 1; i <= m; i ++)
    {
        for(int j  = i + 1; j <= m; j ++)
        {
            double dis = 0;
            for(int k = 1; k <= n; k ++)
                dis += square(p[i][k] - p[j][k]);
            
            double a = d[i], b = d[j], c = sqrt(dis);
            double p = (a + b + c) / 2;
            double s = sqrt(p * (p - a) * (p - b) * (p - c)); // 海伦公式
            double h = s * 2 / c;

            if(h > r || square(a) + dis <= square(b) || square(b) + dis <= square(a))
            {
                ans[i] += c;
                ans[j] += c;
            } 

            else {
                double a1 = acos((square(a) + square(b) - dis) / (2 * a * b));
                double a2 = acos(r / a);
                double a3 = acos(r / b);

                double arc = (a1 - a2 - a3) * r; // 弧长
                double len = arc + d[i] + d[j];
                ans[i] += len;
                ans[i] += len;
            }
        }
    }

    for(int i = 1; i <= m; i ++)
        printf("%.14f\n", ans[i]);
    
    return 0;
}