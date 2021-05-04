#include <iostream>
#include <queue>

template <typename T>
void swapQueues(std::queue<T> *source, std::queue<T> *target)
{
    while(!source->empty())
    {
        target->push(source->front());
        source->pop();
    }
}

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
    std::queue<T> *q0 = new std::queue<T>();
    std::queue<T> *q1 = new std::queue<T>();

    const unsigned long QUEUE_SIZE = queue->size();

    for(unsigned long i = 0; i < QUEUE_SIZE; i++)
    {
        for(unsigned long j = 0; j < queue->size() - 1; j++)
        {
            queue->push(queue->front());
            queue->pop();
        }
        q0->push(queue->front());
        queue->pop();
    }

    swapQueues(q0,queue);
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