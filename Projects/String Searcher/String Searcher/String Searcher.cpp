#include <iostream>
using namespace std;

bool hasSubString(const char* word, const char* text) {

    if (NULL == word || NULL == text)
        return 0;

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
            return 1;
        else 
            i++;
    }

    return hasWord;
}

int main()
{
    const char* text = "hello sir, how are you doing today?";
    const char* word = "?";

    cout << hasSubString(word, text) << endl;
}