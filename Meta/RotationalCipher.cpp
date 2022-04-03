
// Add any extra import statements you may need here
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Add any helper functions you may need here

string rotationalCipher(string input, int rotationFactor)
{
    string aux;
    int ascii_value = 0;
    for (int i = 0; i < input.length(); i++)
    {
        ascii_value = (int)input[i];
        if (ascii_value >= 'A' && ascii_value <= 'Z')
        {
            aux[i] = (char)((input[i] - 'A' + rotationFactor) % 26 + 'A');
            // cout << "Letra a cambiar: " << input[i] << endl;
            // cout << "Letra cambiada: " << aux[i] << endl;
        }
        else if (ascii_value >= 'a' && ascii_value <= 'z')
        {
            aux[i] = (char)((input[i] - 'a' + rotationFactor) % 26 + 'a');
            // cout << "Letra a cambiar: " << input[i] << endl;
            // cout << "Letra cambiada: " << aux[i] << endl;
        }
        else if (ascii_value >= '0' && ascii_value <= '9')
        {
            aux[i] = (char)((input[i] - '0' + rotationFactor) % 10 + '0');
            // cout << "Letra a cambiar: " << input[i] << endl;
            // cout << "Letra cambiada: " << aux[i] << endl;
        }
        else
        {
            aux[i] = input[i];
            // cout << "Letra a cambiar: " << input[i] << endl;
            // cout << "Letra cambiada: " << aux[i] << endl;
        }
    }
    /*  check problem to output everything to the string. whyyy??? */
    cout << "Original string: " << input << endl;
    cout << "Changed string: " << aux << endl;

    return aux;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string &str)
{
    cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

// void check(string &expected, string &output)
// {
//     bool result = (expected == output);
//     const char *rightTick = u8"\u2713";
//     const char *wrongTick = u8"\u2717";
//     if (result)
//     {
//         cout << rightTick << "Test #" << test_case_number << "\n";
//     }
//     else
//     {
//         cout << wrongTick << "Test #" << test_case_number << ": Expected ";
//         printString(expected);
//         cout << " Your output: ";
//         printString(output);
//         cout << endl;
//     }
//     test_case_number++;
// }

int main()
{

    string input_1 = "AAA";
    int rotationFactor_1 = 4;
    string expected_1 = "EEE";
    string output_1 = rotationalCipher(input_1, rotationFactor_1);

    string input_2 = "aaaBBB111";
    int rotationFactor_2 = 2;
    string expected_2 = "cccDDD333";
    string output_2 = rotationalCipher(input_2, rotationFactor_2);

    // Add your own test cases here
}
