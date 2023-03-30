/*
    Un file (sorgente.txt) contiene un testo composto da un numero indefinito di righe.
    Notare che il testo NON contiene il carattere ‘$’.
    Lo scopo del programma è di ricodificare il testo sostituendo sequenze di caratteri ripetuti da 2 a 9
    volte (ATTENZIONE: il numero non comprende il primo carattere, cioè AA contiene una ripetizione,
    BBB due ripetizioni, ecc.) con la terna di caratteri <carattere ripetuto>$<numero di ripetizioni>
    (ATTENZIONE: per il <numero di ripetizioni> è sufficiente un carattere). Se un carattere fosse
    ripetuto più di 9 volte, le ripetizioni sarebbero spezzate in più intervalli.

*/
#include <stdio.h>
#include <stdlib.h>

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);


void main(){
    FILE *fileIn = fopen("/home/alberto/Scrivania/s307025_1/L02/E03/sorgente.txt","r");
    FILE *fileOut = fopen("/home/alberto/Scrivania/s307025_1/L02/E03/sorgenteCompressa.txt","r");

    if(fileIn == NULL || fileOut == NULL){
        printf("errore nell'apertura dei file");
        return;
    }
    //printf("Sono stati scritti %d caratteri nel file compresso e %d in quello decompresso", comprimi(fileIn, fileOut), decomprimi(fileOut,fileIn));
    comprimi(fileIn,fileIn);
    printf("\n\n");
    decomprimi(fileOut, fileOut);
    fclose(fileIn);
    fclose(fileOut);
}


int comprimi(FILE *fin, FILE *fout){
    char attuale, precedente;
    int ricorrenza = 1, cntCaratteri = 0;

    fscanf(fin, "%c", &precedente);
    while( fscanf(fin, "%c", &attuale) != EOF ){
        
        // chiede se il carattere letto è uguale al precedente
        if( attuale == precedente ){
            // chiede se ha già letto 9 caratteri uguali
            if( ricorrenza == 9 ){
                cntCaratteri += 3;
                printf("%c$9",attuale);
                ricorrenza = 1;
            }else{
                ricorrenza ++;
            }
        }else{
            //il carattere è diverso
            printf("%c", precedente);
            cntCaratteri++;
            if(ricorrenza > 1){
                cntCaratteri += 2;
                printf("$%d",ricorrenza);
                ricorrenza = 1;
            }
            precedente = attuale;
        }
    }

    // finito di leggere il file deve ancora stampare i caratteri letti precedentemente 
    printf("%c", precedente);
    cntCaratteri++;
    if(ricorrenza > 1){
        cntCaratteri += 2;
        printf("$%d",ricorrenza);
        ricorrenza = 1;
    }

    return cntCaratteri;
}



int decomprimi(FILE *fin, FILE *fout){
    int cntCaratteri = 0;
    char attuale, precedente, ricorrenza;

    while( fscanf(fin,"%c",&attuale) != EOF ){
        
        if( attuale == '$' ){
            fscanf(fin,"%c",&ricorrenza);
            ricorrenza = ricorrenza - '1';
            cntCaratteri+= ricorrenza;
            for ( int i = 0; i < ricorrenza; i++ ){
                printf("%c", precedente);
            }
        }else{

            cntCaratteri++;
            printf("%c", attuale);
        }
        precedente = attuale;
    }
    
    return cntCaratteri;
}