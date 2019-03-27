#include "xpaint.h"

void tree(int x, int y, float ang, int tamanho, int tronco){
    if(tamanho < 5)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    
    xs_color(YELLOW);
    xd_thick_line(x, y, xf, yf, tronco - 1);
    x_step("tree");

    tree(xf, yf, ang - 20, tamanho - xm_rand(5,10), tronco - 1);
    tree(xf, yf, ang + 20, tamanho - xm_rand(5,10), tronco - 1); 
    
    if(tamanho <= 8){
		xs_color(RED);
		xd_filled_circle(xf, yf, 8);
    }
		
}

int main(){
    int largura = 1000, altura = 700;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 90;
    tree(x, y, ang, tamanho, 10);
    x_save("tree");
    x_close();
    return 0;
}
