#include <iostream>

struct NoDeque
{
    long valor;
    struct NoDeque* proximo;
    struct NoDeque* anterior;
};

struct DequeEncadeado
{
    struct NoDeque *noCabeca;
    struct NoDeque *noFinal;

    unsigned long contadorElementos;
};

struct NoDeque* criaNoDeque(long valor)
{
    struct NoDeque* noDeque = new NoDeque;

    noDeque->anterior = NULL;
    noDeque->proximo = NULL;
    noDeque->valor = valor;

    return noDeque;
}

struct DequeEncadeado* criaDeque()
{
    struct DequeEncadeado* deque = new DequeEncadeado;
    
    deque->noCabeca = NULL;
    deque->noFinal = NULL;
    deque->contadorElementos = 0;

    return deque;
}

void buscaInicio(struct DequeEncadeado* deque)
{
    struct NoDeque* noDeque = deque->noCabeca;

    while(noDeque != NULL)
    {
        std::cout << noDeque->valor << " ";
        noDeque = noDeque->proximo;
    }

    std::cout << std::endl;
}

void buscaFim(struct DequeEncadeado* deque)
{
    struct NoDeque* noDeque = deque->noFinal;

    while(noDeque != NULL)
    {
        std::cout << noDeque->valor << " ";
        noDeque = noDeque->anterior;
    }

    std::cout << std::endl;
}

void apagaDeque(struct DequeEncadeado* deque)
{
    struct NoDeque* noDeque = deque->noCabeca;

    while(noDeque != NULL)
    {
        struct NoDeque* aux = noDeque;
        noDeque = noDeque->proximo;
        delete aux;
    }

    delete deque;
}

void insereInicio(long valor, struct DequeEncadeado* deque)
{
    struct NoDeque* noDeque = criaNoDeque(valor);

    noDeque->proximo = deque->noCabeca;

    deque->noCabeca = noDeque;
    deque->contadorElementos++;
    deque->noCabeca->proximo->anterior = deque->noCabeca;
}

void insereFim(long valor, struct DequeEncadeado* deque)
{
    struct NoDeque* noDeque = criaNoDeque(valor);

    if(deque->noCabeca == NULL)
    {
        deque->noCabeca = noDeque;
        deque->noFinal = noDeque;
    }
    else
    {
        deque->noFinal->proximo = noDeque; 
        struct NoDeque *aux = deque->noFinal;
               
        deque->noFinal = deque->noFinal->proximo;
        deque->noFinal->anterior = aux;
    }
    deque->contadorElementos++;
}

long removeInicio(struct DequeEncadeado* deque)
{
    if(deque->contadorElementos == 0) exit(0);
    struct NoDeque* aux = deque->noCabeca;
    long valor = aux->valor;

    deque->noCabeca = deque->noCabeca->proximo;
    delete aux;

    deque->contadorElementos--;

    return valor;
}

long removeFim(struct DequeEncadeado* deque)
{
    if(deque->contadorElementos == 0) exit(0);
    struct NoDeque* aux = deque->noFinal;
    long valor = aux->valor;

    deque->noFinal = deque->noFinal->anterior;

    deque->contadorElementos--;

    return valor;
}

int main(int argc, char* argv[])
{
    std::cout << "Criando deque\n";

    struct DequeEncadeado* deque = criaDeque();

    insereFim(400, deque);
    insereInicio(100, deque);
    insereInicio(300, deque);
    removeInicio(deque);
    insereInicio(200, deque);
    removeFim(deque);
    insereFim(500, deque);
    
    buscaInicio(deque);
    buscaFim(deque);

    std::cout << "Apagando deque\n";
    apagaDeque(deque);

    return 0;
}