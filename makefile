COMPILER = g++ --std=c++17

all: clean questao1Sequencial questao1Encadeada questao2 questao3 questao4a questao4b questao4c questao5a questao5b questao6

questao1Sequencial:
	 $(COMPILER) -o questao1Sequencial.out questao1Sequencial.cpp

questao1Encadeada:
	$(COMPILER) -o questao1Encadeada.out questao1Encadeada.cpp

questao2:
	$(COMPILER) -o questao2.out questao2.cpp

questao3:
	$(COMPILER) -o questao3.out questao3.cpp

questao4a:
	$(COMPILER) -o questao4a.out questao4a.cpp

questao4b:
	$(COMPILER) -o questao4b.out questao4b.cpp

questao4c:
	$(COMPILER) -o questao4c.out questao4c.cpp

questao5a:
	$(COMPILER) -o questao5a.out questao5a.cpp

questao5b:
	$(COMPILER) -o questao5b.out questao5b.cpp

questao6:
	$(COMPILER) -o questao6.out questao6.cpp

clean:
	rm *.out