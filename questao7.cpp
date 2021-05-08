#include <iostream>
#include <stack>
#include <string>
#include <map>

bool isOperator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

std::string convertToRPN(std::string expression)
{
    std::stack<char> *operators = new std::stack<char>();
    std::stack<char> *operands = new std::stack<char>();

    std::map<char, short> *operatorsPrecedences = new std::map<char, short>();
    operatorsPrecedences->emplace('+', 0);
    operatorsPrecedences->emplace('-', 0);
    operatorsPrecedences->emplace('*', 1);
    operatorsPrecedences->emplace('/', 1);

    std::string *output = new std::string();

    for(std::string::iterator it = expression.begin(); it != expression.end(); ++it)
    {
        char c = *it;

        if(isOperator(c))
        {
            while(!operators->empty() && isOperator(operators->top()))
            {
                const short CURRENT_OPERATOR_PRECEDENCE = operatorsPrecedences->at(c);
                const short TOP_OPERATOR_PRECEDENCE = operatorsPrecedences->at(operators->top());

                if(CURRENT_OPERATOR_PRECEDENCE <= TOP_OPERATOR_PRECEDENCE)
                {
                    *output += operators->top();     
                    operators->pop();
                    continue;
                }

                break;
            }
            operators->push(c);
        }
        else if(c == '(') operators->push(c);
        else if(c == ')') 
        {
            if(!operators->empty())
            {
                while(operators->top() != '(')
                {
                    *output += operators->top();
                    operators->pop();
                }

                operators->pop();
            }
        }
        else *output += c;
    }

    while(!operators->empty())
    {
        *output += operators->top();
        operators->pop();
    }

    return *output;
}

int main(int argc, char* argv[])
{
    std::string expression = "((A+B)*(C-(F/D)))";
    std::cout << expression << " " << convertToRPN(expression) << std::endl;

    return 0;
}