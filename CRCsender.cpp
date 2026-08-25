#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, divisor;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator polynomial: ";
    cin >> divisor;

    int dataLength = data.length();
    int divisorLength = divisor.length();

    // Append (n-1) zeros to data
    string temp = data;

    for (int i = 0; i < divisorLength - 1; i++)
    {
        temp = temp + "0";
    }

    cout << "\nData after appending zeros: " << temp << endl;

    // Modulo-2 division
    for (int i = 0; i <= temp.length() - divisorLength; i++)
    {
        // Division is performed only if current bit is 1
        if (temp[i] == '1')
        {
            for (int j = 0; j < divisorLength; j++)
            {
                // XOR operation
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Last (n-1) bits are CRC
    string crc = temp.substr(
        temp.length() - (divisorLength - 1)
    );

    cout << "CRC: " << crc << endl;

    // Codeword = original data + CRC
    string codeword = data + crc;

    cout << "Codeword to be transmitted: "
         << codeword << endl;

    return 0;
}

/*Enter data: 10100001
Enter generator polynomial: 1001

Data after appending zeros: 10100001000
CRC: 111
Codeword to be transmitted: 10100001111*/