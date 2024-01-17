scheduler : main.o bogie.o mine.o
	@echo "main"
	g++ -pedantic -Wall -o Build/scheduler.out Build/main.o

main.o : bogie.o bogie.o mine.o
	@echo "main.o"
	g++ -pedantic -Wall -c Src/main.cpp -o Build/main.o 

mine.o : Inc/mine.hpp bogie.o
	@echo "mine.o"
	g++ -pedantic -Wall -c Src/mine.cpp -o Build/mine.o

bogie.o : Inc/bogie.hpp 
	@echo "bogie.o"
	g++ -pedantic -Wall -c Src/bogie.cpp -o Build/bogie.o

clean:
	rm -f Build/scheduler.out Build/main.o Build/bogie.o Build/mine.o