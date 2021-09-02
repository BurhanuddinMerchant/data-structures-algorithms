#include <iostream>
#include <string.h>
#define MAX_SIZE 10000
using namespace std;
class Stack
{
    char stack_array[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }
    void push(char c)
    {
        if (isFull())
        {
            cout << "\nStack OverFlow!!\n";
        }
        else
        {
            stack_array[++top] = c;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack UnderFlow!!\n";
        }
        else
        {
            top--;
        }
    }
    char peak()
    {
        if (isEmpty())
        {
            return '!';
        }
        else
        {
            return stack_array[top];
        }
    }
};

bool isOperator(char c)
{
    switch (c)
    {
    case ('+'):
    {
        return true;
    }
    case ('-'):
    {
        return true;
    }
    case ('*'):
    {
        return true;
    }
    case ('/'):
    {
        return true;
    }
    case ('('):
    {
        return true;
    }
    case ('{'):
    {
        return true;
    }
    case ('['):
    {
        return true;
    }
    case (')'):
    {
        return true;
    }
    case ('}'):
    {
        return true;
    }
    case (']'):
    {
        return true;
    }
    default:
    {
        return false;
    }
    }
}
bool isOperand(char c)
{
    return !isOperator(c);
}
bool isOpeningParanthesis(char c)
{
    if (isOperator(c))
    {
        switch (c)
        {
        case ('('):
        {
            return true;
        }
        case ('{'):
        {
            return true;
        }
        case ('['):
        {
            return true;
        }
        default:
        {
            return false;
        }
        }
    }
    else
    {
        return false;
    }
}
bool isClosingParanthesis(char c)
{
    if (isOperator(c))
    {
        switch (c)
        {
        case (')'):
        {
            return true;
        }
        case ('}'):
        {
            return true;
        }
        case (']'):
        {
            return true;
        }
        default:
        {
            return false;
        }
        }
    }
    else
    {
        return false;
    }
}
int getPrecedence(char c)
{
    if (isOperator(c))
    {
        switch (c)
        {
        case ('+'):
        {
            return 1;
        }
        case ('-'):
        {
            return 1;
        }
        case ('*'):
        {
            return 2;
        }
        case ('/'):
        {
            return 2;
        }
        case ('('):
        {
            return 4;
        }
        case ('{'):
        {
            return 4;
        }
        case ('['):
        {
            return 4;
        }
        case (')'):
        {
            return 4;
        }
        case ('}'):
        {
            return 4;
        }
        case (']'):
        {
            return 4;
        }
        default:
        {
            return -1;
        }
        }
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string infixExpression)
{
    Stack operatorStorage;
    string postfix = " ";
    int expressionSize = (int)infixExpression.size();
    for (int i = 0; i < expressionSize; i++)
    {
        char c = infixExpression[i];
        if (isOperand(c))
        {
            postfix = postfix + c + " ";
        }
        else if (isOperator(c))
        {
            if (isClosingParanthesis(c))
            {
                while (!isOpeningParanthesis(operatorStorage.peak()))
                {
                    postfix = postfix + operatorStorage.peak() + " ";

                    operatorStorage.pop();
                }
                operatorStorage.pop();
            }
            else if (isOpeningParanthesis(c))
            {
                operatorStorage.push(c);
            }
            else
            {
                while (!operatorStorage.isEmpty() && !isOpeningParanthesis(operatorStorage.peak()) && getPrecedence(operatorStorage.peak()) >= getPrecedence(c))
                {
                    postfix = postfix + operatorStorage.peak() + " ";
                    operatorStorage.pop();
                }
                operatorStorage.push(c);
            }
        }
    }
    while (!operatorStorage.isEmpty())
    {
        postfix = postfix + operatorStorage.peak() + " ";
        operatorStorage.pop();
    }
    return postfix;
}
int evaluatePostfix(char *exp)
{
    Stack stack;
    int i;
    // loop up till end of the c-string
    for (i = 0; exp[i]; ++i)
    {

        if (isdigit(exp[i]))
            // converts the char at i to integer implicitely
            stack.push(exp[i] - '0');
        else
        {
            int val1 = stack.peak();
            stack.pop();
            int val2 = stack.peak();
            stack.pop();
            switch (exp[i])
            {
            case '+':
                stack.push(val2 + val1);
                break;
            case '-':
                stack.push(val2 - val1);
                break;
            case '*':
                stack.push(val2 * val1);
                break;
            case '/':
                stack.push(val2 / val1);
                break;
            }
        }
    }
    return stack.peak();
}
int main()
{
    cout << "Infix to Postfix Converter\n";
    while (true)
    {
        string infixExpression;
        cout << "Enter the expression to be converted : ";
        cin >> infixExpression;
        string postFixExpression = infixToPostfix(infixExpression);
        cout << "The Equivalent PostFix Expression Is  : " << postFixExpression << endl;
        cout << "Note : If Expression has Variables , it will not be evaluated \n";
        cout << "Do you want to evaluate the expression ? (1/0) : ";
        char eval;
        cin >> eval;
        if (eval == '1')
        {
            string pfx = "";
            int len = (int)postFixExpression.length();
            bool error = false;
            for (int i = 0; i < len; i++)
            {
                if (postFixExpression[i] != ' ')
                {
                    pfx += postFixExpression[i];
                }
                if (isalpha(postFixExpression[i]))
                {
                    cout << "Expression cannot be evaluated !! (variable " << postFixExpression[i] << " found !)\n\n";
                    error = true;
                    break;
                }
            }
            if (error)
            {
                continue;
            }
            else
            {

                int n = pfx.length();
                char char_array[n + 1];
                strcpy(char_array, pfx.c_str());
                cout << endl
                     << "After evaluation : " << evaluatePostfix(char_array) << endl;
            }
        }
        cout << "\nContinue ? (1/0) : ";
        char opt;
        cin >> opt;
        cout << endl;
        if (opt == '0')
        {
            break;
        }
    }
    cout << "\n\nThank You! \n";
    return 0;
}