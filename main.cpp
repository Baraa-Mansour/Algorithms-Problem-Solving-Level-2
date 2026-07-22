#include <iostream>
#include <ctime>
#include <cstdlib>

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

// proplem-6: take numebr then sum its digits
int SumNumbersDigits(int number)
{
    int lastDigit = 0, sum = 0;

    while (number > 0)
    {
        lastDigit = GetLastDigit(number);

        number /= 10;

        sum += lastDigit;
    }

    return sum;
}
// END

// proplem-7: take numebr then revers it
int ReversNumber(int number)
{
    int reversed = 0, lastDigit = 0;

    while (number > 0)
    {
        lastDigit = GetLastDigit(number);

        number /= 10;

        reversed = (reversed * 10) + lastDigit;
    }

    return reversed;
}
// END

// proplem-8: take number and digit then return the frequency of digit in that numebr
int GetDigitFrequency(int number, int digit)
{
    int lastDigit = 0, counter = 0;

    while (number > 0)
    {
        lastDigit = GetLastDigit(number);
        number /= 10;
        if (lastDigit == digit)
            counter++;
    }

    return counter;
}
// END

// proplem-9: take number then return the frequency of each digit in that numebr
int DeleteDigitFromNumber(int number, int digit)
{
    int lastDigit = 0, reversed = 0;
    while (number > 0)
    {
        lastDigit = GetLastDigit(number);

        number /= 10;

        if (lastDigit != digit)
        {
            reversed = (reversed * 10) + lastDigit;
        }
    }

    return ReversNumber(reversed);
}
/*void PrintDigitsFrequency(int number)
{
    int lastDigit = 0;

    while (number > 0)
    {
        lastDigit = GetLastDigit(number);

        cout << "Digits Count for (" << lastDigit << "):" << GetDigitFrequency(number, lastDigit) << endl;

        number = DeleteDigitFromNumber(number, lastDigit);
    }
}*/ 
void PrintDigitsFrequency(int number)
{
    for (int i = 0; i < 10; i++)
    {
        int count = GetDigitFrequency(number, i);

        if (count > 0)
            cout << "Number (" << i << ") Frequency: " << count << endl;
    }
}
// END

// proplem-10: check palindrome number (number = revers(number))
bool IsPalindrome(int number)
{
    return number == ReversNumber(number);
}
// END

// proplem-11: Print Inverted Number Pattern
void PrintInvertedNumberPattern(int number)
{
    for (int i = number ; i > 0 ; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
// END

// proplem-12: print number pattern
void PrintNumberPattern(int number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
// END

// proplem-13: print letters inverted pattern
void PrintInvertedLettersPattern(int number)
{
    int baseLetterNumber = 64;

    for (int i = number + baseLetterNumber ; i >= 65; i--)
    {
        for (int j = 1; j <= i - baseLetterNumber ; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}
// END

// proplem-14: print all words from AAA to ZZZ
void PrintAAAtoZZZ()
{
    int baseLetterNumber = 65;
    int lastLetterNumber = 90;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}
// END

// proplem-15: guess 3-letters password
string Get3LettersPassword(string password)
{
    int baseLetterNumber = 65;
    int lastLetterNumber = 90;
    string word = "";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                if (word == password)
                    return word;

                word = "";
            }
        }
    }
    
    return word;
}
// END

// proplem-16: Encrypt/Decrypt word
string Encrypt(string word, short encryptionKey)
{
    string encrypted = "";

    for (int i = 0; i < word.length(); i++)
    {
        encrypted += char((int)word[i] + encryptionKey);
    }

    return encrypted;
}
string Decrypt(string word, short encryptionKey)
{
    string encrypted = "";

    for (int i = 0; i < word.length(); i++)
    {
        encrypted += char((int)word[i] - encryptionKey);
    }

    return encrypted;
}
// END

// proplem-17: print 3 random numbers between 1 and 10
int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}
void Print3RandomNumberBetween1and10()
{
    for (int i = 0; i < 3; i++)
    {
        cout << GenerateRandomNumberInRange(1, 10) << endl;
    }
}
// END

// proplem-18: prrint random small letter, capital letter, special character and digit
enum enRandomType
{
    SMALL_LETTER = 1,
    CAPITAL_LETTER = 2,
    SPECIAL_CHARACTER = 3,
    DIGIT = 4
};
char GenerateRandomCharacter(enRandomType type)
{
    switch (type)
    {
    case SMALL_LETTER:
        return char(GenerateRandomNumberInRange(97, 122));
    case CAPITAL_LETTER:
        return char(GenerateRandomNumberInRange(65, 90));
    case SPECIAL_CHARACTER:
        return char(GenerateRandomNumberInRange(33, 47));
    case DIGIT:
        return char(GenerateRandomNumberInRange(48, 57));
    default:
        return char(GenerateRandomNumberInRange(48, 57));
    }
}
// END

int main()
{
    srand((unsigned)time(NULL));

    cout << GenerateRandomCharacter(CAPITAL_LETTER) << endl;
    cout << GenerateRandomCharacter(SMALL_LETTER) << endl;
    cout << GenerateRandomCharacter(SPECIAL_CHARACTER) << endl;
    cout << GenerateRandomCharacter(DIGIT) << endl;
}
