#include <iostream>
#include<algorithm>

using namespace std;

int player[4];

bool skip(int x)
{
    int a, b, c; // a, b, c 分别存放x个位，十位，百位

    a = x % 10;
    b = (x / 10) % 10;
    c = (x / 100) % 10;

    if(x % 7 == 0 || a == 7 || b == 7 || c == 7)
        return true;
    
    return false;
}

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        cnt ++;
        if(skip(cnt)) {
            player[cnt % 4] ++;
            i --;
        }
    }

    for(int i = 1; i < 4; i ++)
        cout << player[i] << endl;
    cout << player[0] << endl;

    return 0;
}