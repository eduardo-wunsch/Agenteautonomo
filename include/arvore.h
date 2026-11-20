#ifndef ARVORE_H
#define ARVORE_H

#include <stddef.h>

#define MAX_PALAVRA_CHAVE 50
#define MAX_RESPOSTA 500

/* Cada nó de uma árvore binária tem no máximo dois filhos. */
typedef struct NoArvore {
    char palavra_chave[MAX_PALAVRA_CHAVE];
    char resposta[MAX_RESPOSTA];
    struct NoArvore *sube; /* filho da esquerda */
    struct NoArvore *subd; /* filho da direita */
} NoArvore;

NoArvore *criar_no(const char palavra_chave[], const char resposta[]);

/* Liga os filhos esquerdo e direito. NULL significa que o lado ficará vazio. */
int adicionar_filho(NoArvore *pai, NoArvore *filho_esquerdo,
                    NoArvore *filho_direito);

/* Ainda não há perguntas e respostas cadastradas nesta árvore. */
NoArvore *criar_arvore_atendimento(void);

int consultar_arvore(const NoArvore *raiz, const char pergunta[],
                     char resposta[], size_t tamanho_resposta);

void liberar_arvore(NoArvore *raiz);

#endif
