#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_FILE_IN  "input.txt"
#define NAME_FILE_OUT "testo.txt"

void formattaFile(FILE *fin, FILE *fout);
bool isNum(char car);
bool isAlpha(char car);
bool isLetter(char car);
bool isPunteggiatura(char car);
bool isPoint(char car);
bool isMinuscolo(char car);

void main(){
    FILE *fileIn, *fileOut;
    
    fileIn  = fopen(NAME_FILE_IN,"r");
    fileOut = fopen(NAME_FILE_OUT, "w");
    if( fileIn == NULL ){
        printf("impossibile aprire il file");
        exit(-1);
    }

    formattaFile(fileIn, fileOut);
}


//funzione che passato un file lo elabori secondo le indicazioni della consegna.
//Trovo più comodo io personalmente lavorare leggendo i singoli caratteri piuttosto che stringhe o intere righe. 
//Per le variabili booleane potrei usare anche dei flag ad interi, però per occupazione in memoria e semplicità uso i booleani
void formattaFile(FILE *fin, FILE *fout){
    char car;
    bool punteggiatura = false, maiuscolo = false;
    int cntCaratteri = 0, spazi = 0, MAX_CARATTERI_RIGA = 25;
    while( fscanf(fin, "%c", &car) != EOF ){
        cntCaratteri++;

        // se prima ho letto un carattere di punteggiatura e sto leggendo lettere o numeri inserisco uno  spazio
        if( punteggiatura && isAlpha(car)){
            fprintf(fout, " ");
            cntCaratteri++;
            spazi++;
        }
            
        //controlla se bisogna mettere la lettera maiuscola
        if( maiuscolo ){
            // se il carattere è minuscolo lo cambia in maiuscolo. Se invece è uno spazio o \n non resetta la variabile che indica che bisogna stampare maiuscolo, senno la resetta
            if ( isMinuscolo(car) ){
                car = car + 'A' - 'a';
                maiuscolo = false;
            }else{
                if( car != ' ' && car != '\n'){
                    maiuscolo = isPoint(car);
                }
            }
        }else{
            // se non bisognava stampare la lettera maiuscola si controlla se si ha letto un punto.
            // Dentro il ramo vero viene gestito il reset della variabile
            maiuscolo = isPoint(car);
        }

        if( isNum(car) )
            car = '*';
        
        if( cntCaratteri > MAX_CARATTERI_RIGA && car != '\n' ){
            fprintf(fout, "| c:%d\n", cntCaratteri-1 - spazi);
            cntCaratteri = 1;
            spazi = 0;
        }
        if( car == '\n' ){
            for( int spazio = cntCaratteri; spazio <= MAX_CARATTERI_RIGA; spazio++){
                fprintf(fout, " ");
            }
            fprintf(fout, "| c:%d", cntCaratteri-spazi);
            cntCaratteri = 0;
            spazi = 0;
        }
        fprintf(fout,"%c", car);

        punteggiatura = isPunteggiatura(car);    
    }

    for( int spazio = cntCaratteri; spazio < MAX_CARATTERI_RIGA; spazio++){
        fprintf(fout, " ");
    }
    
    fprintf(fout, "| c:%d", cntCaratteri-spazi);

}


bool isNum(char car){
    return ( car >= '1' && car <= '9' );
}

bool isLetter(char car){
    return( (car >= 'a' && car <= 'z') || (car >= 'A' && car <= 'Z') );
}

bool isAlpha(char car){
    return ( isNum(car) || isLetter(car) );
}

bool isPunteggiatura(char car){
    return ( car == '.' || car == ',' || car == ';' || car == ':' || car == '!' || car == '?' || car == '\'' || car == '(' || car == ')');
}

bool isPoint(char car){
    return ( car == '!' || car == '.' || car == '?' );
}

bool isMinuscolo(char car){
    return ( car >= 'a' && car <= 'z' );
}