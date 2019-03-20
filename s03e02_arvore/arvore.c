#include "xpaint.h"

void tree(int x, int y, float ang, int tamanho, int tronco){
    if(tamanho < 5)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    
    xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
    xd_thick_line(x, y, xf, yf, tronco - 1);
    x_step("tree");

    tree(xf, yf, ang - 20, tamanho - xm_rand(5,15), tronco - 1);
    if(tamanho < 25)
		xd_filled_circle(xf, yf, 8);
    tree(xf, yf, ang + 20, tamanho - xm_rand(5,15),tronco - 1);
    
		
}

int main(){
    int largura = 600, altura = 600;
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
