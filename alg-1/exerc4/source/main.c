#include <lista.h>
#include <util.h>
#include <big_number.h>
#include <string.h>
#include <string.h>

int main()
{
    //pegando o numero de operaçoes
    int num_operacoes;
    
    scanf("%d\n", &num_operacoes);
    char *operacao, *num_1 , *num_2;


    for (int i = 0; i < num_operacoes; i++)
    {
        
        operacao = readline(' ');

        num_1 = readline(' ');
        num_2 = readline('\n');
        
        lista_t *lista_num_1 = cria();
        lista_t *lista_num_2 = cria();
        
        int tamanho_lista_1 = (int)strlen(num_1); 
        int tamanho_lista_2 = (int)strlen(num_2);

        for (int i = 0; i < tamanho_lista_1; i++)
        {   
            int valor;

            valor = ((int)num_1[i] - 48); // tabela ascii todos os numeros começam no 48
            
            insertInicio(lista_num_1, valor);
        }

        for (int i = 0; i < tamanho_lista_2; i++)
        {
            int valor;
            
            
            valor = ((int)num_2[i] - 48); // tabela ascii todos os numeros começam no 48
            insertInicio(lista_num_2, valor);
        }

        if(!strcmp(operacao, "soma")) 
        {
            lista_t *listaSoma = cria();

            soma(lista_num_1, lista_num_2, listaSoma);
            printf("Resultado :: ");
            imprimir(listaSoma);


            destroi(listaSoma);

        }
        
        if(!strcmp(operacao, "menor"))
        {
            int res = menor(lista_num_1, lista_num_2);
            if(res == 1) printf("Resultado :: True\n");
            else printf("Resultado :: False\n");
        }
         
        if(!strcmp(operacao, "maior")) 
        {
            int res = maior(lista_num_1, lista_num_2);
            if(res == 1) printf("Resultado :: True\n");
            else printf("Resultado :: False\n");
        }
        if(!strcmp(operacao, "igual")){ 
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