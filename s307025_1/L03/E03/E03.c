#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PATH_FILE_IN "numeri.txt"

void controllaValori(FILE *fin);
void stampaRisultati(int max, int min, int scartati);
bool controllaNumero(int attuale, int prec1, int prec2);

void main(){
    FILE *fileIn = fopen(PATH_FILE_IN,"r");

    controllaValori(fileIn);

}


void controllaValori(FILE *fin){
    int max, min, attuale, prec1, prec2, scartati = 0;

    //se il file contenesse solo uno o due valori stampa di conseguenza e ritorna alla funzione chiamante. Sennò cerca massimo e minimo e continua con la ricerca indicata nella consegna
    if( fscanf(fin, "%d",&prec2) != EOF ){
        if( fscanf(fin, "%d",&prec1) != EOF ){
            if( prec1 > prec2 ){
                max = prec1;
                min = prec2;
            }else{
                max = prec2;
                min = prec1;
            }
        }else{
            stampaRisultati(prec2,prec2, 0);
            return;
        }
    }else{
        printf("nessun valore contenuto nel file");
        return;
    }

    while ( fscanf(fin, "%d",&attuale) != EOF ){
        if( controllaNumero(attuale, prec1, prec2) ){
            prec2 = prec1;
            prec1 = attuale;
            if( attuale > max )
                max = attuale;
            else{
                if( attuale < min )
                    min = attuale;
            }
        }else{
            scartati++;
        }
    }
    stampaRisultati(max, min, scartati);    
}



void stampaRisultati(int max, int min, int scartati){
    printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d",max, min, scartati);
}

bool controllaNumero(int attuale, int prec1, int prec2){
    if( prec1 == 0)
        return ( attuale == prec2 + prec1 || attuale == prec2 - prec1 || attuale == prec2 * prec1);
    return ( attuale == prec2 + prec1 || attuale == prec2 - prec1 || attuale == prec2 * prec1 || attuale == prec2 / prec1);
    
}