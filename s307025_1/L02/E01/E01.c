/*
    Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore
    utilizzando la formula di Eulero
*/
#include <stdio.h>
#include <stdlib.h>


//funzione che resitutisce il mcd
int mcdEulero(int n1, int n2){
    int maggiore = n1, minore = n2, resto, temp;

    //Cerco maggiore e minore, calcolo il resto della divisione, se è diverso da zero copio il valore in 'maggiore', sennò ritorno il mcd al chiamante 
    do{
        if( maggiore < minore ){
            temp = maggiore;
            maggiore = minore;
            minore = temp;
        }
        resto = maggiore % minore;
        if( resto ){
            maggiore = resto;
        }
    }while( resto != 0);
        
    return minore;
}

void main(){
    int num1, num2;
    printf("Inesrire due numeri interi:\nprimo numero: ... ");
    scanf("%d",&num1);
    printf("secondo numero: ... ");
    scanf("%d",&num2);

    printf("Il minimo comune divisore tra %d e %d e' %d",num1,num2,mcdEulero(num1, num2));

    return;
}