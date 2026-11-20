#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<string,int>> v = {
        {"Apple", 30},
        {"Banana", 10},
        {"Mango", 20},
        {"Orange", 40}
    };

    sort(v.begin(), v.end(),
         [](pair<string,int> a, pair<string,int> b)
         {
             return a.second < b.second;
         });

    cout << "Sorted pairs:\n";

    for(auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
