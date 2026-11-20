#include <stdio.h>
#include <string.h>
#include "atendimento.h"
#include "arvore.h"


void iniciar_atendimento(void){
    char pergunta[200];
    char resposta[500];


    printf("Como posso te ajudar?\n");
    fgets(pergunta, sizeof(pergunta), stdin);
    pergunta[strcspn(pergunta, "\n")] = '\0';
    if(consultar_arvore(pergunta, resposta, sizeof(resposta)))
        printf("Agente: %s\n", resposta);
    else
        printf("Agente: Ainda não sei responder a essa pergunta\n");


}