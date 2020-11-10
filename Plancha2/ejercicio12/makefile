WINDOWS = guindows

ej12: corrutinas.c $(WINDOWS).o
	gcc -o ej12.out -Wall -Werror -g corrutinas.c $(WINDOWS).o

$(WINDOWS).o: $(WINDOWS).c $(WINDOWS).h
	gcc -c -Wall -Werror $(WINDOWS).c

cleanOut:
	rm *.out

cleanO:
	rm *.o
