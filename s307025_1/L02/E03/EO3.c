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
    FILE *fileIn;
    FILE *fileOut;
    char nomeFile[35];

    printf("Inserire C per comprimere e D per decomprimere\n->");
    fflush(stdin);
    switch(getchar()){
        case 'C':
            printf("inserire nome file da comprimere:\n->");
            scanf("%s", nomeFile);
            fileIn = fopen(nomeFile,"r");
            //fileIn = fopen("C:\\Users\\alb20\\OneDrive\\Desktop\\poli\\s307025_1\\L02\\E03\\sorgente.txt", "r");
            fileOut = fopen("./sorgenteCompressa.txt","w");
            if(fileIn == NULL || fileOut == NULL){
                printf("errore nell'apertura dei file");
                exit(-1);
            }
            printf("Sono stati stampati %d caratteri durante la compressione",comprimi(fileIn,fileOut));
        break;

        case 'D':
            printf("inserire nome file da decomprimere:\n->");
            scanf("%s", nomeFile);
            fileIn = fopen(nomeFile,"r");
            //fileIn = fopen("C:\\Users\\alb20\\OneDrive\\Desktop\\poli\\s307025_1\\L02\\E03\\sorgenteCompressa.txt", "r");
            fileOut = fopen("./compressoDecompresso.txt","w");
            if(fileIn == NULL || fileOut == NULL){
                printf("errore nell'apertura dei file");
                exit(-1);
            }
            printf("Sono stati stampati %d caratteri durante la decompressione",decomprimi(fileIn,fileOut));
            break;
            
        default:
            printf("scelta non valida");
    }

    fclose(fileIn);
    fclose(fileOut);
    return;
}


int comprimi(FILE *fin, FILE *fout){
    char attuale, precedente;
    int ricorrenza = 0, cntCaratteri = 0;

    fscanf(fin, "%c", &precedente);
    while( fscanf(fin, "%c", &attuale) != EOF ){
        // chiede se il carattere letto è uguale al precedente
        if( attuale == precedente ){
            // chiede se ha già letto 9 caratteri uguali
            if( ricorrenza == 9 ){
                cntCaratteri += 3;
                fprintf(fout, "%c$9",attuale);
                ricorrenza = 0;
            }else{
                ricorrenza ++;
            }
        }else{
            //il carattere è diverso
            fprintf(fout, "%c", precedente);
            cntCaratteri++;
            
            if( ricorrenza > 0){
                //se ci sono solo due caratteri simili vicini stampa i due caratteri, sennò usa la notazione $
                if( ricorrenza == 1){
                    fprintf(fout, "%c", precedente);
                    cntCaratteri++;
                    ricorrenza = 0;                
                }else{
                    cntCaratteri += 2;
                    fprintf(fout, "$%d",ricorrenza);
                    ricorrenza = 0;
                }
            }
            precedente = attuale;
        }
    }

    // finito di leggere il file deve ancora stampare i caratteri letti precedentemente 
    fprintf(fout, "%c", precedente);
    cntCaratteri++;

    if( ricorrenza == 1 ){
        fprintf(fout, "%c", precedente);
        cntCaratteri++;
    }else{
        if( ricorrenza > 1 ){
            cntCaratteri += 2;
            fprintf(fout, "$%d",ricorrenza);
        }
    }
    
    return cntCaratteri;
}


int decomprimi(FILE *fin, FILE *fout){
    int cntCaratteri = 0;
    char attuale, precedente, ricorrenza;
    // legge ad uno ad uno i caratteri fino a fine file
    while( fscanf(fin,"%c",&attuale) != EOF ){
        // quando legge il dollaro stampa n volte il carattere precedente (pensando n il carattere dopo il dollaro )
        if( attuale == '$' ){
            // non posso usare un %d perchè se dopo ci fosse un intero leggerebbe le due/tre/... cifre.
            // Quindi leggo il carattere ascii successivo ad $ e gli sottraggo il corrispettivo valore ascci di '1'. 
            fscanf(fin,"%c",&ricorrenza);
            ricorrenza = ricorrenza - '1';
            cntCaratteri+= ricorrenza;
            //stampo 'ricorrenza' volte il carattere precedente il dollaro
            for ( int i = 0; i <= ricorrenza; i++ ){
                fprintf(fout, "%c", precedente);
            }
        }else{
            // se non ha letto $ stampa semplicemente il carattere precedentemente letto
            cntCaratteri++;
            fprintf(fout, "%c", attuale);
        }
        precedente = attuale;
    }
    return cntCaratteri;
}