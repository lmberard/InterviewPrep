#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
***************************************************************
https://www.facebook.com/careers/life/sample_interview_questions
***************************************************************
*/
int **spiral(int n);
string lookandsay(const string &s);
bool one_edit_apart(const string *s1, const string *s2);

int main()
{
    // question 1
    int **matrix = spiral(10);

    // question 2
    string laf = "1";
    cout << laf << '\n';
    for (int i = 0; i < 10; ++i)
    {
        laf = lookandsay(laf);
        cout << laf << '\n';
    }
    return 0;
}

/*
***************************************************************
https://www.facebook.com/careers/life/sample_interview_questions
***************************************************************
*/
// Question 1: 2D Spiral Array
// https://www.facebook.com/careers/life/sample_interview_questions
// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
// https://leetcode.com/problems/spiral-matrix/
// being n the number of columns. returns a nxn matrix
int **spiral(int n)
{
    // border case
    if (n == 0)
    {
        cout << "Error, n must be > 0" << endl;
        return NULL;
    }

    // ask memory for the matrix nxn
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }

    return matrix;
}

// Question 2: Look and Say
// La constante de Conway es una constante matemática
// ligada a la tasa de crecimiento del número de cifras
// de una sucesión conocida como desintegración audioactiva
// o Look-and-Say
// Starting with the number 1,   you have one 1 which produces 11
// Starting with 11,   you have two 1's.   I.E.:   21
// Starting with 21,   you have one 2, then one 1.   I.E.:   (12)(11) which becomes 1211
// Starting with 1211,   you have one 1, one 2, then two 1's.   I.E.:   (11)(12)(21) which becomes 111221
// https://www.rosettacode.org/wiki/Look-and-say_sequence#C.2B.2B

string lookandsay(const string &s)
{
    ostringstream r;

    for (size_t i = 0; i != s.length();)
    {
        auto new_i = s.find_first_not_of(s[i], i + 1);

        if (new_i == string::npos)
            new_i = s.length();

        r << new_i - i << s[i];
        i = new_i;
    }
    return r.str();
}

// Question 3: Edit Distance
bool one_edit_apart(const string *s1, const string *s2)
{
    if (s1->size() > s2->size())
        swap(s1, s2);
    if (s2->size() - s1->size() > 1)
        return false;
    bool saw_difference = false;
    for (size_t i = 0, j = 0; i < s1->size(); ++i, ++j)
    {
        if ((*s1)[i] != (*s2)[j])
        {
            if (saw_difference)
                return false;
            saw_difference = true;
            if (s2->size() > s1->size())
            {
                --i;
            }
        }
    }
    return saw_difference || s2->size() != s1->size();
}
