#include <lista.h>

typedef struct no_st no_t;

struct no_st { //bignumber
    num info;
    int carry;
    no_t *prox;
};

struct lista_st {
    no_t *ini, *fim;
    int tam;
};


// Aloca espaço para a lista e define os parâmetros iniciais.
lista_t *cria() {
    lista_t *lista = malloc(sizeof(lista_t));

    lista->tam = 0;
    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

/* Desaloca o espaço reservado para cada nó
 * da lista e o espaço da própria lista.
 */
void destroi(lista_t *lista) {
    if (lista == NULL) return;
    no_t *p = lista->ini;
    while (p != NULL) {
        lista->ini = p->prox;
        free(p);
        p = lista->ini;
    }
    free(lista);
}

//inserir início da lista
void insertInicio(lista_t *lista, num x)
{
    no_t *novo = (no_t*)malloc(sizeof(no_t));
    novo->info = x;

    if (lista->ini == NULL)
    {
        novo->prox = NULL;
        lista->ini = novo;
        lista->fim = novo;
    }else{
        novo->prox = lista->ini;
        lista->ini = novo;
    }
    lista->tam++;
}

/* Aloca espaço para um nó, seta os parâmetros
 * desse nó e insere no final da lista, fazendo
 * as devidas verificações.
 * Incrementa o tamanho da lista ao inserir esse novo nó.
 */
void insertFim(lista_t *lista, num x) {
    if (lista == NULL) return;
    
    no_t *p = malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;

    if (lista->ini == NULL)
        lista->ini = p;
    else
        lista->fim->prox = p;

    lista->fim = p;
    lista->tam++;
}

/* Remove um nó da lista, independentemente da posição
 * dele na lista.
 * Procura o primeiro nó que contém esse valor, libera a memória
 * reservada para ele, e diminui o tamanho da lista.
 */
void remover(lista_t *lista, num x) {
    if (lista == NULL) return;
    no_t *anterior = NULL;
    no_t *p = lista->ini;

    while (p != NULL) {
        if (p->info == x) {
            if (p == lista->ini) {
                lista->ini = lista->ini->prox;
            } else if (p == lista->fim) {
                lista->fim = anterior;
                lista->fim->prox = NULL;
            } else {
                anterior->prox = p->prox;
            }
            free(p);
            lista->tam--;
            
            return; // Se removeu
        } else {
            anterior = p;
            p = p->prox;
        }
    }
}

//Retorna o tamanho da lista
int tamanho(lista_t *lista) {
    if (lista != NULL) return lista->tam;

    return -1;
}

//Imprime o conteúdo de todos os nós da lista.
void imprimir(lista_t *lista) {
    if (lista == NULL) return;
    no_t *p = lista->ini;

    while (p != NULL) {
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");
}

//Retorna 1 se estiver e 0 se não estiver.
int esta_na_lista(lista_t *lista, int x) {
    if (lista == NULL) return -1;

    no_t *p = lista->ini;
    while (p != NULL) {
        if (p->info == x) return 1;

        p = p->prox;
    }
    return 0;
}

//Retorna o elemento da posiçao que for passada no parâmetro
int encontrarPosicao(lista_t *lista, int pos) {
    int contador = 1;

    no_t *p = lista->ini;

    while (p != NULL && contador <= pos) {
        if (contador == pos) return p->info; //me retorna o numero.
        p = p->prox;
        contador++;
    }
    return 0;
}

//opercaçao de igual
int igual(lista_t *lista_1,lista_t *lista_2)
{
    int tamLista1 = lista_1->tam;
    int tamLista2 = lista_2->tam;
    int count = 0;

    if(tamLista1 == tamLista2) // se o tamanho da lista for igual,
    {
        while (count <= tamLista1)
        {
            if(encontrarPosicao(lista_1,count) != encontrarPosicao(lista_2,count))
            return 0;//false
            count++;
        }
        return 1; //true;

    }else return 0; //false
}

int maior(lista_t *lista_1,lista_t *lista_2)
{
    int tamLista1 = lista_1->tam;
    int tamLista2 = lista_2->tam;

    // caso 1: se o tamanho for igual, verifica só o primeiro numero
    if((tamLista1 == tamLista2) && ((encontrarPosicao(lista_1,tamLista1)) > (encontrarPosicao(lista_2,tamLista2))))
    return 1; //true

    // caso 2: e o tamanho for igual e a posiçao da frente for maior
    
    else if(((tamLista1 == tamLista2)))
    {
        int count = tamLista1;
        while (encontrarPosicao(lista_1, count) == encontrarPosicao(lista_2, count))
        {
            count--;
        }
        if((encontrarPosicao(lista_1,count)) > (encontrarPosicao(lista_2,count)))
        return 1;
        else return 0;
        
    }
    /* caso 3: compara positivo com negativo
        é maior se o tamanho for diferete (e) os primeiros forem 
        diferentes (e) o primeiro da 2 for -3
    */
    else if ((tamLista1 != tamLista2) && ((encontrarPosicao(lista_2,tamLista2)) == -3) && ((encontrarPosicao(lista_1,tamLista1)) != (encontrarPosicao(lista_1,tamLista2))))
    {
        //printf("primeiro eh -3\n");
        return 1; //true
    }
    /* caso 4: compara positivo com negativo
        é menor se o tamanho for diferete (e) os primeiros forem 
        diferentes (e) o primeiro da 1 for -3
    */
    else if ((tamLista1 != tamLista2) && ((encontrarPosicao(lista_1,tamLista1)) == -3) && ((encontrarPosicao(lista_1,tamLista1)) != (encontrarPosicao(lista_1,tamLista2))))
    {
        //printf("primeiro eh -3\n");
        return 0; //false
    }
    /* caso 5: tamanhos do 1 for maior que o tamanho de 2, entao eh maior
    */
    else if (tamLista1 > tamLista2) return 1; //true
    else return 0; //false
}

int menor(lista_t *lista_1,lista_t *lista_2)
{
    int tamLista1 = lista_1->tam;
    int tamLista2 = lista_2->tam;
    
    // caso 1: se o tamanho for igual, verifica só o primeiro numero

    if((tamLista1 == tamLista2) && ((encontrarPosicao(lista_1,tamLista1)) < (encontrarPosicao(lista_2,tamLista2))))
    return 1;
    // caso 2: e o tamanho for igual e a posiçao da frente for menor
    
    else if(((tamLista1 == tamLista2)))
    {
        int count = tamLista1;
        while (encontrarPosicao(lista_1, count) == encontrarPosicao(lista_2, count))
        {
            count--;
        }
        if((encontrarPosicao(lista_1,count)) < (encontrarPosicao(lista_2,count)))
        return 1;
        else return 0;
        
    }

    /* caso 3: compara numero negativo com positivo
        é menor se o tamanho for diferete (e) os primeiros forem 
        diferentes (e) o primeiro da 1 for negativo
    */
    else if ((tamLista1 != tamLista2) && ((encontrarPosicao(lista_1,tamLista1)) == -3) && ((encontrarPosicao(lista_1,tamLista1)) != (encontrarPosicao(lista_1,tamLista2))))
    {
        return 1; //true
    }

    /* caso 4: compara positivo com negativo
        é maior se o tamanho for diferete (e) os primeiros forem 
        diferentes (e) o primeiro da 2 for negativo
    */
   else if ((tamLista1 != tamLista2) && ((encontrarPosicao(lista_2,tamLista2)) == -3) && ((encontrarPosicao(lista_1,tamLista1)) != (encontrarPosicao(lista_1,tamLista2))))
    {
        return 0; //false
    }

    /* caso 5: tamanhos do 1 for maior que o tamanho de 2, entao eh maior
    */
    else if (tamLista1 < tamLista2) return 1; //true
    else return 0; //false
}

//funçao que me retorna o resultado da soma
void soma(lista_t *lista_1,lista_t *lista_2, lista_t *listaSoma)
{
    int tamLista1 = lista_1->tam;
    int tamLista2 = lista_2->tam;
    int maior = 0;
    int soma = 0;
    int carry = 0;
    int valLista1, valLista2;

    if(tamLista1 >= tamLista2)   maior = tamLista1; 
    else maior = tamLista2;
    for (int i = 1; i <= maior+1; i++)
    {   
        valLista1 = encontrarPosicao(lista_1, i+1);
        valLista2 = encontrarPosicao(lista_2, i+1);
        soma = carry + encontrarPosicao(lista_1, i) + encontrarPosicao(lista_2, i);
        if(soma >= 10)  carry = 1;
        else carry = 0;
        if((soma == 0) && valLista2 == 0 && valLista1 == 0) break;
        insertInicio(listaSoma, soma % 10);
    }
}

void ImprimirResultado(char* operacao, lista_t *lista_num_1, lista_t *lista_num_2)
{
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
}

