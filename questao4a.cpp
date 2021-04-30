#include <iostream>
#include <queue>
#include <stack>

template <typename T>
void reverseStack(std::stack<T> *stack)
{
    std::queue<T> *queue = new std::queue<T>();

    while(!stack->empty())
    {
        queue->push(stack->top());
        stack->pop();
    }

    while(!queue->empty())
    {
        stack->push(queue->front());
        queue->pop();
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    std::stack<long> *stack = new std::stack<long>();

    stack->push(100);
    stack->push(500);
    stack->push(400);
    stack->push(200);
    stack->push(300);

    std::cout << "Stack top: " << stack->top() << std::endl;
    reverseStack(stack);
    std::cout << "Stack top after reverse: " << stack->top() << std::endl;

    return 0;
}