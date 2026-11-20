#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

int main() {
    vector<int> marks = {88, 91, 75};
    marks.push_back(95);                 // vector: dynamic array
    cout << "vector(" << marks.size() << "): ";
    for (int m : marks) cout << m << " ";
    cout << endl;

    set<int> uniq = {3, 1, 2, 3, 1};    // set: unique + auto-sorted
    cout << "set: ";
    for (int x : uniq) cout << x << " "; // 1 2 3
    cout << endl;

    map<string,int> port = {{"eth0",1},{"eth1",2}};  // map: sorted by key
    port["eth2"] = 3;
    cout << "map: ";
    for (auto &p : port) cout << p.first << "=" << p.second << " ";
    cout << endl;

    unordered_map<string,int> freq;     // unordered_map: hash, avg O(1)
    for (string w : {"cpp","stl","cpp"}) freq[w]++;
    cout << "unordered_map: cpp x" << freq["cpp"] << endl;

    queue<int> q;                        // queue: FIFO
    q.push(10); q.push(20);
    cout << "queue front=" << q.front() << " back=" << q.back() << endl;

    return 0;
}