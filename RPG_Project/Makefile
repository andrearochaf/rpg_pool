CC    =     gcc
NAME  =     game
OBJ   = my_putchar.o \
	  my_putstr.o \
	  my_readline.o \
	  my_strlen.o \
	  my_strdup.o \
	  game.o \

CFLAGS      =     -W -Wall -ansi -pedantic -std=gnu99

LDFLAGS     =     -lmy

RM    =     rm -f

all: $(OBJ)
	cc $(OBJ) -o game

my_game.o: my_game.c my_strdup.o
	cc my_strdup.o -c my_game.c -o game.o 

my_strdup.o: my_strdup.c my_strlen.o
	cc my_strlen.o -c my_strdup.c -o my_strdup.o 

my_strlen.o: my_strlen.c my_putchar.o
	cc my_putchar.o -c my_strlen.c -o my_strlen.o $(CFLAGS) $(LDFLAGS)

my_putchar.o: my_putchar.c
	cc -c my_putchar.c -o my_putchar.o $(CFLAGS) $(LDFLAGS)

my_putstr.o : my_putchar.o my_putstr.c
	cc -o my_putchar.o -c my_putstr.c -o my_putstr.o $(CFLAGS) $(LDFLAGS)

clean:      
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
