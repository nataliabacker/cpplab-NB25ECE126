#include <iostream>
#include <deque>
using namespace std;

template <class T>
class Queue
{
    deque<T> q;

public:

    void enqueue(T value)
    {
        q.push_back(value);
    }

    void dequeue()
    {
        if(q.empty())
            cout << "Queue is empty!" << endl;
        else
        {
            cout << "Deleted: " << q.front() << endl;
            q.pop_front();
        }
    }

    T front()
    {
        if(q.empty())
            throw runtime_error("Queue is empty");

        return q.front();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Cherry");

    cout << "Front element: " << q.front() << endl;

    q.dequeue();

    cout << "Front element after deletion: "
         << q.front() << endl;

    return 0;
}
