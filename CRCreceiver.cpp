#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, divisor;

    // Input from user
    cout << "Enter received codeword: ";
    cin >> codeword;

    cout << "Enter generator polynomial: ";
    cin >> divisor;

    // Modulo-2 division
    string temp = codeword;

    for (int i = 0; i <= temp.length() - divisor.length(); i++)
    {
        // If current bit is 1, perform XOR
        if (temp[i] == '1')
        {
            for (int j = 0; j < divisor.length(); j++)
            {
                // XOR operation
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get remainder
    int remainderLength = divisor.length() - 1;

    string remainder =
        temp.substr(temp.length() - remainderLength);

    cout << "\nRemainder: " << remainder << endl;

    // Check error
    bool error = false;

    for (int i = 0; i < remainder.length(); i++)
    {
        if (remainder[i] == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
    {
        cout << "Error is present in received data." << endl;
    }
    else
    {
        cout << "No error is present in received data." << endl;
    }

    return 0;
}

/*Enter received codeword: 10100001101
Enter generator polynomial: 1001

Remainder: 010
Error is present in received data.*/

/*Enter received codeword: 10100001111
Enter generator polynomial: 1001

Remainder: 000
No error is present in received data.*/