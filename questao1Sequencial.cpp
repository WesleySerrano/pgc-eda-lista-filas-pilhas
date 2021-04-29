#include <iostream>

struct DequeSequencial
{
    unsigned long contadorElementos;
    unsigned long tamanhoDeque;

    long* elementos;
};

struct DequeSequencial* iniciaDeque(unsigned long tamanhoDeque)
{
    struct DequeSequencial *novoDeque = (DequeSequencial*) malloc(sizeof(DequeSequencial));

    novoDeque->contadorElementos = 0;
    novoDeque->tamanhoDeque = tamanhoDeque;
    novoDeque->elementos = new long[tamanhoDeque];

    return novoDeque;
}

void aumentaTamanhoDeque(struct DequeSequencial* deque)
{
    delete deque->elementos;

    deque->elementos = new long[2*deque->tamanhoDeque];
    deque->tamanhoDeque *= 2;
}

void insereInicio(struct DequeSequencial* deque, long elemento)
{
    const long TAMANHO_VETOR_AUXILIAR = deque->tamanhoDeque;
    long* vetorAuxiliar = new long[deque->tamanhoDeque];

    for(long i = 0; i < deque->contadorElementos; i++)
    {
        vetorAuxiliar[i] = deque->elementos[i];
    }

    if(deque->contadorElementos >= deque->tamanhoDeque)
    {
        aumentaTamanhoDeque(deque);
    }

    deque->elementos[0] = elemento;
    for(long i = 0; i < TAMANHO_VETOR_AUXILIAR; i++)
    {
        deque->elementos[i+1] = vetorAuxiliar[i];
    }

    deque->contadorElementos++;
}

void insereFim(struct DequeSequencial* deque, long elemento)
{
    if(deque->contadorElementos >= deque->tamanhoDeque)
    {
        const long TAMANHO_VETOR_AUXILIAR = deque->tamanhoDeque;
        long* vetorAuxiliar = new long[deque->tamanhoDeque];

        for(long i = 0; i < deque->contadorElementos; i++)
        {
            vetorAuxiliar[i] = deque->elementos[i];
        }

        aumentaTamanhoDeque(deque);

        for(long i = 0; i < TAMANHO_VETOR_AUXILIAR; i++)
        {
            deque->elementos[i] = vetorAuxiliar[i];
        }
    }

    deque->elementos[deque->contadorElementos++] = elemento;
}

long removeInicio(struct DequeSequencial* deque)
{
    if(deque->contadorElementos == 0) exit(0);

    const long RETORNO = deque->elementos[0];

    for(int i = 1; i < deque->contadorElementos; i++)
    {
        deque->elementos[i-1] = deque->elementos[i];
    }

    deque->contadorElementos--;

    return RETORNO;
}

long removeFim(struct DequeSequencial* deque)
{
    if(deque->contadorElementos == 0) exit(0);

    const long RETORNO = deque->elementos[deque->contadorElementos];

    deque->contadorElementos--;

    return RETORNO;
}

void percorreDeque(struct DequeSequencial* deque)
{
    for(long i = 0; i < deque->contadorElementos; i++)
    {
        std::cout << deque->elementos[i] << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "Criando deque\n";
    const long TAMANHO_INICIAL_DEQUE = 10;
    struct DequeSequencial* deque = iniciaDeque(TAMANHO_INICIAL_DEQUE);

    insereInicio(deque, 100);
    insereInicio(deque, 300);
    removeInicio(deque);
    insereInicio(deque, 200);
    removeFim(deque);
    insereFim(deque, 400);

    percorreDeque(deque);

    std::cout << "Apagando deque\n";
    delete deque;

    return 0;
}