#include <stdio.h>
void Sacar_media(float *Temp, int num, float *promedio);
void Ordenar_men_a_may(float *Temp, int num);
void Impresion(float *Temp, float promedio, int num);
void Mayor_a_media(float *Temp, int num, float promedio); 


int main (void)
{
  int r,num, i;
  float Temp[100], promedio;
  printf("\nDame un número entre el 3 y el 100: ");
  scanf("%d", &num);
  while(num<3 || num>100)
    {
      printf("Insertaste un valor erroneo, procura que el número este entre 3 y 100.\nInserta el numero otra vez: ");
      scanf("%d", &num);	
    }
  num--;
  for(i=0; i<=num; i++)
    {
      r=i+1;
      printf("Dame %d temperatura: \n", r);
      scanf("%f", &Temp[i]);
    }
  Ordenar_men_a_may(Temp, num);
  Sacar_media(Temp, num, &promedio);
  Mayor_a_media(Temp,num, promedio);
  Impresion(Temp, promedio, num);
}

void Ordenar_men_a_may(float *Temp, int num)
{
  int i,j;
  float temporal;
  for(i=0; i<=num; i++)
    {
      for(j=num; j>i; j--)
	{
	  if(Temp[i]>Temp[j])
	    {
	      temporal=Temp[i];
	      Temp[i]=Temp[j];
	      Temp[j]=temporal;
	    }
	}
    }
}

void  Sacar_media(float *Temp, int num, float *promedio)
{
  int i;
  float acomulado=0;
  for(i=0; i<=num; i++)
    {
      acomulado=Temp[i]+acomulado;
    }
  *promedio=acomulado/num;
}

void Mayor_a_media(float *Temp, int num, float promedio)
{
  int i;
  printf("\nLas temperaturas mayores o iguales a la media son: ");
    for(i=0; i<=num; i++)
      {
	if(Temp[i]>=promedio)
	  {
	    printf(" %f ", Temp[i]);
	  }
      }
}

void Impresion(float *Temp, float promedio, int num)
{
  int i;
  printf("\nLa lista de temperaturas en orden acendente es: ");
  for(i=0; i<=num; i++)
    {
      printf(" %f",Temp[i]); 
    }
  printf("\nEl promedio de las temperaturas es:%f\n", promedio);
}
