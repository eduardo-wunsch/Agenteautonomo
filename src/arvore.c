#include <string.h>
#include "arvore.h"

int consultar_arvore(const char pergunta[], char resposta[], int tamanho_resposta) {
    (void)pergunta; /* A busca na árvore será implementada depois. */

    if (tamanho_resposta > 0) {
        resposta[0] = '\0';

    }

/* Remove o Enter guardado pelo fgets. */
    pergunta[strcspn(pergunta, "\n")] = '\0';

    if (consultar_arvore(pergunta, resposta, sizeof(resposta))) {
        printf("Agente: %s\n", resposta);
    }       else {
                printf("Agente: Ainda não sei responder a essa pergunta.\n");
            }
    }

    return 0; /* Por enquanto, ainda não há respostas cadastradas. */
}


    criar_no(const char palavra_chave[], const char resposta[]) {
        NoArvore *novo_no(NoArvore(malloc(sizeof(*NoArvore))));
        