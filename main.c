#include <stdio.h>
#include <stdlib.h>
#include "Tokens.h"
#include "pila.h"
#include "lista.h"
#include "posfija.h"

void imprimir(TInfo t);

int main() {
//    char cadena[] = "( 36.5 *(   23.4- 2))^2\n       ";
    char cadena[] = "total = (( prueba+23)^3 -(33+23*44))^(x/3) ";
    TToken *p;
    TLista *listaPosfija;
    TLista *listaInfija = nuevaLista();

    p = token(cadena);
    while (p != NULL) {
       agregarNodo(listaInfija,*p);
       p = token(NULL);
    }
    printf("***** tokens antes de funcion posfija*******\n");
    itera(*listaInfija,imprimir);

    listaPosfija = posfija(listaInfija);

    printf("\n\n***** tokens de entrada despues de la funcion posfija *******\n");
    itera(*listaInfija,imprimir);
    printf("\n\n***** tokens de salida *******\n");
    itera(*listaPosfija,imprimir);
    printf("\n\nfin");
    return 0;
}

void imprimir(TInfo t) {
    printf("[%s %s]",strToken[t.tipo],t.token);
}
