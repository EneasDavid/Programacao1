#include <stdio.h>

int main(){
    // Declara variaveis
    int idadeAdotante, idadeAdotando, podeAdotar=0;
    char familiar, adocaoConjunta, uniaoEstavel, desconheceFamilia, consentimentoPais, consentimentoAdotando;
    // Recebe variaveis
    scanf("%d %c %c %c %d %c %c %c %c", &idadeAdotante,
          &familiar,
          &adocaoConjunta,
          &uniaoEstavel,
          &idadeAdotando,
          &desconheceFamilia,
          &consentimentoPais,
          &consentimentoAdotando);

    // Verifica se pode adotar
    if (idadeAdotante>=18){
        if (idadeAdotante-idadeAdotando>=16){
            if (familiar=='N'){
                podeAdotar=1;
                if (adocaoConjunta=='S' && uniaoEstavel=='N'){
                    podeAdotar=0;
                }else if (idadeAdotando >= 12 && consentimentoAdotando=='N'){
                    podeAdotar=0;
                }else if (desconheceFamilia=='N' && consentimentoPais=='N'){
                    podeAdotar=0;
                }
            }
        }
    }

    // retorna se pode
    if (podeAdotar){
        printf("Pode adotar");
    }else{
        printf("Nao pode adotar");
    }
    return 0;
}
/*
Art. 42. Podem adotar os maiores de 18 (dezoito) anos, independentemente do estado civil. - OK

§ 1º Não podem adotar os ascendentes e os irmãos do adotando. - OK

§ 2o Para adoção conjunta, é indispensável que os adotantes sejam casados civilmente ou mantenham união estável, comprovada a estabilidade da família. -ok

§ 3º O adotante há de ser, pelo menos, dezesseis anos mais velho do que o adotando. - ok


Art. 45. A adoção depende do consentimento dos pais ou do representante legal do adotando.

§ 1º. O consentimento será dispensado em relação à criança ou adolescente cujos pais sejam desconhecidos ou tenham sido destituídos do poder familiar.

§ 2º. Em se tratando de adotando maior de doze anos de idade, será também necessário o seu consentimento.

=======================================

A Idade do Adotante - ok

Se o adotante é irmão ou ascendente

Se é Adoção Conjunta - ok

Adotantes são casados ou união estável - ok

Idade do Adotando - ok

Pais Desconhecidos ou Adotando Destituído do Poder Familiar? - OK

Consentimento dos pais quando não desconhecidos - OK

Consentimento do adotando maior de doze anos de idade - OK

*/