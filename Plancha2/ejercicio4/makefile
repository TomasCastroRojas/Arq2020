EJ4 = ej4

all: a b

a: $(EJ4)a.s
	gcc -o $(EJ4)a.out -Wall -Werror -g $(EJ4)a.s

b: $(EJ4)b.s
	gcc -o $(EJ4)b.out -Wall -Werror -g $(EJ4)b.s

clean:
	rm *.out