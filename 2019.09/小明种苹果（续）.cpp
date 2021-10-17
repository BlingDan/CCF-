#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;
const int M = 100010;

int n, m;
int t, e, d;  //  t最后果子总数， d发生苹果掉落的苹果树棵树， e连续三个苹果树发生掉落的组数

int has_fall[N];
int tree[N][M];
int map[N][M];
int size[N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> size[i];
        for(int j = 1; j <= size[i]; j ++)
            cin >> tree[i][j];
    }

    for(int i = 1; i <= n; i ++)
    {
        bool has_record = false;

        for(int j = 1; j <= size[i]; j ++)
        {
            if(tree[i][j] <= 0)
                map[i][j] = map[i][j - 1] + tree[i][j];
            
            else
            {
                map[i][j] = tree[i][j];

                if(j != 1 && tree[i][j - 1] <= 0 && tree[i][j] > 0 &&  map[i][j] != map[i][j - 1] && !has_record)
                {
                    d ++;
                    has_record = true;
                    has_fall[i - 1] = true;
                }
            }
        }

    }

    int mod = n;
    for(int i = 0; i < n; i ++)
    {
        
        int suc = (i + 1) % mod;
        int Suc = (i + 2) % mod;

        if(has_fall[i] && has_fall[suc] && has_fall[Suc])
            e ++;

        t += map[i + 1][size[i + 1]]; 
    }

   cout << t << ' ' << d << ' ' << e << endl;
/*
    cout << endl;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= size[i]; j ++)
            cout << map[i][j] << ' ';
        
        cout << endl;
    }
*/

    return 0;
}