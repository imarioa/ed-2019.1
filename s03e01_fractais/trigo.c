#include "xpaint.h"

void trigo(int x, int y, int ang, float tamanho){
	if(tamanho <= 1){
		return;
	}
	
	int xi = x;
	int yi = y;
		
	for(int i = 0 ; i < 4; i++){
		int xf = xi + tamanho * xm_cos(ang);
		int yf = yi - tamanho * xm_sin(ang);
			
		xd_thick_line(x, y, xf, yf, 1);
		x_step("tri");
			
		trigo(xf,yf, ang - 40, tamanho/3);
		trigo(xf,yf, ang + 40, tamanho/3);
			
		xi = xf;
		yi = yf;
	}	
}

int main(){
	
	int largura = 1000, altura = 1000;
	
    x_open(largura, altura); 
    x_clear(VIOLET);
    
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 120;
    
    trigo(x, y, ang, tamanho);
    x_save("tri");
    x_close();
    
    return 0;
	
}
