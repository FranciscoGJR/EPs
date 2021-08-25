/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   94       - Luciano Digiampietri                               **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Francisco Oliveira Gomes Junior                               **/
/**                                                                 **/
/*********************************************************************/

/*  Calculo para raiz quadrada  */

#include <stdio.h>

double modulo(double number){
    if (number < 0) return number * -1;
    return number;
}

    //RAIZ QUADRADA COM METODO DE NEWTON
double raizQuadrada(double a, double epsilon) {
        // RETORNAR ERRO
    if(a < 0 || epsilon <= 0 || epsilon >= 1) return -1;
    if(a == 0) return 0;

    double xo, xi;

        //PRIMEIRA INTERACAO
    xo = a/2;

        //REPETITIVAS INTERACOES
    while(1){
        xi = (a/xo + xo)/2;

            //CONDICAO DE PARADA
        if (modulo(xi - xo) <= epsilon) return xi;

        xo = xi;
    }
}


int main() {
        //TESTES
printf("(64) (0.0001) = %f\n", raizQuadrada(64, 0.0001));
	printf("(25) (0.0001) = %f\n", raizQuadrada(25, 0.0001));
	printf("(124) (0.042) = %f\n", raizQuadrada(-4, 0.042));
	printf("(0) (-1) = %f\n", raizQuadrada(0, -1));
	printf("(626) (6) = %f\n", raizQuadrada(626, 6));
	printf("(34) (0.0001) = %f\n", raizQuadrada(34, 0.0001));
	return 0;
}
