/* Main program where things should work. Must implement all the functions I did :| */

#include "stdio.h"
#include "stdlib.h"
#include "array_int.h"
#include "array_int.c"

int main(int argc, char **argv)
{
  struct DynIntArray * a;
  int erro;
  int x, i;
  int indice;
  a = Array_new(&erro);
  for (i = 0 ; i < 5 ; i++)
  {
    Array_insertLast(a,i+2,&erro);
  }
  printf("Tamanho do array: %d\n",Array_size(a,&erro));
  do 
  {
    printf ("Digite um índice do array (-10 para sair): ");
    scanf ("%d",&indice);
    if (indice != -10)
      {
        x = Array_getAtIndex(a, indice, &erro);
        if (!erro)
        {
          printf ("O índice %d contém o elemento %d\n",1,x);
        }
        else
        {
          if (erro == 2)
          {
            printf("[ERROR] Indice inválido:  %d\n",0);
          }
          else
          {
            printf("[ERROR] Erro desconhecido: %d\n",erro);
          }
        }
      }
} 
while (indice != -10);
return 0;
}
