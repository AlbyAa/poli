/*
    Esercizio 5. Scrivere un programma “calcolatrice” che esegua le quattro operazioni aritmetiche di base
    (addizione, sottrazione, divisione e moltiplicazione) tra due valori op1 e op2.
    Realizzare un programma C che:
    a) Acquisisca da tastiera utilizzando getchar l’operazione da eseguire (‘+’, ‘-‘, ‘*’ e ‘/’)
    b) Acquisisca da tastiera utilizzando scanf i due operandi (float) (es. 21.0 2.0).
    c) Stampi a schermo il carattere dell’operazione seguita dal risultato (es. / 10.50).
    Approfondimento: Cosa succede quando op2 è uguale a 0?
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("inserire operazione da eseguire\n-> ");
    char operatore = getchar();

    // if necessaria perchè se non avesse inserito un operatore valido non ha senso chiedere i due operandi (che sono allocati nell'if perchè, in questo specifico esercizio, se non si ha la certezza di dover chiederli sarebbe un'occupazione inutile di memoria)
    if( operatore == '+' || operatore == '-' || operatore == '*' || operatore == '/' ){
        // chiedo all'utente due valori reali
        float op1,op2, risultato;
        printf("inserire primo operando:\n-> ");
        scanf("%f", &op1);
        printf("inserire secondo operando:\n-> ");
        scanf("%f", &op2);

        // cerco l'operatore corretto (non è presente il case default grazie all'if della riga 18).
        // Ho scelto una sintassi più compatta per i case perchè con pochi case e istruzioni simili rimane anche più leggibile e comprensibile
        switch (operatore){
        case '+':   risultato = op1 + op2;      break;
        case '-':   risultato = op1 - op2;      break;
        case '*':   risultato = op1 * op2;      break;
        case '/':   risultato = op1 / op2;      break; 
        }
        // stampo il risultato dell'operazione
        printf("RISULTATO OPERAZIONE: %.3f", risultato);

    }else{
        //si potrebbe anche fare strutturato con una variabile flag che viene ritornata alla fine
        printf("operatore non valido");
        return -1;
    }
    
    return 0;
}
