#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

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

// proplem-19: generate random keys xxxx-xxxx-xxxx-xxxx from capital letters
string GenerateWord(enRandomType type, int wordLength)
{
    string word = "";

    for (int j = 1; j <= wordLength; j++)
    {
        word += GenerateRandomCharacter(type);
    }

    return word;
}
string GenerateRandomKey(enRandomType type, int keyLength, int wordLength)
{
    string key = "";

    for (int i = 1; i <= keyLength; i++)
    {
        key += GenerateWord(type, wordLength);  

        if (i != keyLength)
            key += "-";
    }

    return key;
}
void PrintRandomsKeys(int numberOfKeys)
{
    while (numberOfKeys > 0)
    {
        cout << GenerateRandomKey(CAPITAL_LETTER, 4, 4) << endl;
        numberOfKeys--;
    }
}
// END

// proplem-20: 
// -Enter number of array elements
// -Enter array elemnts
// -Enter elemnt you want to count and return it
void FillArrayElements(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = ReadPositiveNumber("Enter elemnt (" + to_string(i) + ")");
    }
}
int TimesRepeated(int arr[100], int arrLength, int number)
{
    int counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            counter++;
    }

    return counter;
}
int ReadArray(int arr[100])
{
    int arrLength = ReadPositiveNumber("Enter array length");
    FillArrayElements(arr, arrLength);
    return arrLength;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element " << i << ": " << arr[i] << endl;
    }
}
void PrintTimesRepeated()
{
    int arr[100] = {};
    int arrLength = ReadArray(arr);

    PrintArray(arr, arrLength);

    int number = ReadPositiveNumber("Enter number to check: ");

    int timeRepeated = TimesRepeated(arr, arrLength, number);

    cout << number << " repeated times: ";
    cout << timeRepeated << endl;
}
// END

// proplem-21: get array length then fill it with randoms from 1 to 100
void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateRandomNumberInRange(1, 100);
}
// END

// proplem-22: get max in array
int GetMaxInArray(int arr[100], int arrayLength)
{
    int max = arr[0];
    for (int i = 1; i < arrayLength; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}
// END

// proplem-23: get min in array
int GetMinInArray(int arr[100], int arrayLength)
{
    int min = arr[0];
    for (int i = 1; i < arrayLength; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}
// END

// proplem-24: get sum of array elements
int GetSumArrayElements(int arr[100], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
        sum += arr[i];
    return sum;
}
// END

// proplem-25: get avg in array
float GetAvgInArray(int arr[100], int arrayLength)
{
    return (float)GetSumArrayElements(arr, arrayLength) / arrayLength;
}
// END

// proplem-26: copy array
void CopyArray(int originalArr[100], int copyArr[100], int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
        copyArr[i] = originalArr[i];
}
// END

// proplem-27: copy prime array numbers
void CopyPrimeArrayNumbers(int originalArr[100], int copyArr[100], int arrLength, int& copyLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(originalArr[i]) == PRIME)
        {
            copyArr[copyLength] = originalArr[i];
            copyLength++;
        }
    }
}
// END

// proplem-28: sum of 2 arrays into third one
void SumOf2Arrays(int arr1[100], int arr2[100], int sumArr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        sumArr[i] = arr1[i] + arr2[i];
}
// END

// proplem-29: 
// -fill array with order numebr from 1 to n
// -shuffle this array
void FillArrayFrom1toN(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}
void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void ShuffleArray(int arr[100], int arrLength)
{
    int lastIndex = arrLength - 1;

    for (int i = 0; i < arrLength; i++)
    {
        int index1 = GenerateRandomNumberInRange(0, arrLength - 1);
        int index2 = GenerateRandomNumberInRange(0, arrLength - 1);
        Swap(arr[index1], arr[index2]);
    }
}
// END

// proplem-30: copy array in reversed order
void CopyArrayReversed(int originalArr[100], int copyArr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        copyArr[i] = originalArr[arrLength - i - 1];
}
// END

// proplem-31: fill array with number of random key
void FillArrayWithRandomKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateRandomKey(CAPITAL_LETTER, 4, 4);
}
void PrintArray(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element " << i << ": " << arr[i] << endl;
    }
}
// END

// proplem-32: get element index in array
int GetElementIndex(int arr[100], int arrLength, int number)
{
    for (int i = 0; i < arrLength; i++)
        if (arr[i] == number) return i;

    return -1;
}
// END

// proplem-33: check if elemnt found in array
bool IsElemntFoundInArray(int arr[100], int arrLength, int number)
{
    return GetElementIndex(arr, arrLength, number) != -1;
}
// END

// porplem-34: read array from user with simi-dynamic array length (max 100)
bool ReadYesNo(string message)
{
    bool answer = false;

    cout << message << endl;
    cin >> answer;

    return answer;
}
void AddArrayElemnt(int arr[100], int& arrlength, int number)
{
    arr[arrlength++] = number;
}
void ReadArraySimiDynamic(int arr[100], int& arrLength)
{
    int number = -1;
    bool moreNumbers = false;
    int currentIndex = 0;
    do
    {
        number = ReadPositiveNumber("Enter number: ");

        AddArrayElemnt(arr, arrLength, number);

        moreNumbers = ReadYesNo("More Numbers? [0]:No, [1]:yes?");

    } while (moreNumbers && currentIndex != 100);

}
// END

// proplem-35: copy array with add array function
void CopyArray(int originalArr[100], int copyArr[100], int originalLength, int& copyLength)
{
    for (int i = 0; i < originalLength; i++)
        AddArrayElemnt(copyArr, copyLength, originalArr[i]);
}
// END

// proplem-36: copy odd array numbers
enum enEvenOdd { EVEN = 1, ODD = 2 };
enEvenOdd CheckEvenOdd(int number)
{
    return number % 2 == 0 ? EVEN : ODD;
}
void CopyOddArrayNumbers(int originalArr[100], int copyArr[100], int arrLength, int& copyLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int currentElemnt = originalArr[i];
        if (CheckEvenOdd(currentElemnt) == ODD)
        {
            AddArrayElemnt(copyArr, copyLength, currentElemnt);
        }
    }
}
// END

// porplem-37: copy distinct number in array
void CopyDistinctArrayNumber(int originalArr[100], int copyArr[100], int arrLength, int& copyLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int currentElement = originalArr[i];
        if (!IsElemntFoundInArray(copyArr, copyLength, currentElement))
            AddArrayElemnt(copyArr, copyLength, currentElement);
    }
}
// END

// porplem-38: Palindrome array (array = revers(array))
bool IsPalindromeArray(int arr[100], int arrLength)
{
    int halfLength = floor(arrLength / 2);

    for (int i = 0; i < halfLength; i++)
        if (arr[i] != arr[arrLength - i - 1]) return false;

    return true;
}
// END

// poplem-39: count even/odd numbers in arr
int EvenOddCount(int arr[100], int arrLength, enEvenOdd numType)
{
    int counter = 0;

    for (int i = 0; i < arrLength; i++)
        if (CheckEvenOdd(arr[i]) == numType) counter++;

    return counter;
}
// END

// proplem-40: return abs of number (dont use built in function)
int MyAbs(int number)
{
    return number > 0 ? number : (number * -1);
}
// END

// proplem-41: return round of number (dont use built in function)
float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyRound(float number)
{
    float fractionPart = GetFractionPart(number);
    int integerPart = (int)number;

    if (abs(fractionPart) >= 0.5)
        return number > 0 ? ++integerPart : --integerPart;
    else
        return integerPart;
}
// END

// proplem-42: return floor of numebr (dont use built in function)
int MyFloor(float number)
{
    int integerPart = (int)number;

    return integerPart;
}
// END

// proplem-43: return ceil of numebr (dont use built in function)
int MyCeil(float number)
{
    int integerPart = (int)number;
    float fractionPart = GetFractionPart(number);

    if (abs(fractionPart) > 0)
        return integerPart > 0 ? ++integerPart : --integerPart;

    return number;
}
// END

// proplem-44: return sqrt of numebr (dont use built in function)
float MySqrt(float number)
{
    return pow(number, 0.5);
}
// END

int main()
{
    srand((unsigned)time(NULL));

    int number = ReadPositiveNumber("eneter number: ");

    cout << MySqrt(number) << endl;
}
