#include<stdio.h>
#include<stdlib.h>

void Ubicar_centro(int matriz[2][2] , int nr);
void Relleno_matriz(int matriz[2][2],int n,int nr);
void Verificar_n(int *n);
void Despliegue(int matriz[2][2], int n);

int main (void)
{
  int n=0, nr, matriz[2][2]; //nr es porque n empieza en 0 y acaba en n-1, entonces para utlilizarlo, usaremos nr.
  Verificar_n(&n);
  while(n%2==0 || n>11 || n<3)
    {
      printf("cometiste un error ingresando los datos, favor de volver a intentar, presiona <enter> para continuar");
      getchar();
      Verificar_n(&n);	
    }
  nr=n-1;
  Ubicar_centro(matriz, nr);
  Relleno_matriz(matriz, nr,n);
  Despliegue(matriz, n);
}
void Verificar_n(int *n)
{
  printf("\nDame las dimensiones que deseas de la tabla mágica, recuerda que solo se puede del 3 al 11, y que sea impar: ");
  scanf("%d", n);
}
void Ubicar_centro(int matriz[2][2], int nr)
{
  matriz[nr/2][0]=1;
}

void Relleno_matriz(int matriz[2][2],int n,int nr)
{
  int i,x=0,y=0, num=2, flag=0;
  for(i=1; i<=n*n;  i++)
    {
      if(n%i==0)
	{
	  matriz[x][y+1]=num;
	}
      else
	{
	  if(flag==0) 
	    {
	      x=(nr/2) + 1;
	      flag=1;
	    }
	  else
	    {
	      x=x+1;
	    }
	  y=y-1;
	  if(x>nr)
	    {
	      x=0;
	    }
	  if(y<0)
	    {
	      y=nr;
	    }
	  matriz[x][y]=num;	
	}
      num++;
    }
}

Despliegue(int matriz[2][2], int n)
{
  int x,y;
  for (x=0; x<n; x++)
    {
      for(y=0; y<n; y++)
	{
	  printf("%d", matriz[y][x]);
	}  
		printf("\n");
    }
}

