#include <iostream>
using namespace std;

char shift(char c, int key) {
    return c + (key % 256);
}

string encrypt(string encryptWord, int key) {

    for (unsigned int i = 0; i < encryptWord.length(); i++) 
        encryptWord[i] = shift(encryptWord[i], key);

    return encryptWord;
}

string decrypt(string decryptWord, int key) {

    for (unsigned int i = 0; i < decryptWord.length(); i++)
        decryptWord[i] = shift(decryptWord[i], -key);

    return decryptWord;
}

int main()
{
    string word = "zach schiro";
    int key = 1000;

    cout << "Before encryption: " << word << endl;

    word = encrypt(word, key);
    cout << "After encryption: " << word << endl;

    word = decrypt(word, key);
    cout << "After decryption: " << word << endl;
}