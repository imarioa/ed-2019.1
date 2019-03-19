#include<stdio.h>
#include<time.h>
#include<stdlib.h>

const char TREE = '#';
const char FIRE = 'o';
const char VAZIO = '.';
const char BURN = 'x';
int rL[] = {0, 0, -1, 1};
int rC[] = {-1, 1, 0, 0};
int sizeLC = sizeof(rL)/sizeof(int);

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
    getchar();
    printf("\n");
}

void misturar(int vet[], int size){
	for(int i = 0; i < size; i++){
		int pos = rand() % size;
		int aux = vet[i];
		
		vet[i] = vet[pos];
		vet[pos] = aux;
		}
}

void tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
	if((l >= nl) || (c >= nl) || (l < 0) || (c < 0))
		return;
	if(mat[l][c] != TREE)
		return;
		
	mat[l][c] = FIRE;
	int vizinhos[]= {0,1,2,3};
	misturar(vizinhos, sizeLC);
	
	for(int i = 0; i < sizeLC; i++){
		int j = vizinhos[i];
		tocar_fogo(nl, nc, mat, l + rL[j], c + rC[j]);
	}
	
	mat[l][c] = BURN;
	
}



int main(){
	int l = 0;
	int c = 0;
	int nl = 0;
	int nc = 0;
	
	scanf("%d %d %d %d\n", &nl,&nc,&l,&c);
	
	char mat[nl][nc];
	
	
	for(int i = 0; i < nl; i++)
		for(int j = 0; j < nc; j++)
			scanf(" %c", &mat[i][j]);
			
	tocar_fogo(nl,nc,mat,l,c);
	//show(nl,nc,mat);
}
