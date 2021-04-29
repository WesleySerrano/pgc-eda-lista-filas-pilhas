COMPILER = g++ --std=c++17

all: clean questao1Sequencial

questao1Sequencial: questao1Sequencial.cpp
	 $(COMPILER) -o questao1Sequencial.out questao1Sequencial.cpp

clean:
	rm *.out