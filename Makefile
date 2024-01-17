scheduler : main.o
	@echo "main"
	g++ -pedantic -Wall -o Build/scheduler.out Build/main.o

main.o : bogie.o
	@echo "main.o"
	g++ -pedantic -Wall -c Src/main.cpp -o Build/main.o 

bogie.o : Inc/bogie.hpp
	@echo "bogie.o"
	g++ -pedantic -Wall -c Src/bogie.cpp -o Build/bogie.o

clean:
	rm -f Build/scheduler.out Build/main.o Build/bogie.o