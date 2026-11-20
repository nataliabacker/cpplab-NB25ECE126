
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, x;

    priority_queue<int> pq;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }

    cout << "Three largest elements:\n";

    for(int i = 0; i < 3 && !pq.empty(); i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
