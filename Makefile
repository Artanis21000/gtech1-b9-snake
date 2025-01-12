CC=g++
# Adapt the variables below to your needs:
EXE=snake
CPP=boucle.cpp move.cpp snake.cpp window.cpp
HPP= fruit.hpp snake.hpp segment.hpp constantes.hpp eat.hpp window.hpp move.hpp

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -lSDL2 -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

# Build the UML diagram as a PNG image:
../uml/classes.png: $(HPP)
	../uml/mk_uml.sh $@ $^

# Count the number of lines of code:
nblines:
	@wc -l $(CPP) $(HPP)
