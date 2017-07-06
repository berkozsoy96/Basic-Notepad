#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

POINT isaret;

void ekranHazirla(){
    initwindow(800 , 680 , "" , 15 , 15);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(0);
    setusercharsize(1,3,1,1);
}

int main(){

    ekranHazirla();
    FILE* dosya;

    char yazi[42][88]={0};
    int sutsay[42]={0};
    char ch;
    int i=0 , j=0 , k;
    int imlecX=0 , imlecY=0;

    while(1){
        //GET CHARACTER
        ch=getch();

        //BACKSPACE
        if(ch==8){
            if(sutsay[i]==0 && i==0){
                //Birsey Yapma
            }
            else if(sutsay[i]==0){
                i--;
                moveto(sutsay[i]*9 , i*16);
            }
            else if(sutsay[i]!=0){
                sutsay[i]--;
                moveto(sutsay[i]*9 , i*16);
                setfillstyle(SOLID_FILL , WHITE);
                bar(sutsay[i]*9 , i*16 , sutsay[i]*9+9 , i*16+16);
            }
            continue;
        }
        //CLOSE GRAPH
        if(ch==0x1B){
            break;
        }
        //ARROW KEYS
        if(GetAsyncKeyState(VK_UP)){
            printf("yukari\n");
            continue;
        }
        if(GetAsyncKeyState(VK_DOWN)){
            printf("asagi\n");
            continue;
        }
        if(GetAsyncKeyState(VK_LEFT)){
            printf("sol\n");
            continue;
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            printf("sag\n");
            sutsay[i]++;
            moveto(sutsay[i]*9 , i*16);
            continue;
        }
        //ENTER OR END OF ROW
        if(sutsay[i]==88){
            i++;
            moveto(0 , i*16);
        }
        if(ch==13){
            i++;
            moveto(0 , i*16);
            continue;
        }
        //PRINT CHARACTER TO SCREEN
        outtext(&ch);
        yazi[i][sutsay[i]]=ch;
        sutsay[i]++;
    }
    int bos=0;
    char bosch=NULL;//yaþam için teknoloji
    dosya=fopen("Notepad.txt" , "w");
    for(j=0 ; j<=i ; j++){
        for(k=0 ; k<sutsay[j] ; k++){
            fprintf(dosya , "%c" , yazi[j][k]);
        }
        fprintf(dosya,"\n");
    }
    fclose(dosya);
    int bos2=0;
    return 0;
}
