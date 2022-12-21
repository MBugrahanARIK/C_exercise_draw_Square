#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#ifdef WIN32
#include <windows.h> 
#define sleep(sec) Sleep(1000*sec)
#endif

int programExit(){
    char sonuc[]="";
    printf("\n--------------------------------------------\n\nTekrar denemek ister misiniz? \033[0;31m[y/n]\033[0m: ");
    scanf("%s", &sonuc);
    if (sonuc[0]=='y'||sonuc[0]=='Y'){
        return 1;
    }else if(sonuc[0]=='n'||sonuc[0]=='N'){
        printf("Program Kapatiliyor...");
        sleep(2);
        exit(1);
    }else{
        printf("Yanlis Bir Deger Girdiniz Tekrar Deneyin!");
        sleep(3);
        return 0;
    }
}

void alertText(char text[]){
    for(;;){
        system("cls");
        printf("Dikdortgen Cizme Programi\n--------------------------------------------\n");
        printf("\033[0;31m%s\033[0m", text); // Metine Kırmızı Renk Verir Ve Yazdırır.
        if (programExit()==1){
            break;
        }
    }
        system("cls");
}

int main()
{   
    for (;;)
    {
        int satir = 0;
        int sutun = 0;

        // Değerleri al
        for(;;){
            printf("Dikdortgen Cizme Programi\n--------------------------------------------\n");

            printf("Satir sayisini giriniz: "); 
            scanf("%d", &satir);

            printf("\nSutun sayisini giriniz: ");
            scanf("%d", &sutun);
            
            // Gelen Değerlerin Kontrolü
            if(satir==0||sutun==0){
                alertText("Girdiginiz degerler herhangi bir sekil olusturmaz.\nLutfen degerlerinizi en az 2 olarak giriniz.");
            }else if(satir==1 && sutun==1){
                alertText("Girdiginiz degerler nokta olusturur.\nLutfen degerlerinizi en az 2 olarak giriniz.");
            }else if ((satir==1&&sutun>1)||(satir>1&&sutun==1)){
                alertText("Girdiginiz degerler cizgi olusturur.\nLutfen degerlerinizi en az 2 olarak giriniz.");
            }else if (satir<0 || sutun<0){
                alertText("Lutfen negatif degerler vermeyin!\nLutfen degerlerinizi en az 2 olarak giriniz.");
            }
            if(satir>1 && sutun>1){
                system("cls");
                break;
            }
        }
            printf("Dikdortgen Cizme Programi\n--------------------------------------------\n");

        for (int i = 0; i < satir; i++)
        {
            for (int j = 0; j < sutun; j++)
            {
                if(i==0||i==satir-1){
                    printf("*");
                }else{
                    if(j==0||j==sutun-1){
                        printf("*");
                    }else{
                        printf(" ");
                    }
                }
            }
            
            printf("\n");
        }
        while(programExit()==0){} // Programdan çıkma ya da devam etmek
        system("cls");
    }
}