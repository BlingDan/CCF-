/*
 * @Author: Awesome_Zdc 
 * @Date: 2021-09-23 22:42:50 
 * @Last Modified by:   Awesome_Zdc 
 * @Last Modified time: 2021-09-23 22:42:50 
 */
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 21, M = 1010;

int n, k, t, X1, Y1, X2, Y2;

int across, stay;

int main()
{
    cin >> n >> k >> t >> X1 >> Y1 >> X2 >> Y2;

    for(int i = 1; i <= n; i ++)
    {
        int a, b;
        int cnt = 0;
        int ans = 0;
        bool has_across = false;

        for(int j = 1; j <= t; j ++)
        {
            cin >> a >> b;
            
            if(a >= X1 && a <= X2 && b >= Y1 && b <= Y2)
            {
                cnt ++;

                if(!has_across)
                {
                    has_across = true;
                    across ++;
                }
            }    
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }

        ans = max(ans, cnt);
        if(ans >= k) stay ++;
    }
    printf("%d\n%d", across, stay);

    return 0;
}