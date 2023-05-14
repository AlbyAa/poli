#include <stdio.h>
#include <string.h>

#define MAX_CODIFICHE 30
#define DIM_MAX_RIGA 200
#define DIM_PAROLA 20

typedef struct {
    char ricodifica[10];
    char originale[10];
    int lungOriginale;
}Sostituto;

void leggiCodifiche(Sostituto codifiche[], FILE *fp, int dim);
void codificaTesto(char nomeFileIn[], char nomeFileOut[], Sostituto codifiche[], int numCodifiche);
void corrispondenzaParola(char riga[],int inizioParola,int fineParola,Sostituto codifiche[],int numCodifiche);
int isLettera(char lettera);

int main(){
    FILE *fp = fopen("dizionario.txt","r");
    int numCodifiche;
    fscanf(fp,"%d",&numCodifiche);
    if(numCodifiche > MAX_CODIFICHE){
        printf("ERRORE: numero di codifiche maggiore di quelle supportate");
        return -1;
    }
    Sostituto codifiche[numCodifiche];
    leggiCodifiche(codifiche, fp, numCodifiche);
    fclose(fp);

    //codificaTesto("sorgente.txt", "ricodificato.txt", codifiche, numCodifiche);

    corrispondenzaParola("contemporaneamente",0,19,codifiche, numCodifiche);
}

void leggiCodifiche(Sostituto codifiche[], FILE *fp, int dim){
    int cnt;
    for(cnt = 0; cnt< dim; cnt ++){
        fscanf(fp,"%s %s\n",codifiche[cnt].ricodifica, codifiche[cnt].originale);
        codifiche[cnt].lungOriginale = strlen(codifiche[cnt].originale);
    }
}

void codificaTesto(char nomeFileIn[], char nomeFileOut[], Sostituto codifiche[], int numCodifiche){
    int cnt, dimRiga, inizioParola;
    FILE *fin  = fopen(nomeFileIn,"r");
    FILE *fout = fopen64(nomeFileOut,"w");

    char riga[DIM_MAX_RIGA+1] = "";
    char parola[DIM_PAROLA+1] = "";
    while (fgets(riga,DIM_MAX_RIGA,fin) != 0){ // legge righe
        dimRiga = strlen(riga);
        inizioParola = 0;
        for(cnt = 0; cnt < dimRiga; cnt++){
            if( isLettera(riga[cnt])  != 0){
                corrispondenzaParola(riga,inizioParola,cnt, codifiche, numCodifiche);
                printf("%c",riga[cnt]);
                inizioParola = cnt;
            }
        }

    }
    
    fclose(fin);
    fclose(fout);
}

int isLettera(char lettera){
    if(( lettera >= 'a' && lettera <= 'z' ) || (lettera >= 'A' && lettera <= 'Z')){
        return 0;
    }else{
        return 1;
    }
}

void corrispondenzaParola(char riga[],int inizioParola,int fineParola,Sostituto codifiche[],int numCodifiche){
    int indice, lung;
    for(indice = 0; indice < fineParola - inizioParola; indice++){
        printf("%d ->", indice);
        for(lung = 0; lung < fineParola - inizioParola - indice; lung++){
            printf("%d --", lung);
        }
        printf("\n");
    }
}

componiParola(char riga[], int)