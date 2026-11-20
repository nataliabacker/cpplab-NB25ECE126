#include <iostream>
#include <string>
using namespace std;

// class template with TWO independent type parameters
template <typename K, typename V>
struct Pair {
    K key; V value;
    void show() const { cout << key << " -> " << value << endl; }
};

// function template with TWO type parameters; 'auto' deduces the return type
template <typename A, typename B>
auto bigger(A a, B b) { return (a > b) ? a : b; }

int main() {
    Pair<string,int> p{"ECE", 121};   // K=string, V=int
    p.show();
    Pair<int,double> q{7, 3.5};       // K=int, V=double
    q.show();
    cout << "bigger(3, 9.5) = " << bigger(3, 9.5) << endl;  // -> 9.5
    return 0;
}