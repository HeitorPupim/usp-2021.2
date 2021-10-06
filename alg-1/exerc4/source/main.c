#include <lista.h>
#include <util.h>
#include <big_number.h>
#include <string.h>



int main()
{
    int num_operacoes;
    //pegando o numero de operaçoes
    scanf("%d\n", &num_operacoes); // peguei as operações.
    char *operacao, *num_1 , *num_2;


    for (int i = 0; i < num_operacoes; i++)
    {
        //ler oq ele vai querer em cada linha
        operacao = readline(' ');
        num_1 = readline(' ');
        num_2 = readline('\n');

        
        printf(" %s| %s| %s| \n", operacao, num_1, num_2); 
        
        // lista_t *lista_num1,*lista_num2;
        // lista_num1 = cria();
        // lista_num2 = cria();

        //if operacao == soma -> criar outra lista
        // if tam lista 1 for igual q tam lista 2 &&
        // se o no do incio da lista 1 for maior q o no do in. da lista 2
        //entao eh maior, caso contrario menor...
        
        popularLista(num_1);

        free(operacao);
        free(num_1);
        free(num_2);
    }
    return 0;
}