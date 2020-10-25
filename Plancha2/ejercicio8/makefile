EJ8 = ej8

all: a b

a: $(EJ8)a.s
	gcc -o $(EJ8)a.out -Wall -Werror -g -no-pie $(EJ8)a.s

b: $(EJ8)b.s
	gcc -o $(EJ8)b.out -Wall -Werror -g -no-pie $(EJ8)b.s

clean:
	rm *.out