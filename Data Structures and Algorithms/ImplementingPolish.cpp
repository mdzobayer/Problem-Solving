#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isOperator(char ex)
{
    if ( ex == '+' || ex == '-' || ex == '*' || ex == '/' || ex == '^')
        return true;
    else
        return false;
}

int getWeight(char ch)
{
    if (ch == '*' || ch == '/')
        return (3);
    else if (ch == '+' || ch == '-')
        return (2);
    else
        return (1);
}

void polish(char q[], char p[], int size)
{
    stack<char> s;

    s.push('(');

    int i = 0, k = 0, weight;
    char ch;
    while (i < size)
    {
        ch = q[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            p[k++] = ch;
            i++;
            continue;
        }
        if (ch == '(')
        {
            s.push(ch);
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (isOperator(ch))
        {
            while ((s.top() != '(') && (getWeight(s.top()) >= weight))
            {
                p[k++] = s.top();
                s.pop();
            }
            s.push(ch);
            i++;
            continue;

        }
        if (ch == ')')
        {
            while ((s.top() != '('))
            {
                p[k++] = s.top();
                s.pop();
            }
            s.pop();
            i++;
            continue;
        }
        i++;
    }
    while(!s.empty())
    {
        if (s.top() == '(')
        {
            break;
        }
        p[k++] = s.top();
        s.pop();
    }
    p[k] = '\0';
}

int main()
{

    char inFix[] = "A+(B*C-(D/E^F)*G)*H"; //"A+(B*C-(D/E^F)*G)*H";
    int size = strlen(inFix);
    char postFix[size];

    polish(inFix, postFix, size);

    cout << inFix << endl;
    cout << postFix << endl;

    return (0);
}
