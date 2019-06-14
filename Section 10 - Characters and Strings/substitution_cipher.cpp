/**********************************************
 * Author: Miguel Osuna
 * Purpose: Substitution Cipher
 * Date: 21/3/19
**********************************************/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,!;'@#$%^&*"};
    string key      {"zxcvbnmlkjhgfdsaqwertyuiopZXCVBNMLKJHGFDSAQWERTYUIOP ,!;'@#$%^&*"};
    string encryptedMessage {};

    cout << "Enter your message: ";
    // Read the user's input until the Enter is pressed
    getline(cin, encryptedMessage);

    // Make a copy of the original message to be modified

    if(encryptedMessage.length() != 0)
    {
        for(size_t i{0}; i < encryptedMessage.length(); i++)
        {
            char c = encryptedMessage[i];
            size_t index = alphabet.find(c);

            if(index != string::npos)
                encryptedMessage[i] = key[index];
            else
                encryptedMessage[i] = c;
        }

        cout << "The encrypted message is: " << encryptedMessage << endl;
        cout << endl;

        for(size_t i{0}; i < encryptedMessage.length(); i++)
        {
            char c = encryptedMessage[i];
            size_t index = key.find(c);

            if(index != string::npos)
                encryptedMessage[i] = alphabet[index];
            else
                encryptedMessage[i] = c;

        }

        cout << "The original message is: " << encryptedMessage << endl;
        cout << endl;
    }

    return 0;
}
