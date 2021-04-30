#include <iostream>
#include <stack>


template <typename T>
void swapStacks(std::stack<T> *source, std::stack<T> *target)
{
    while(!source->empty())
    {
        target->push(source->top());
        source->pop();
    }
}

template <typename T>
void reverseStack(std::stack<T> *stack)
{
    std::stack<T> *s0 = new std::stack<T>();
    std::stack<T> *s1 = new std::stack<T>(); 

    swapStacks(stack, s0);
    swapStacks(s0, s1);
    swapStacks(s1, stack);
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