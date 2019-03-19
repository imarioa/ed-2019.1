#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Pos{
    int l;
    int c;
} Pos;

int rL[] = {0, 0, -1, 1};
int rC[] = {-1, 1, 0, 0};

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

/* typedef struct{
    Pos vet[4];
} Neibs;
Neibs fill_neibs(int l, int c){
    Neibs neibs = {{{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}};
    return neibs;
} */

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l][c] == value;
}

bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, '#'))
        return false;
    int cont = 0;
    Pos neibs[] = get_neibs(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, '#'))
            cont++;
    if(cont < 3)
        return false;
    return true;
}

void furar(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl, nc, mat, l, c))
        return;
    mat[l][c] = ' ';
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++)
        furar(nl, nc, mat, neibs[i].l, neibs[i].c);    
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
    if(mat[l][c] != ' '){
        return false; 
    }if(mat[l][c] == '.'){
		return false;
	}
    mvis[l][c] = true;
    mat[l][c] = '.';
    if(mat[l][c] == mat[lsaida][csaida]){
        return true;
    }
    
    for(int i = 0; i < 4; i++){
		
		if(procurar_saida(nl,nc,mat,mvis,l + rL[i],c + rC[i],lsaida,csaida)){
			mat[l][c] = 'o'; 
			return true;
		}
	}
}
void fazer_caminho(int nl,int nc,char mat[nl][nc], bool mvis[nl][nc],int l,int c,int lsaida,int csaida){
	
}
    /*for(int i = 0; i < 4; i++){
			procurar_saida(nl,nc,mat,mvis,l + rL[i],c + rC[i],lsaida,csaida);
		if(procurar_saida(nl,nc,mat,mvis,l + rL[i],c + rC[i],lsaida,csaida)){
			return true;
		}else{
			//mat[l][c] = 'o';
			return false;
		}
	}
	return true;*/


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
    procurar_saida(nl,nc,mat, vis,1,1,1,9);
    show(nl, nc, mat);
    
    }
