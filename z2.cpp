//var 3
#include <iostream>

using namespace std;

int cost(int v, int n, int *h, int *c, int currentC, int currentV)
{
    if(currentV > v)
        return -1;
    if(n == 0)
        return currentC;
        
    int max = currentC;
    for(int i = 0; i < n; i++)
    {
        int t = cost(v, n-i-1, &h[i+1], &c[i+1], currentC + c[i], currentV + h[i]);
        if(t > max)
        {
            max = t;
        }
    }
    return max;
}

int main()
{
    cout << "Введите грузоподъемность и количество предметов\n";
    int v,n;
    cin >> v >> n;
    cout << "Введите вес предметов\n";
    int h[n];
    for(int i = 0; i < n;i++)
        cin >> h[i];
    cout << "Введите стоимость предметов\n";
    int c[n];
    for(int i = 0; i < n;i++)
        cin >> c[i];
    cout << cost(v, n, h, c, 0, 0);
    return 0;
}