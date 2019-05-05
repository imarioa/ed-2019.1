#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct _Pos{
    int l;
    int c;
}Pos;

#define get_neibs(l,c) { {l + 1, c} , {l - 1, c} , {l, c + 1} , {l, c - 1} }

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];

        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}
bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l >= nl) || (c >= nc) || (l < 0) || (c < 0)){
        return false;
    }
    return mat[l][c] == value;
}
bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl,nc,mat,l,c,'#')){
        return false;
    }
    int cont = 0;
    Pos neibs[] = get_neibs(l,c);
    for(int i = 0; i < 4; i++){
        if(equals(nl,nc,mat,neibs[i].l ,neibs[i].c ,'#')){
            cont++;
        }
    }
    if(cont < 3){
        return false;
    }
    return true;
}
void furar(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl,nc,mat,l,c)){
        return;
    }
    mat[l][c] = ' ';
    Pos neibs[] = get_neibs(l,c);
    shuffle(neibs, 4);

    for(int i = 0 ; i < 4; i++){
        furar(nl,nc,mat, neibs[i].l, neibs[i].c);
    }
}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == '#')
                printf("█");
            else
                printf("%c", mat[l][c]);
        }
        puts("");
    }
}
bool procurar_saida(int nl,int nc,char mat[nl][nc], bool mvis[nl][nc],int l,int c,int lsaida,int csaida){
    if(!equals(nl,nc,mat,l,c,' ')){
        return false;
    }if(equals(nl,nc,mat,l,c,'.')){
        return false;
    }
    mat[l][c] = '.';
    if(mat[l][c] == mat[lsaida][csaida]){
        return true;
    }
    Pos neibs[] = get_neibs(l,c);
    for(int i = 0; i < 4; i++){
        if(procurar_saida(nl,nc, mat, mvis,neibs[i].l,neibs[i].c, lsaida, csaida)){
            return true;
        }
    }
    mat[l][c] = ' ';
    return false;
}

int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 10;
    int nc = 30;

    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    char mat[nl][nc];
	bool vis[nl][nc];
    char * p = &mat[0][0];
    bool * k = &vis[0][0];
    for(int i = 0; i < nl * nc; i++){
        p[i] = '#';
        k[i] = false;
    }
    furar(nl, nc, mat, 1, 1);
    printf("%d %d\n", nl, nc);
    show(nl, nc, mat);
    printf("\n");
    procurar_saida(nl,nc,mat, vis,1,1,2,5);
    show(nl, nc, mat);
    
    }