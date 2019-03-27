#include "xpaint.h"

//xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});


void circle(int x, int y, int ang, int tamanho){
	if(tamanho <= 0){
		return;
	}
	
    for(int i = 0; i < 6; i++){
		int xf = x + tamanho * xm_cos(ang);
		int yf = y - tamanho * xm_sin(ang);
		
		xd_circle(x,y, tamanho);
		x_step("circle");
		
		ang = ang + 60;
		circle(xf,yf,ang, tamanho/3);
		
	}
}
int main(){
    int largura = 500, altura = 500;
    x_open(largura, altura); 
    x_clear(VIOLET);
    
    int x = largura / 2;
    int y = altura /2;
    
    circle(x, y, 0, 100);
    x_save("circle");
    x_close();
    
    return 0;
}
