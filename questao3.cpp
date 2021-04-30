#include <iostream>
#include <stack>

struct Queue
{
    unsigned long numberOfElements = 0;

    std::stack<long> s0;
    std::stack<long> s1;
};

void push(long element, struct Queue* queue)
{
    while(!queue->s0.empty())
    {
        queue->s1.push(queue->s0.top());
        queue->s0.pop();
    }
    
    queue->s0.push(element);

    while(!queue->s1.empty())
    {
        queue->s0.push(queue->s1.top());
        queue->s1.pop();
    }

    queue->numberOfElements++;
}

void pop(struct Queue* queue)
{
    if(queue->numberOfElements >= 1)
    {
        queue->s0.pop();
        queue->numberOfElements--;
    }
}

long front(struct Queue* queue)
{
    if(queue->numberOfElements == 0) exit(0);
    return queue->s0.top();
}

int main(int argc, char* argv[])
{
    struct Queue* queue = new Queue;

    push(100, queue);
    push(300, queue);
    push(500, queue);
    push(400, queue);
    push(200, queue);

    std::cout << front(queue) << std::endl;
    pop(queue);
    std::cout << front(queue) << std::endl;
    pop(queue);
    std::cout << front(queue) << std::endl;

    return 0;
}