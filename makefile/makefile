CC = gcc
CFLAGS = -Wall -ansi -pedantic 
OBJ = main.o map.o array.o control.o terminal.o
EXEC = maze

ifdef DARK
CFLAGS += -D DARK
DARK : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c map.h array.h control.h
	$(CC) $(CFLAGS) main.c -c 
map.o : map.c map.h 
	$(CC) $(CFLAGS) map.c -c 
array.o : array.c map.h array.h
	$(CC) $(CFLAGS) array.c -c 
control.o : control.c control.h array.h terminal.h
	$(CC) $(CFLAGS) control.c -c 
terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c 


clean :
	rm -f $(EXEC) $(OBJ)
