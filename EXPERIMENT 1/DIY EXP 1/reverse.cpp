#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<string> words;

    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    string word;

    while (ss >> word)
    {
        words.push_back(word);
    }

    for (int i = words.size() - 1; i >= 0; i--)
    {
        cout << words[i] << " ";
    }

    return 0;
}