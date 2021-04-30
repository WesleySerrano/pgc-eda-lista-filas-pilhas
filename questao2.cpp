#include <iostream>
#include <queue>

struct Stack
{
    std::queue<long> q0;
    std::queue<long> q1;

    unsigned long numberOfElements = 0;
};

void push(long element, struct Stack* stack)
{
    std::queue<long> aux;   

    stack->q0.push(element);

    while(!stack->q1.empty())
    {
        stack->q0.push(stack->q1.front());
        stack->q1.pop();
    }

    aux = stack->q1;
    stack->q1 = stack->q0;
    stack->q0 = aux;

    stack->numberOfElements++;
}

void pop(struct Stack* stack)
{
    if(stack->numberOfElements >= 1)
    {
        stack->q1.pop();

        stack->numberOfElements--;
    }
}

long top(struct Stack* stack)
{
    return stack->q1.front();
}

int main(int argc, char* argv[])
{
    struct Stack *stack = new Stack;    

    pop(stack);
    push(100, stack);
    push(200, stack);
    push(400, stack);
    push(300, stack);
    push(500, stack);

    std::cout << top(stack) << std::endl;
    pop(stack);
    std::cout << top(stack) << std::endl;
    pop(stack);
    std::cout << top(stack) << std::endl;

    return 0;
}