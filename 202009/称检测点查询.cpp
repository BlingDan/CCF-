/*
 * @Author: Awesome_Zdc 
 * @Date: 2021-09-23 18:02:28 
 * @Last Modified by:   Awesome_Zdc 
 * @Last Modified time: 2021-09-23 18:02:28 
 */
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 210;
int map[N][N];
int n, X, Y;
PII a[N];

int main()
{
    cin >> n >> X >> Y;

    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i].first = (X - x) * (X - x) + (Y - y) * (Y - y);
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);
/*
    int index = 1;
    for(int i = 1 ;i <= 3; i ++) {
        if(i == 1) {
            cout << a[index].second << endl;
            continue;
        }

        int next = index + 1;

        while(a[index].first == a[next].first && next <= n) 
            next ++;
        index = next;

        cout << a[index].second << endl;
    }


    for(int i = 1; i <= n; i ++)
        cout << a[i].first << ' ' << a[i].second << endl;
*/
    for(int i = 1; i <= 3; i ++)
        cout << a[i].second << endl;
    return 0;
}