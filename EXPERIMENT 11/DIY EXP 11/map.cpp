#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> freq;
    string word;

    int n;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter the words:" << endl;

    for(int i = 0; i < n; i++)
    {
        cin >> word;
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";

    string mostFrequent;
    int maxCount = 0;

    for(auto p : freq)
    {
        cout << p.first << " : " << p.second << endl;

        if(p.second > maxCount)
        {
            maxCount = p.second;
            mostFrequent = p.first;
        }
    }

    cout << "\nMost frequent word: "
         << mostFrequent << endl;

    cout << "Frequency: " << maxCount;

    return 0;
}
