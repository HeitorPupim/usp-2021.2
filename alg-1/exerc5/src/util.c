#include <util.h>

char* readline(char parada)
{
    char* linha = NULL;
    char tmp;
    int count = 0;

    do
    {
        tmp = getchar();
        if (tmp == '\r') tmp = getchar(); // para ignorar o \r do windows
        if (count % BUFFER == 0) 
        {
            linha = realloc(linha, sizeof(char)*(count + BUFFER));
        }
        if (tmp != parada) 
        {
            linha[count++] = tmp; 
        }
    } while (tmp != parada || tmp == EOF);

    linha[count] = '\0'; 
    
    return linha;
}

char *readCPF(char parada) //O CPF termina quando é lido o primeiro;
{
    char* linha = NULL;
    char tmp;
    int count = 0;

    do
    {
        tmp = getchar();
        if (tmp == '\r') tmp = getchar(); // para ignorar o \r do windows
        if (tmp == '.') tmp = getchar();
        if (tmp == '-') tmp = getchar();
        if (count % BUFFER == 0) 
        {
            linha = realloc(linha, sizeof(char)*(count + BUFFER));
        }
        if (tmp != parada) 
        {
            linha[count++] = tmp; 
        }
    } while (tmp != parada || tmp == EOF);

    linha[count] = '\0'; 
    
    return linha;   
}
