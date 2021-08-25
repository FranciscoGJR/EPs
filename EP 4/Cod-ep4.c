/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   94       - Luciano Digiampietri                               **/
/**                                                                 **/
/**   Quarto Exercicio-Programa                                     **/
/**                                                                 **/
/**   Francisco Oliveira Gomes Junior                               **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>

#define dividaMaxima 30000
#define dividaMaximaEspecial 50000

#define true 1
#define false 0

typedef int bool;

typedef struct{
	char* nome;
	int cpf;
} PESSOA;


typedef struct{
	PESSOA pessoa;
	char tipo;
	int valorContaCorrente;
	int valorDaDivida;
} CLIENTE;


typedef struct{
	PESSOA pessoa;
	CLIENTE* clientes[20];
	int numClientes;
} GERENTE;


typedef struct{
	GERENTE* gerentes[10];
	int numGerentes;
} BANCO;


/********************** FUNCOES PARA CRIAR CLIENTES, GERENTES OU BANCOS ******/


/* Funcao para a criacao de um novo cliente.
   A funcao preenche todos os valores de seus campos e retorna esse novo cliente.
*/
CLIENTE novoCliente(char* nome, int cpf, int valorInicial){
	CLIENTE novo;
	novo.pessoa.nome = nome;
	novo.pessoa.cpf = cpf;
	novo.valorContaCorrente = valorInicial;
	novo.valorDaDivida = 0;
	novo.tipo = 'C';
	return novo;
}

/* Funcao para a criacao de um novo cliente especial.
   A funcao preenche todos os valores de seus campos (utilizando a funcao novoCliente)
   e retorna esse novo cliente especial.
*/
CLIENTE novoClienteEspecial(char* nome, int cpf, int valorInicial){
	CLIENTE novo = novoCliente(nome,cpf,valorInicial);
	novo.tipo = 'E';
	return novo;
}

/* Funcao para a criacao de um novo gerente.
   A funcao preenche os valores de seus campos e retorna esse novo gerente.
*/
GERENTE novoGerente(char* nome, int cpf){
	GERENTE novo;
	novo.pessoa.nome = nome;
	novo.pessoa.cpf = cpf;
	novo.numClientes = 0;
	return novo;
}

/* Funcao para a criacao de um novo banco.
   A funcao preenche os valores de seus campos e retorna esse novo banco.
*/
BANCO novoBanco(){
	BANCO novo;
	novo.numGerentes = 0;
	return novo;
}





/********************** FUNCOES DOS CLIENTES *********************************/

bool negativado(CLIENTE* c1) {

    if(c1->valorContaCorrente < c1->valorDaDivida)
        return true;

	return false;
}


bool obterEmprestimo(CLIENTE* c1, int valor) {
    if(valor <= 0) return false;
    int soma = valor + c1->valorDaDivida;

	if(c1->tipo == 'C' && soma > dividaMaxima)
        return false;
    if(c1->tipo == 'E' && soma > dividaMaximaEspecial)
        return false;

    c1->valorDaDivida = c1->valorDaDivida + valor;
    c1->valorContaCorrente = c1->valorContaCorrente + valor;
    return true;
}


bool pagarEmprestimo(CLIENTE* c1, int valor) {

	if(valor <= 0 || valor > c1->valorDaDivida || valor > c1->valorContaCorrente) return false;

    c1->valorDaDivida = c1->valorDaDivida - valor;
    c1->valorContaCorrente = c1->valorContaCorrente - valor;
	return true;
}


bool realizarSaque(CLIENTE* c1, int valor) {

    //if(valor <= 0) return false;
	if(valor > c1->valorContaCorrente || valor <= 0) return false;

    c1->valorContaCorrente = c1->valorContaCorrente - valor;
    return true;
}




/********************** FUNCOES DOS GERENTES *********************************/


bool adicionarCliente(GERENTE* g1, CLIENTE* cliente) {
	if (g1->numClientes == 20) return false;
	int x;
	for (x=0;x<g1->numClientes;x++){
		if (g1->clientes[x]->pessoa.cpf == cliente->pessoa.cpf) return false;
	}
	g1->clientes[g1->numClientes] = cliente;
	g1->numClientes++;
	return true;
}


void cobrarTodosEmprestimos(GERENTE g1) {
	CLIENTE* atual;
	int c;
	for (c=0; c < g1.numClientes; c++){
		atual = g1.clientes[c];
		if (atual->valorDaDivida > 0){
			if (atual->valorContaCorrente >= atual->valorDaDivida){
				atual->valorContaCorrente -= atual->valorDaDivida;
				atual->valorDaDivida = 0;
			}else{
				atual->valorDaDivida -= atual->valorContaCorrente;
				atual->valorContaCorrente = 0;
			}
		}
	}
}



/* Funcao para imprimir informacoes sobre os clientes gerenciados por ger1 */
void imprimirClientes(GERENTE ger1){
	CLIENTE* atual;
	int c;
	printf("\tNumero de clientes: %i\n", ger1.numClientes);
	for (int c=0; c < ger1.numClientes; c++){
		atual = ger1.clientes[c];
		printf("%4i %c %s\t%11i %8i %8i %i\n", c+1, atual->tipo, atual->pessoa.nome, atual->pessoa.cpf, atual->valorContaCorrente, atual->valorDaDivida, negativado(atual));
	}
}




/********************** FUNCOES DOS BANCOS ***********************************/

bool adicionarGerente(BANCO* b1, GERENTE* gerente){
	if(b1->numGerentes == 10) return false;

	int c;
	for(c = 0; c < b1->numGerentes; c++){
        if(b1->gerentes[c]->pessoa.cpf == gerente->pessoa.cpf) return false;
	}
	b1->gerentes[b1->numGerentes] = gerente;
	b1->numGerentes = b1->numGerentes + 1;
	return true;
}



/* Funcao para imprimir informacoes gerais sobre o banco b1 (passado como parametro) */
void imprimirDadosBanco(BANCO b1){
	printf("#########################################################################\n");
	printf("Imprimindo informacoes do banco.\n");
	printf("Ha %i gerente(s) neste banco.\n",b1.numGerentes);
	GERENTE* ger;
	for (int g=0; g < b1.numGerentes; g++){
		ger = b1.gerentes[g];
		printf("Gerente: %s\tCPF: %i\n", ger->pessoa.nome, ger->pessoa.cpf);
		imprimirClientes(*ger);
	}
	printf("#########################################################################\n");
}




int main(){

	return 0;
}
