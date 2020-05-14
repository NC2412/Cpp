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
    string word;
    char input;
    bool isSearching = true;

    while (true == isSearching) {
        cout << endl << "Please enter text to search: " << flush;
        getline(cin, text);
        cout << "Please enter a substring to search for in the text: " << flush;
        getline(cin, word);

        cout << "Substring found at index: " << hasSubString(word, text) << endl;

        cout << endl << "Would you like to search again? (y/n): " << flush;
        cin >> input;
        isSearching = (input == 'y') ? true : false;

        cin.ignore();
    }
    
    cout << endl << "Program exiting." << flush;
}