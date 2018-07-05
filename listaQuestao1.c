#include <stdio.h>
#include <malloc.h>

//definir lista
int tamlista = 0;

typedef struct entralista {
    char conteudo;
} listacaracter;

typedef struct aux {
    listacaracter reg;
    struct aux* prox;
} Lista, *pontlista;



void iniciarLista(Lista** l) {
    *l = NULL;
    tamlista = 0;
}

int tamanhoLista(Lista** l) {
    pontlista end = *l;
    int tam = 0;

    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

bool inserirLista(Lista** f, listacaracter p) {
    pontlista novo = (pontlista) malloc(sizeof (listacaracter));
    novo->reg = p;
    novo->prox = NULL;

    if (*f == NULL) *f = novo;
    else {
        Lista *aux = *f;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }


    tamlista++;

    return true;
};


void exibirLista(Lista** l) {
    pontlista end = *l;

    printf("Lista: ");
    while (end != NULL) {
        printf("%c", end->reg.conteudo);
        end = end->prox;
    }
    printf("\n");

}

bool excluirLista(Lista **p, listacaracter e) {
    pontlista aux;

    if (*p == NULL) {
        printf("Lista vazia\n");
        return false;
    }
    else {
        if((*p)->reg.conteudo==e.conteudo){
            aux=*p;
            *p=(*p)->prox;
            printf("%c\n",(aux)->reg.conteudo);
            free(aux);      
            tamlista--;
        }else excluirLista(&(*p)->prox,e);
      return true;      
    }
}



bool procuraNull(Lista **f){
    if(*f==NULL){
        return true;
    }else{
        return procuraNull(&(*f)->prox);
    }
}


//definir fila
int tamfila = 0;

typedef struct entrafila {
    char letra;
} filacaracter;

typedef struct aux1 {
    filacaracter entrada;
    struct aux1* prox;
} elemento, *pont;

typedef struct {
    pont inicio;
    pont fim;
} Fila;

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
    tamfila = 0;
};

void exibirFila(Fila* f) {
    pont end = f->inicio;
    printf("A fila eh:");
    while (end != NULL) {
        printf("%c", end->entrada);
        end = end->prox;
    };
    printf("\n");
};

int vazia(Fila *LISTA) {
    if (LISTA->inicio == NULL)
        return 1;
    else
        return 0;
}

bool inserirNafila(Fila* f, filacaracter p) {
    pont novo = (pont) malloc(sizeof (pont));
    novo->entrada = p;
    novo->prox = NULL;

    if (f->inicio == NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    tamfila++;

    return true;
};







//definir pilha
int tampilha = 0;

typedef struct pilhaentrada {
    char num;
} pilhacaracter;

typedef struct pilha {
    pilhacaracter entrada;
    struct pilha* prox;
} elepilha, *pontpilha;

typedef struct {
    pontpilha topo;
} Pilha;

void iniciaPilha(Pilha** p) {
    (*p)->topo = NULL;
    if((*p)->topo==NULL){
        printf("pilha iniciada: %x\n",(*p)->topo);
    }
    tampilha = 0;
}

void tamanhoPilha(Pilha* p) {
    pontpilha end = p->topo;
    int tam = 0;

    while (end != NULL) {
        tam++;
        end = end->prox;
    }
}

bool pilhavazia(Pilha** p) {
    if ((*p)->topo == NULL) return true;
    return false;
}

void exibirPilha(Pilha** p) {
    pontpilha end = (*p)->topo;
    printf("Pilha: ");
    while (end != NULL) {
        printf("%c ", end->entrada.num);
        end = end->prox;
    }
    printf("\n");
}

bool inserirPilha(Pilha **p, pilhacaracter reg) {
    pontpilha novo = (pontpilha) malloc(sizeof (pontpilha));
    novo->entrada = reg;
    novo->prox = (*p)->topo;
    (*p)->topo = novo;
    tampilha++;
    return true;
}

bool ehnumero(Lista *f, Pilha **p){
    listacaracter aux;
    pilhacaracter aux2;
    char pilhaaux;
    
    if (f->reg.conteudo>='0'&&f->reg.conteudo<='9') {
        aux=f->reg;
        pilhaaux=f->reg.conteudo;
        aux2.num=pilhaaux;
        inserirPilha(p,aux2);
        exibirPilha(p);
        exibirLista(&f);
        return true;
    }
    return false;
}

int main() {
    
    //lista para trabalhar
    Lista *lista;
    char entrada[10]={'d','7','3','f','7','t','1','9','5','2'};
    listacaracter dados;
    int i=0;
    iniciarLista(&lista);
    while(i<10){
        dados.conteudo= entrada[i];
        inserirLista(&lista,dados);
        i++;
    }
    exibirLista(&lista);
    
    Pilha *pilha;
    iniciaPilha(&pilha);
    exibirPilha(&pilha);

    while(lista!=NULL){
        ehnumero(lista,&pilha);
        lista=lista->prox;
    }
    
    exibirLista(&lista);
    
    return 0;
};
