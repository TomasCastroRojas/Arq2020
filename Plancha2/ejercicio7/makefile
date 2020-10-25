EJ7 = ej7

all: a b

a: $(EJ7)a.s
	gcc -o $(EJ7)a.out -Wall -Werror -g $(EJ7)a.s

b: $(EJ7)b.s
	gcc -o $(EJ7)b.out -Wall -Werror -g $(EJ7)b.s

clean:
	rm *.out