#include <stdio.h>
#include <termios.h>
#define FD_STDIM 0
#define clear() printf("\033[H\033[J")
#define M 4

int validaPass(void)
{	clear();
	char tec=0, pswd [M];
	char valide[M] = {'t','d','i','i'};
	int i=0, count, trys=0;
	struct termios t_old, t_new;
	tcgetattr(FD_STDIM, &t_old); 
	t_new = t_old;
	t_new.c_lflag &= ~(ECHO | ICANON); // anulacion de entrada canónica y eco
	tcsetattr(FD_STDIM,TCSANOW,&t_new);
	do {
		 printf ("Ingrese password(%d dígitos): ", M);
		while (tec!=10){ 
	 		tec=getchar();
	 		count=0;
	             	if(tec == t_new.c_cc[VERASE] && i!=0){
	              		i--;
	              		printf("\b \b");
	    	      		pswd [i] = ' ';
			}

			else { if(tec!=10&&i<M){
				pswd [i]= tec;
				printf("*");
				i++;
		       	                   }
			     } 
		}		
		for(i=0;i<M;i++)
			if (pswd [i]==valide[i])
				count++;
		if (count == M){
			printf("\nUd. ha ingresado correctamente. Bienvenido al sistema.\n");
			return 1;
	                 	}
		else
			printf("\nPassword incorrecta.\n");
		
	tec = 0;
	i=0;	
	trys++;	
		
	}while(trys < 3 && count != M);
	tcsetattr(FD_STDIM, TCSANOW, &t_old); 
	printf("Se han registrado 3 intentos fallidos. Intente nuevamente en unos instantes...");
	return 0;
}


