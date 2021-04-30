COMPILER = g++ --std=c++17

all: clean questao1Sequencial questao1Encadeada questao2 questao3

questao1Sequencial:
	 $(COMPILER) -o questao1Sequencial.out questao1Sequencial.cpp

questao1Encadeada:
	$(COMPILER) -o questao1Encadeada.out questao1Encadeada.cpp

questao2:
	$(COMPILER) -o questao2.out questao2.cpp

questao3:
	$(COMPILER) -o questao3.out questao3.cpp

clean:
	rm *.out