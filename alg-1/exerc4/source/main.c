#include <lista.h>
#include <util.h>
#include <big_number.h>



int main()
{
    int num_operacoes;
    //pegando o numero de operaçoes
    scanf("%d\n", &num_operacoes); // peguei as operações.
    char *operacao, *num_1 , *num_2;
    for (int i = 0; i < num_operacoes; i++)
    {
        operacao = readline(' ');
        num_1 = readline(' ');
        num_2 = readline('\n');

        printf(" %s| %s| %s| \n", operacao, num_1, num_2); 
        free(operacao);
        free(num_1);
        free(num_2);
    }
    
    return 0;
}