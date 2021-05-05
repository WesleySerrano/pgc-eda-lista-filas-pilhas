#include <iostream>
#include <stack>

class PilhaMin
{
    public:
        PilhaMin(){this->stack = new std::stack<long>();}
        unsigned long getSize(){return stack->size();}

        void push(long element)
        {
            if(this->getSize() > 0)
            {
                this->minimum = (element < this->minimum) ? element : this->minimum;
            }
            else  this->minimum = element;

            this->stack->push(element);
        }

        long top(){return this->stack->top();}

        void pop(){this->stack->pop();}

        long obterMinimo(){return this->minimum;}

    private:
        std::stack<long> *stack;
        long minimum;
};



int main(int argc, char* argv[])
{
    PilhaMin *s = new PilhaMin();

    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;
    s->push(500);
    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;
    s->push(200);
    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;
    s->push(300);
    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;
    s->push(100);
    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;
    s->push(400);
    std::cout << "Tamanho da pilha: " << s->getSize() << " Mínimo: " << s->obterMinimo() << std::endl;

    return 0;
}