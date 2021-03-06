#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 * https://www.hackerrank.com/challenges/balanced-brackets/problem
 */

// This can be resolved using STACKS. Basically you put everything in a pile of chars (stack)
//  if you see your "partner", you take it out and keep looking for the rest
string isBalanced(string s)
{
    stack<char> st;

    for (char bracket : s)
    { // for each bracket in the string s
        switch (bracket)
        {
        case '{':
        case '(':
        case '[':
            st.push(bracket); // add the bracket
            break;
        case '}':
            if (st.empty() || (st.top() != '{'))
                // as it is a stack, everything pushes at the top
                return "NO";
            st.pop(); // if there is a match {}, i take out the { of the stack
            break;
        case ')':
            if (st.empty() || (st.top() != '('))
                return "NO";
            st.pop();
            break;
        case ']':
            if (st.empty() || (st.top() != '['))
                return "NO";
            st.pop();
            break;
        }
    }

    return st.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
