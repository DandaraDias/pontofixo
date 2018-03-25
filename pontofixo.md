# Código

```
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
```

# Descrição do método

Este método é utilizado para se encontrar ponto fixos de funções. Em matemática, define-se ponto fixo como aquele que não é alterado por uma aplicação.
Existem diversas maneiras de usar o método para obter a raíz de uma função f(x). A ideia fundamental é reescrever a equação f(x) = 0 como uma equação equivalente da forma:

	x = g(x)

Se g(x) é uma função para a qual o método do ponto fixo converge, então a sequência:

![Equação](https://github.com/DandaraDias/pontofixo/blob/master/eq.png)

Com x0 como uma aproximação inicial da solução, converge para o ponto fixo x* da função g.

Pela sequência, podemos observar que a estimativa atual (n+1) depende da estimativa anterior (n).

# Resultados

![Gráfico](https://github.com/DandaraDias/pontofixo/blob/master/pontofixo.png)

Podemos observar que para os dois valores de x, ocorrem oscilações que eventualmente convergem para o resultado. Foi necessário limitar a extensão do gráfico para que fosse possível observar a oscilação para ambos os valores, já que para x=1.5 temos valores muito maiores.
