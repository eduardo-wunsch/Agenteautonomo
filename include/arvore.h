#ifndef ARVORE_H
#define ARVORE_H

#include <stddef.h>

#define MAX_FILHOS 10
#define MAX_PALAVRA_CHAVE 50
#define MAX_RESPOSTA 500

/* Cada nó pode ter vários filhos, que são outros nós da árvore. */
typedef struct NoArvore {
    char palavra_chave[MAX_PALAVRA_CHAVE];
    char resposta[MAX_RESPOSTA];
    struct NoArvore *filhos[MAX_FILHOS];
    size_t quantidade_filhos;
} NoArvore;

/* Cria um nó com uma palavra-chave e uma resposta. */
NoArvore *criar_no(const char palavra_chave[],
                   const char resposta[]);

/* Liga um nó filho a um nó pai. Retorna 1 se conseguiu. */
int adicionar_filho(NoArvore *pai, NoArvore *filho);

/* Monta a árvore inicial de assuntos e respostas. */
NoArvore *criar_arvore_atendimento(void);

/* Busca a pergunta na árvore. Retorna 1 se encontrar resposta. */
int consultar_arvore(const NoArvore *raiz,
                     const char pergunta[],
                     char resposta[],
                     size_t tamanho_resposta);

/* Libera os nós da árvore da memória. */
void liberar_arvore(NoArvore *raiz);

#endif