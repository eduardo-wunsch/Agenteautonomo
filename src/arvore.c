#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore.h"

NoArvore *criar_no(const char palavra_chave[], const char resposta[]) {
    NoArvore *novo_no;

    if (palavra_chave == NULL || resposta == NULL ||
        strlen(palavra_chave) >= MAX_PALAVRA_CHAVE ||
        strlen(resposta) >= MAX_RESPOSTA) {
        return NULL;
    }

    novo_no = malloc(sizeof *novo_no);
    if (novo_no == NULL) {
        return NULL;
    }

    strcpy(novo_no->palavra_chave, palavra_chave);
    strcpy(novo_no->resposta, resposta);
    novo_no->sube = NULL;
    novo_no->subd = NULL;

    return novo_no;
}

int adicionar_filho(NoArvore *pai, NoArvore *filho_esquerdo,
                    NoArvore *filho_direito) {
    if (pai == NULL || pai->sube != NULL || pai->subd != NULL) {
        return 0;
    }

    pai->sube = filho_esquerdo;
    pai->subd = filho_direito;
    return 1;
}

NoArvore *criar_arvore_atendimento(void) {
    /* A árvore começa vazia até que sejam cadastradas perguntas e respostas. */
    return NULL;
}

static int buscar_resposta(const NoArvore *no, const char pergunta[],
                           char resposta[], size_t tamanho_resposta) {
    if (no == NULL) {
        return 0;
    }

    if (no->palavra_chave[0] != '\0' &&
        strstr(pergunta, no->palavra_chave) != NULL) {
        if (tamanho_resposta > 0) {
            snprintf(resposta, tamanho_resposta, "%s", no->resposta);
        }
        return 1;
    }

    return buscar_resposta(no->sube, pergunta, resposta, tamanho_resposta) ||
           buscar_resposta(no->subd, pergunta, resposta, tamanho_resposta);
}

int consultar_arvore(const NoArvore *raiz, const char pergunta[],
                     char resposta[], size_t tamanho_resposta) {
    if (resposta != NULL && tamanho_resposta > 0) {
        resposta[0] = '\0';
    }

    if (raiz == NULL || pergunta == NULL || resposta == NULL ||
        tamanho_resposta == 0) {
        return 0;
    }

    return buscar_resposta(raiz, pergunta, resposta, tamanho_resposta);
}

void liberar_arvore(NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar_arvore(raiz->sube);
    liberar_arvore(raiz->subd);
    free(raiz);
}
