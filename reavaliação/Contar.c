#include <stdio.h>
#define tamanhoArray 9999

void removeQuebrasDeLinha(char str[], int i, int d) {
    if (str[i]=='\0') {
        str[d]='\0';
        return;
    }
    if (str[i]!='\n') {
        str[d]=str[i];
        removeQuebrasDeLinha(str, i+1, d+1);
    } else {
        removeQuebrasDeLinha(str, i+1, d);
    }
}

int compareStrings(char entradaUm[], char entradaDois[], int i, int d){
    if(entradaDois[d]=='\0') return 1;
    if(entradaUm[i]=='\0') return 0;
    if(entradaUm[i]==entradaDois[d]) return compareStrings(entradaUm, entradaDois, i+1, d+1);
    return 0;
}

int myFor(char entradaUm[], char entradaDois[], int i, int qtnApareceu) {
    int entradaDivididaUm=0;
    while(entradaUm[entradaDivididaUm]!='\0'){
        entradaDivididaUm++;
    }
    if(i>entradaDivididaUm) return qtnApareceu;
    if(compareStrings(entradaUm, entradaDois, i, 0)) qtnApareceu++;
    return myFor(entradaUm, entradaDois, i+1, qtnApareceu);
}

int main() {
    char entradaUm[tamanhoArray], entradaDois[tamanhoArray];
    int qtnApareceu=0;
    scanf("%[^\n] %[^\n]", entradaUm, entradaDois);
    removeQuebrasDeLinha(entradaUm, 0, 0);
    removeQuebrasDeLinha(entradaDois, 0, 0);
    qtnApareceu=myFor(entradaUm, entradaDois, 0, 0);
    printf("%d\n", qtnApareceu);
    return 0;
}