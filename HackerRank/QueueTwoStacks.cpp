#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
QUEUE USING TWO STACKS
Cola: el primero que entra es el primero que sale
Pila: el primero que entra es el ultimo que sale
Entonces la idea de usar dos pilas es poner todo en una y despues cuando
quiero popear, lo pongo en el otro stack y lo saco

push a, b c:
s1
c
b
a

pop:
s2
a
b
c

*/

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> s1, s2;
    int numberOfQueries = 0, q_operation = 0, number = 0;
    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++)
    {
        cin >> q_operation;

        // Enqueue element  into the end of the queue.
        if (q_operation == 1)
        {
            // just push the number at the front of the stack
            cin >> number;
            s1.push(number);
        }

        // Dequeue the element at the front of the queue.
        if (q_operation == 2)
        {
            if (!s2.empty())
            {
                s2.pop();
            }
            else
            {
                // i have to copy everything from s1 to s2 and then pop the front one
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
            }
        }

        // Print the element at the front of the queue
        if (q_operation == 3)
        {
            if (!s2.empty())
            {
                cout << s2.top() << endl;
            }
            else
            {
                // i have to copy everything from s1 to s2 and then pop the front one
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s2.top() << endl;
            }
        }
    }

    return 0;
}
