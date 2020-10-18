#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* codificar (char *cadena, int codigo){
  char *cadenaCodificada = malloc (sizeof(char) * (strlen(cadena) + 1));
  int i = 0;
  for (; cadena[i]; i++) cadenaCodificada[i] = cadena[i] ^ codigo;
  cadenaCodificada[i] = '\0';
  return cadenaCodificada;
}

int main (int argc, char* argv[]) {
  if (argc == 2) {
    int codigo = atoi (argv[1]);
    char entrada[200], caracter;
    int i = 0;
    printf ("Ingrese lo que sea codificar: ");
    for (; (caracter = getchar()) != '\n'; ++i) entrada[i] = caracter;
    entrada[i] = '\0';
    char *entradaCodificada = codificar (entrada, codigo);
    printf ("Codificacion: %s\n", entradaCodificada);
    free (entradaCodificada);
  }
  else printf ("No se ingreso la cantidad correcta de argumentos\n");
}

// Para que el programa decodifique simplemente tendria que aplicarse nuevamente
// la funcion codificar. Una funcion decodificar se veria asi:
/* char* decodificar (char *cadena, int codigo) {
  char* aux = cadena;
  char* cadenaDecodificada = codificar (cadena, codigo);
  free (aux);
  return cadenaDecodificada;
}
*/

// No habria ninguna ganancia en codificar mas de una vez ya que codificando dos veces
// nos devuelve la misma cadena. Esto es lo que sucede: (cadena ^ codigo) ^ codigo = 
// cadena ^ (codigo ^ codigo) = cadena ^ 0 = cadena.