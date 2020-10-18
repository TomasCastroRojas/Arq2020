EJ1A = ej1a
EJ1B = ej1b

ej1aS: $(EJ1A).s
	gcc -o $(EJ1A)S.out -Wall -Werror -g $(EJ1A).s

ej1aC: $(EJ1A).c
	gcc -o $(EJ1A)C.out -Wall -Werror -g $(EJ1A).c

ej1bS: $(EJ1B).s
	gcc -o $(EJ1B)S.out -Wall -Werror -g $(EJ1B).s

ej1bC: $(EJ1B).c
	gcc -o $(EJ1B)C.out -Wall -Werror -g $(EJ1B).c

clean:
	rm *.out