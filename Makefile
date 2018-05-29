# Makefile pour test systemc du cours EN317
#============================================
include Makefile.in

# Nom de l'executable
EXEC = gpio_SAM3X8E

#liste des sources a compiler
SRC= 	src/main.cpp \
	 	src/register.cpp

# Localisation de systemc
INCLUDE = -Iinclude -I$(SYSTEMC_HOME)/include

# Le compilateur et ses flags
CC = g++

CFLAGS=-W -Wall $(INCLUDE)
LDFLAGS= -L$(LD_LIBRARY_PATH) $(INCLUDE) -l systemc


OBJ=$(SRC:.c=.o)

help :
	@echo "help \t==> \t pour afficher cette aide"
	@echo "build \t==> \t pour compiler le projet"
	@echo "clean \t==> \t pour nettoyer les fichiers de compilation"
	@echo "run \t==> \t pour executer le programme"

build : $(OBJ)
	$(CC) -o $(EXEC) $^ $(LDFLAGS)

run : build
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH) ./$(EXEC)
	@echo "-- done --\n"
%.o: %.c %h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
	rm -f *.out
	rm -f $(EXEC)
