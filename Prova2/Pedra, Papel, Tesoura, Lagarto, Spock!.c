#include <stdio.h>
#include <string.h>

int jogada(int kaio, int yuri){
  if(kaio==0){
    if(yuri==1 || yuri==2){
      return 1;
    }
    return -1;
  }else if(kaio==1){
    if(yuri==3 || yuri==2){
      return 1;
    }
    return -1;
  }else if(kaio==2){
    if(yuri==3 || yuri==4){
      return 1;
    }
    return -1;
  }else if(kaio==3){
    if(yuri==0 || yuri==4){
      return 1;
    }
    return -1;
  }else{
    if(yuri==0 || yuri==1){
      return 1;
    }
    return -1;
  }
}

void entrada(int vezes, int res)
{
    if(vezes == 0)
    {
        if(res>0)
        {
            printf("Yuri foi o perdedor.");
        }else{
            printf("Kaio foi o perdedor.");
        }
    }
    else
    {
        int jogadaKaio, jogadaYuri, quemGanhou;

        scanf("%d%d", &jogadaYuri, &jogadaKaio);

        res += jogada(jogadaKaio, jogadaYuri);
        
        entrada(vezes - 1, res);
    }
}

int main()
{
    int vezesJogada;
    
    scanf("%d", &vezesJogada);

    entrada(vezesJogada, 0);

	return 0;
}