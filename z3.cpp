//var 18
/*
18. Имеется M типов материалов и K типов клеев, каждый из которых пригоден
для склеивания нескольких типов материалов. Требуется попарно склеить P (P <= M)
известных типов материалов. Найти минимальное число клеев, которые потребуются для этого.
*/

/*
7
3
3
1 2 3
2
4 7
3
1 5 6
5
1 4 5 6 7
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> findglues(int m, int k, vector<set<int>> &glues, set<int> &materials, vector<int> current, int offset)
{
    set<int> covered;
    for(auto glue : current)
    {
        for(auto e : glues[glue])
        {
            covered.insert(e);
        }
    }
    if(includes(covered.begin(), covered.end(), materials.begin(), materials.end()))
    {
        return current;
    }
    if(offset == k)
        return {};
    vector<int> min = {};
    for(int i = offset; i < k; i++)
    {
        current.push_back(i);
        vector<int> t = findglues(m, k, glues, materials, current, i+1);
        if(t.size() != 0 && ((t.size() < min.size()) || (min.size() == 0)))
            min = t;
        current.pop_back();
    }
    return min;
}

int main()
{
    cout << "Введите количество типов материалов\n";
    int m;
    cin >> m;
    cout << "Введите количество типов клеев\n";
    int k;
    cin >> k;
    vector<set<int>> glues(k);
    for(int i = 0; i < k; i++)
    {
        cout << "Введите количество типов материалов для клея " << i+1 << "\n";
        int t;
        cin >> t;
        cout << "Введите " << t << " материалов(индексы с 1)\n";
        for(int j = 0; j < t; j++)
        {
            int tt;
            cin >> tt;
            glues[i].insert(tt);
        }
    }
    cout << "Введите количество материалов для склеивания\n";
    int p;
    cin >> p;
    cout << "Введите " << p << " материалов\n";
    set<int> materials;
    for(int i = 0; i < p; i++)
    {
        int t;
        cin >> t;
        materials.insert(t);
    }
    vector<int> minglues = findglues(m, k, glues, materials, {}, 0);
    if(minglues.size() != 0)
    {
        cout << "Минимальное количество клеев = " << minglues.size() << ": ";
        for(auto glue : minglues)
        {
            cout << glue+1 << " ";
        }
    }
    else
    {
        cout << "Решение не найдено\n";
    }
    return 0;
}