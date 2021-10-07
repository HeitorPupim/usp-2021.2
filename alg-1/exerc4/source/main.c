#include <lista.h>
#include <util.h>
#include <big_number.h>
#include <string.h>
#include <string.h>

int main()
{
    int num_operacoes;
    //pegando o numero de operaçoes
    scanf("%d\n", &num_operacoes); // peguei as operações.
    char *operacao, *num_1 , *num_2;


    for (int i = 0; i < num_operacoes; i++)
    {
        //printf("-----------------------------------\n");
        //printf("Operaçao %d\n", i+2);
        //ler oq ele vai querer em cada linha
        operacao = readline(' ');

        //-> fazer uma funçao de ler o tamanho da string
        // getchar() -> ungetchar(stdin) se for != ' ', para
        // utiliza um count pra ver quantas vezes pegou caractere
        // se tiver 9 digitos, vou fazer um 9%4, que me dá 1
        // daí eu leio 1, depois leio de 4 em 4, e ele chega no fim..

        //num_1 = lerLinha(4,' ');
        //
        //num_2 = lerLinha(4,' ');
    	

        num_1 = readline(' ');
        num_2 = readline('\n');
        
        //printf(" %s| %s| %s| \n", operacao, num_1, num_2); 

        
        lista_t *lista_num_1 = cria();
        lista_t *lista_num_2 = cria();
        
        int tamanho_lista_1 = (int)strlen(num_1); 
        int tamanho_lista_2 = (int)strlen(num_2);

        //printf("tamanho da lista 1: %d\n", tamanho_lista_1);
        //printf("tamanho da lista 2: %d\n", tamanho_lista_2);
        for (int i = 0; i < tamanho_lista_1; i++)
        {   
            int valor;
            //printf("char a ser transf: %c\n", num_1[i]);

            valor = ((int)num_1[i] - 48); // tabela ascii todos os numeros começam no 48
            //printf("valor = %d\n",valor);
            insertInicio(lista_num_1, valor);
        }
        for (int i = 0; i < tamanho_lista_2; i++)
        {
            int valor;
            //printf("char a ser transf: %c\n", num_2[i]);
            
            valor = ((int)num_2[i] - 48); // tabela ascii todos os numeros começam no 48
            //printf("valor = %d\n",valor);
            // sinal de '-'= -3.
            insertInicio(lista_num_2, valor);
        }
        //imprimir(lista_num_1);
        //imprimir(lista_num_2);
        // aqui precisa fazer as operações....

        if(!strcmp(operacao, "soma")) 
        {
            lista_t *listaSoma = cria();

            //printf("OP = soma \n");
            soma(lista_num_1, lista_num_2, listaSoma);
            printf("Resultado :: ");
            imprimir(listaSoma);


            free(listaSoma);

        }
        
        if(!strcmp(operacao, "menor"))
        {
            //printf("OP = menor \n");
            int res = menor(lista_num_1, lista_num_2);
            if(res == 1) printf("Resultado :: True\n");
            else printf("Resultado :: False\n");
        }
         


        if(!strcmp(operacao, "maior")) 
        {
            //printf("OP = maior \n");
            int res = maior(lista_num_1, lista_num_2);
            if(res == 1) printf("Resultado :: True\n");
            else printf("Resultado :: False\n");
        }
        if(!strcmp(operacao, "igual")){ 
            //printf("OP = igual \n");
            int res = igual(lista_num_1, lista_num_2);
            if(res == 1) printf("Resultado :: True\n");
            else printf("Resultado :: False\n");
        }
        

        destroi(lista_num_1);
        destroi(lista_num_2);
        free(operacao);
        free(num_1);
        free(num_2);
    }
    return 0;
}