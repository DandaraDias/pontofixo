#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *pf;

int SolucaoPontoFixo(double *x0, double prec)
{
	double x,i=0;

	pf = fopen("pontofixo.dat", "w");
	
	do{
		x = cos(*x0) ;
		prec = fabs(x - *x0);
		*x0 = x ;

		i += 1;			

		printf ("%g \t %g\n", *x0,i);
		fprintf(pf, "%g \t %g\n",i,*x0);
		
	}while (prec > 1e-5);
	
	fclose(pf);

	return(i);
}	

int main(int argc, char **argv)
{
	double x, x0, dx, prec;

	x0 = atof(argv[1]);
	prec = atof(argv[2]);

	printf("\nRaiz = %.10g em %d iterações \n", x0, SolucaoPontoFixo(&x0, prec));
		
	return 0;
}
