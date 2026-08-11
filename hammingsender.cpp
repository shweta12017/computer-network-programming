#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    int m, r = 0;

    cout << "Enter data bits: ";
    cin >> data;
    m = data.length();

    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;

    cout << "\nData Word: " << data;
    cout << "\nNo. of Redundant Bits: " << r;
    cout << "\nTotal No. of Bits in Codeword: " << n << endl;

    int code[20] = {0};
    int j = m - 1;
    for (int pos = 1; pos <= n; pos++)
    {
        if (pos == 1 || pos == 2 || pos == 4 || pos == 8)
        {
            code[pos] = 0;
        }
        else
        {
            code[pos] = data[j] - '0';
            j--;
        }
    }

    cout << "\nCalculating Redundant Bits";
    int count = 0;
    for (int pos = 1; pos <= n; pos++)
    {
        if (pos & 1)
        {
            if (pos != 1)
                count += code[pos];
        }
    }

    code[1] = count % 2;

    cout << "\n\n1) R1";
    cout << "\nConsider R1, D3, D5, D7, D9, D11";
    cout << "\nD3 D5 D7 D9 D11 = ";

    for (int pos : {3, 5, 7, 9, 11})
        cout << code[pos];

    cout << "\nSet R1 = " << code[1];

    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 2) && pos != 2)
            count += code[pos];
    }

    code[2] = count % 2;

    cout << "\n\n2) R2";
    cout << "\nConsider R2, D3, D6, D7, D10, D11";
    cout << "\nD3 D6 D7 D10 D11 = ";

    for (int pos : {3, 6, 7, 10, 11})
        cout << code[pos];

    cout << "\nSet R2 = " << code[2];

    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 4) && pos != 4)
            count += code[pos];
    }

    code[4] = count % 2;

    cout << "\n\n3) R4";
    cout << "\nConsider R4, D5, D6, D7";
    cout << "\nD5 D6 D7 = ";

    for (int pos : {5, 6, 7})
        cout << code[pos];

    cout << "\nSet R4 = " << code[4];

    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 8) && pos != 8)
            count += code[pos];
    }

    code[8] = count % 2;

    cout << "\n\n4) R8";
    cout << "\nConsider R8, D9, D10, D11";
    cout << "\nD9 D10 D11 = ";

    for (int pos : {9, 10, 11})
        cout << code[pos];

    cout << "\nSet R8 = " << code[8];
    cout << "\nFinal Codeword / Codeword Transmitted:";
    
    for (int pos = n; pos >= 1; pos--)
        cout << code[pos];

    cout << endl;

    return 0;
}

//Enter data bits: 1011001

//Data Word: 1011001
//No. of Redundant Bits: 4
//Total No. of Bits in Codeword: 11

//Calculating Redundant Bits

//1) R1
//Consider R1, D3, D5, D7, D9, D11
//D3 D5 D7 D9 D11 = 10111
//Set R1 = 0

//2) R2
//Consider R2, D3, D6, D7, D10, D11
//D3 D6 D7 D10 D11 = 10101
//Set R2 = 1

//3) R4
//Consider R4, D5, D6, D7
//D5 D6 D7 = 001
//Set R4 = 1

//4) R8
//Consider R8, D9, D10, D11
//D9 D10 D11 = 101
//Set R8 = 0
//Final Codeword / Codeword Transmitted:10101001110