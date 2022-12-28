#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{

public:
    T data;
    Node *next;

    Node()
    {
        next = NULL;
    }
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class Stack
{

public:
    Node<T> *top;
    Stack()
    {
        top = NULL;
    }

    void push(T c)
    {
        Node<T> *node = new Node<T>(c);
        node->next = top;
        top = node;
    }

    void pop()
    {

        if (top == NULL)
        {
            return;
        }
        Node<T> *temp = top;
        top = top->next;
        delete(temp);
    }

    T stackTop()
    {
        return top->data;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;

        return false;
    }
};

int precedence(char c)
{

    if (c == '+' || c == '-')
        return 1;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '^')
        return 3;

    return -1;
}

string infixToPostfix(string str)
{

    Stack<char> s1;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {

        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            ans += c;
        }
        else if (c == '(')
        {
            s1.push(c);
        }

        else if (c == ')')
        {
            while (s1.stackTop() != '(')
            {
                ans += s1.stackTop();
                s1.pop();
            }
            s1.pop();
        }

        else
        {
            while (!s1.isEmpty() && precedence(c) <= precedence(s1.stackTop()))
            {
                ans += s1.stackTop();
                s1.pop();
            }
            s1.push(c);
        }
    }
    while (!s1.isEmpty())
    {
        // ans += s1.pop()->data;
        ans += s1.stackTop();
        s1.pop();
    }

    return ans;
}

string reverse(string str)
{
    string ans;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        ans += str[i];
    }

    return ans;
}

string infixToPrefix(string str)
{
    string exp = reverse(str);

    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == '(')
            exp[i] = ')';

        else if (exp[i] == ')')
            exp[i] = '(';
    }
    string ans = infixToPostfix(exp);

    return reverse(ans);
}

int evalPostfix(string exp)
{

    Stack<int> s1;

    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == ' ')
            continue;
        if (isdigit(exp[i]))
        {
            s1.push((int)(exp[i] - '0'));
        }

        else
        {
            int val1 = s1.stackTop();
            s1.pop();

            int val2 = s1.stackTop();
            s1.pop();

            cout << "val1 " << val1 << " val2 " << val2 << endl;

            switch (exp[i])
            {
            case '+':
            {
                s1.push(val2 + val1);
                break;
            }

            case '-':
            {
                s1.push(val2 - val1);
                break;
            }

            case '*':
            {
                s1.push(val2 * val1);
                break;
            }

            case '/':
            {
                s1.push(val2 / val1);
                break;
            }

            case '^':
            {
                s1.push(pow(val2, val1));
                break;
            }
            }
        }
    }
    return (int)s1.stackTop();
}

// string reverse(string str) {

//     string ans;
//     for(int i = str.length()-1; i >= 0; i--) {
//         ans += str[i];
//     }

//     return ans;
// }

int evalPrefix(string str)
{

    string exp = reverse(str);
    int ans = evalPostfix(exp);
    return ans;
}

int main()
{

    // string str;
    // cout << "enter the string : ";
    // cin >> str;
    // string answer = infixToPostfix(str);
    // cout << "\n"
    //      << answer << "\n";

    cout << evalPostfix("8 4 7 * +") << endl;

    cout << evalPrefix("+ * 7 9 6") << endl;
}