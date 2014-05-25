CXX=g++
CXXFLAGS=-Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o Personnage.o Weapon.o Warrior.o Wizard.o StringServices.o
	@$(CXX) -o $@ $^

main.o: *.h

%.o: %.cpp
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper
    
clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf main
