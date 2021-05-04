#include <iostream>
#include <queue>
#include <stack>

template <typename T>
void printQueue(std::queue<T> queue)
{
    while(!queue.empty())
    {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void reverseQueue(std::queue<T> *queue)
{
    std::stack<T> *stack = new std::stack<T>();

    while(!queue->empty())
    {
        stack->push(queue->front());
        queue->pop();
    }

    while(!stack->empty())
    {
        queue->push(stack->top());
        stack->pop();
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    std::queue<long> *queue = new std::queue<long>();

    queue->push(300);
    queue->push(200);
    queue->push(500);
    queue->push(100);
    queue->push(400);

    printQueue(*queue);
    reverseQueue(queue);
    printQueue(*queue);

    return 0;
}