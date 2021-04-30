COMPILER = g++ --std=c++17

all: clean questao1Sequencial questao1Encadeada questao2

questao1Sequencial:
	 $(COMPILER) -o questao1Sequencial.out questao1Sequencial.cpp

questao1Encadeada:
	$(COMPILER) -o questao1Encadeada.out questao1Encadeada.cpp

questao2:
	$(COMPILER) -o questao2.out questao2.cpp

clean:
	rm *.out