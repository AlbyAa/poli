/*
    Partendo dal codice dell’esercizio precedente, scrivere un programma C che legga da file
    una serie di operazione da eseguire e scriva su un altro file l’operazione eseguita
    ed il risultato dell’operazione con due cifre decimali.
*/
#include <stdio.h>
#include <stdlib.h>


#define PATH_FILE_IN  "./Operations.txt"
#define PATH_FILE_OUT "./Results.txt"
//#define PATH_FILE_IN  "/home/alberto/Scrivania/s307025_1/L01/E06/Operations.txt"
//#define PATH_FILE_OUT "/home/alberto/Scrivania/s307025_1/L01/E06/Results.txt"


float solveEquation(char operator, float num1, float num2);


int main(){ 
    char operator;
    float n1, n2, result;
    int cnt = 0;
    // apre file di input e output
    FILE *fin  = fopen(PATH_FILE_IN, "r");
    FILE *fout = fopen(PATH_FILE_OUT, "w");
    
    if( fin == NULL ){
        printf("errore con l'apertura del file di input...");
        return -1;
    }
    
    // fino a quando non arriva alla fine del file legge righe con la formattazione indicata, passa i valori alla funzione che risolve calcoli e scrive su file di output il risultato ottenuto
    while( !feof(fin) ){
        fscanf(fin, "%c %f %f\n", &operator, &n1, &n2);
        result = solveEquation(operator,n1,n2);
        fprintf(fout, "%c %.2f\n",operator, result);      
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}


//risolve l'operazione inserita. Se l'operatore non esiste ritorna 0...
float solveEquation(char operator, float num1, float num2){
    float result = 0;
    switch ( operator ){
        case '+':   result = num1 + num2;      break;
        case '-':   result = num1 - num2;      break;
        case '*':   result = num1 * num2;      break;
        case '/':   result = num1 / num2;      break; 
        default :   
            printf("operatore non valido in %f %c %f",num1,operator,num2);
        }
    return result;
}