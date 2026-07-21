#include <iostream>

using namespace std;

// proplem-1: multiplication table from 1 to 10 as follow
void PrintHeader()
{
    cout << "\n\n\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
}
string ColumnSeperater(int number)
{
    if (number < 10)
        return "     |";
    else
        return "    |";
}
void PrintTable()
{
    PrintHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << i << ColumnSeperater(i) << " ";
        for (int j = 1; j <= 10; j++)
        {
            int result = i * j;
            cout << result << "\t";
        }
        cout << endl;
    }
}
// END

// proplem-2: print all prime number from 1 to N
enum enPrimeNotPrime {PRIME = 1, NOT_PRIME = 2};
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
enPrimeNotPrime CheckPrime(int number)
{
    if (number < 2)
        return PRIME;

    int halfOfNumber = floor(number / 2);

    for (int i = 2; i <= halfOfNumber; i++)
    {
        if (number % i == 0)
            return enPrimeNotPrime::NOT_PRIME;
    }

    return enPrimeNotPrime::PRIME;
}
void PrintPrimeFrom1toN(int number)
{
    cout << "\n";
    cout << "Prime number from 1 to " << number << " are:" << endl;

    for (int i = 1; i <= number; i++)
    {
        if (CheckPrime(i) == enPrimeNotPrime::PRIME)
        {
            cout << i << endl;
        }
    }
}
// END

int main()
{
    PrintPrimeFrom1toN(ReadPositiveNumber("Enter positive number"));
}
