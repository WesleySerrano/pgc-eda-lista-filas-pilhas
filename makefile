COMPILER = g++ --std=c++17

all: clean questao1Sequencial questao1Encadeada

questao1Sequencial:
	 $(COMPILER) -o questao1Sequencial.out questao1Sequencial.cpp

questao1Encadeada:
	$(COMPILER) -o questao1Encadeada.out questao1Encadeada.cpp

clean:
	rm *.out