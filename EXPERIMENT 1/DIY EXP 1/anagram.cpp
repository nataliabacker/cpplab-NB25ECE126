#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    int freq1[256] = {0};
    int freq2[256] = {0};
    bool anagram = true;

    cout << "Enter first word: ";
    cin >> s1;

    cout << "Enter second word: ";
    cin >> s2;

    if (s1.length() != s2.length())
    {
        anagram = false;
    }
    else
    {
        for (int i = 0; i < s1.length(); i++)
        {
            freq1[(int)s1[i]]++;
            freq2[(int)s2[i]]++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (freq1[i] != freq2[i])
            {
                anagram = false;
                break;
            }
        }
    }

    if (anagram)
        cout << "They are anagrams." << endl;
    else
        cout << "They are not anagrams." << endl;

    return 0;
}