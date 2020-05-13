#include <iostream>
#include <string>
using namespace std;

int hasSubString(const string word, const string text) {

    if (word.empty() || text.empty())
        return -1;

    bool hasWord = false;
    int i = 0;
    int j = 0;

    while (NULL != text[i]) {
        j = 0;
        while (NULL != word[j]) {
            if (word[j] != text[i + j]) {
                hasWord = false;
                break;
            }
            else
                hasWord = true;

            j++;
        }

        if (true == hasWord)
            return i;
        else 
            i++;
    }

    return -1;
}

int main()
{
    string text;
    // How can you get more than one word?
    getline(cin, text);
    string word;
    getline(cin, word);
    
    cout << hasSubString(word, text) << endl;
}