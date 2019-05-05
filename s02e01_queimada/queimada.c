#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const char TREE = '#';
const char FIRE = 'o';
const char VAZIO = '.';
const char BURN = 'x';

int L[] = {0,0,1,-1};
int C[] = {1,-1,0,0};
int sizeLC = sizeof(L)/sizeof(int);

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++ ){
            printf("%c", mat[l][c]);
        }
        puts("");
    }
    getchar();
    printf("\n");
}
void misturar(int vet[], int size){
    int pos = 0;
    int aux = 0;
    for(int i = 0; i < size; i++){
        pos = rand() % size;
        aux = vet[i];

        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}
void tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l >= nl) || (c >= nc) || (l < 0) || (c < 0)){
        return;
    }
    if(mat[l][c] != TREE){
        return;
    }
    mat[l][c] = FIRE;
    int viz[] = {0,1,2,3};
    misturar(viz, sizeLC);
    for(int i = 0 ; i < sizeLC ;i++){
        int j = viz[i];
        tocar_fogo(nl,nc,mat,l + L[j], c + C[j]);
    }
    mat[l][c] = BURN;
}

int main(){
    int l = 0;
    int c = 0;
    int nl = 0;
    int nc = 0;

    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];

    for(int i = 0; i < nl; i++ ){
        for(int j = 0; j < nc; j++){
            scanf(" %c", &mat[i][j]);
        }
    }
    tocar_fogo(nl,nc,mat,l,c);
    show(nl,nc,mat);
}