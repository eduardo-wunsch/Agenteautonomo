#include <stdio.h>
#include <string.h>

#include "atendimento.h"
#include "arvore.h"

void iniciar_atendimento(void) {
    char pergunta[200];
    char resposta[MAX_RESPOSTA];
    NoArvore *raiz = criar_arvore_atendimento();

    printf("Como posso te ajudar?\n");
    if (fgets(pergunta, sizeof pergunta, stdin) == NULL) {
        liberar_arvore(raiz);
        return;
    }

    pergunta[strcspn(pergunta, "\n")] = '\0';

    if (consultar_arvore(raiz, pergunta, resposta, sizeof resposta)) {
        printf("Agente: %s\n", resposta);
    } else {
        printf("Agente: Ainda não sei responder a essa pergunta.\n");
    }

    liberar_arvore(raiz);
}
