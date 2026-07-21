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
enum enPrimeNotPrime {PRIME = 1, NOT_PRIME = 0};
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

// proplem-3: is number perfect (perfect = sum(divisors) but not its self)
enum enPerfectNumber {PERFECT = 1, NOT_PERFECT = 0};
bool IsDivisor(int number, int divisor)
{
    return number % divisor == 0;
}
enPerfectNumber IsPerfectNumber(int number)
{
    int halfOfNumber = floor(number / 2);
    int sum = 0;

    for (int i = 1; i <= halfOfNumber ; i++)
    {
        if (IsDivisor(number, i))
        {
            sum += i;
        }
    }

    return sum == number ? PERFECT : NOT_PERFECT;
}
void PrintPerfectNumber(int number)
{
    cout << "Number " << number << " is: ";
    IsPerfectNumber(number) == PERFECT ? cout << "PERFECT" : cout << "NOT PERFECT";
    cout << endl;
}
// END

// proplem-4: print all perfect numebr form 1 to N
void PrintPerfectNumberFrom1toN(int number)
{
    cout << "Perfect number from 1 to " << number << " is:" << endl;
    for (int i = 1; i <= number ; i++)
    {
        if (IsPerfectNumber(i) == PERFECT)
            cout << i << endl;
    }
}
// END

// proplem-5: take numebr then print its digits in reversed order
int GetLastDigit(int number)
{
    return number % 10;
}
void PrintNumberDigitsReversed(int number)
{
    while (number > 0)
    {
        int lastDigit = GetLastDigit(number);

        cout << lastDigit << endl;

        number /= 10;
    }
}
// END

int main()
{
    PrintNumberDigitsReversed(ReadPositiveNumber("Enter positive number"));
}
