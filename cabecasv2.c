//
// Created by Imario on 23/02/19.
//

#include<stdio.h>
#include<stdbool.h>

int achar_vivo(int participantes[],int indice, int n_participantes){

    int pos = 0;

    if(participantes[indice] > 0){
        pos = (indice + 1) % n_participantes;
    }else if(participantes[indice] < 0){
        pos = indice - 1;
        if(pos < 0){
            pos = n_participantes - 1;
        }
    }

    if(participantes[indice] > 0) {
        while (participantes[pos] == 0) {
            if (participantes[pos] == 0) {
                pos = (pos + 1) % n_participantes;
            }
        }
    }else if(participantes[indice] < 0){
        while (participantes[pos] == 0) {
            pos--;
            if(pos < 0){
                pos = n_participantes - 1;
            }
        }
    }
    return pos;

}

void imprime_vivos(int participantes[], int n_participantes, int escolhido){
    bool primeiro = true;

    printf("[");
    for(int i = 0; i < n_participantes; i++){

        if(participantes[i] != 0) {

            if (primeiro == true) {
                primeiro = false;
            } else {
                printf(" ");
            }
            if(i == escolhido && participantes[i] > 0){
                printf("%d>",participantes[escolhido]);
            }else if(i == escolhido && participantes[i] < 0){
                printf("<%d", participantes[i]);
            }else{
                printf("%d",participantes[i]);
            }
        }
    }
    printf("]\n");
}
void p_Alternando(int vet[], int fase, int qtd){

    for(int i = 0; i < qtd; i++){
        if(fase > 0) {
            if (i % 2 == 0) {
                vet[i] = i + 1;
            } else {
                vet[i] = -(i + 1);
            }
        }else if(fase < 0){
            if (i % 2 == 0) {
                vet[i] = -(i + 1);
            } else {
                vet[i] = i + 1;
            }
        }

    }
}
int passar_espada(int vet[], int esc, int qtd){
    int n_vezes = 0;
    int pos = esc;

    if(vet[esc] > 0){
        for(int i = 0; i < vet[esc]; i++){

            if(vet[achar_vivo(vet,pos,qtd)] < 0){
                pos = (pos + 2) % qtd;
                i--;
            }
            pos = achar_vivo(vet,pos,qtd);
        }
    }else if(vet[esc] < 0){
        n_vezes = -1 * vet[esc];

        for(int i = 0 ; i < n_vezes; i++){
            if(vet[pos] > 0){
                pos = pos - 1;
                i++;
                if(pos < 0){
                    pos = qtd - 1;
                }
            }
            pos = achar_vivo(vet,pos,qtd);

        }
    }
    return pos;
}

int main(){

   int size = 0;
   int esc = 0;
   int fase = 0;

   scanf("%d", &size);
   scanf("%d", &esc);
   scanf("%d", &fase);

   int vet[size];
   p_Alternando(vet,fase,size);

   esc = esc - 1;
   imprime_vivos(vet,size,esc);

   for(int i = 0; i < size -1; i++){

        int vai_morrer = achar_vivo(vet,esc,size);
        vet[vai_morrer] = 0;
        esc = passar_espada(vet,esc,size);
        imprime_vivos(vet,size,esc);

    }
}


