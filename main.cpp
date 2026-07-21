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


int main()
{
    PrintTable();
}
