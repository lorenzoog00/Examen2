#include <stdio.h>
void segs_a_mins(int *acosegs, int *acomins);
void mins_a_hrs(int *horas, int *acomins);
void despliegue(int horas,int acomins, int acosegs);
//void Validacion(int argc, char *argv, int *acomins, int *acosegs, int *flag);

void main(int argc, char*argv[])
{
  int acosegs, acomins, horas, flag=0;
  int i, mins, segs;
  acomins=0;
  acosegs=0;
  for(i=1; i<argc; i++)
    {
      sscanf(argv[i],"%d:%d", &mins, &segs);
      if(mins>60 || segs>60 || mins<0 || segs<0)
	{
	  flag=1;
	}
      else
	{
	  acosegs= acosegs + segs;
	  acomins= acomins + mins;
	}
    }

  //Validacion(argc, argv, &acomins, &acosegs, &flag);
  if(flag==1)
    {
      printf("Cometiste un error al ingresar los datos, por favor vuelve a intentarlo\n");
    }
  else
    {
      segs_a_mins(&acosegs, &acomins);
      mins_a_hrs(&horas, &acomins);
      despliegue(horas, acomins, acosegs);
    }
}
/*
void Validacion(int argc,char *argv, int *acomins,int *acosegs, int *flag)
{ 
  int i, mins, segs;
  *acomins=0;
  *acosegs=0;
  for(i=0; i<=argc; i++)
    {
      sscanf(argv[i]; “%d:%d”; &mins, &segs);
      if(mins>60 || segs>60 || mins<0 || segs<0)
	{
	  *flag=1;
	}
      else
	{
	  *acosegs= *acosegs + segs;
	  *acomins= *acomins + mins;
	}
    }
}
*/
void segs_a_mins(int *acosegs, int *acomins)
{
  int temp, miins, seegs; 
  temp = *acosegs/60;
  *acomins= *acomins + temp;
  temp= temp * 60;
  *acosegs= *acosegs-temp;
  miins=*acomins;
  seegs=*acosegs;
  if(temp==0)
    {
      //*acomins=00;
    }
  printf( "Formato mm:ss %d:%d\n", miins, seegs);
  
}


void mins_a_hrs(int *horas, int *acomins)
{
  int temp;
  *horas=0;
  temp = *acomins/60;
  *horas= *horas + temp;
  temp= temp * 60;
  *acomins= *acomins-temp;
  if(temp==0)
    {
      *horas=00;
    }
}
void despliegue(int horas,int acomins,int acosegs)
{
  printf("formato hh:mm:ss %d:%d:%d\n", horas,acomins,acosegs);
}

