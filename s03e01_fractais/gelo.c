#include "xpaint.h"

//xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});


void gelo(int x, int y, int ang, float tamanho){
	if(tamanho < 1){
		return;
	}
	
	for(int i = 0; i < 5; i++){
		 int xf = x + tamanho * xm_cos(ang);
		 int yf = y - tamanho * xm_sin(ang);
	
		xd_thick_line(x, y, xf, yf, 1);
		x_step("ice");
		ang += 72;
		gelo(xf,yf,ang, tamanho/3);
	}
}
int main(){
    int largura = 500, altura = 500;
    x_open(largura, altura); 
    x_clear(VIOLET);
    
    int x = largura / 2;
    int y = altura /2;
    
    gelo(x, y, 72, 100);
    x_save("ice");
    x_close();
    
    return 0;
}
