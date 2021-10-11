#include<iostream>
#include<set>

using namespace std;

typedef long long LL;
typedef pair<long long, long long> PLL;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int diax[4] = {1 ,1, -1, -1};
int diay[4] = {-1, 1, -1, 1};
int a[4];
set<PLL> s;

bool check(LL x, LL y) // (x, y)上下左右是否存在点
{
    for(int i = 0; i < 4; i ++)
    {
        LL a = x + dx[i];
        LL b = y + dy[i];
        if(!s.count({a, b}))
            return false;
    }

    return true;
}
int main()
{
    int n; 
    cin >> n;
    while(n --)
    {
        LL x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    for(set<PLL>::iterator t = s.begin(); t != s.end(); t ++)
    {
        LL x = t->first;
        LL y = t->second;

        if(check(x, y)) {
            int tmp = 0;

            for(int i = 0; i < 4; i ++)
            {
                LL a = x + diax[i];
                LL b = y + diay[i];
                if(s.count({a, b}))
                    tmp ++;
            }

            a[tmp] ++;
        }

    }

    for(int i = 0; i < 5; i ++)
        cout << a[i] << endl;
        
    return 0;
}