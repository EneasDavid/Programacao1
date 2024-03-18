#include <stdio.h>

int matrizDeathV(int i, int j, int matrizDath[][3], int x, int y, int luke){
	if (i<3){
		if (j<3){
			if (i==0 && j==2|| i==1 && j==1 || i==2 && j==0){
				if (matrizDath[i][j]==1) x++;	
				else y++;
			}
			else{
				if (matrizDath[i][j]==0) y++;
			}
			matrizDeathV(i, ++j, matrizDath, x, y, luke);
		}
		else matrizDeathV(++i, 0, matrizDath, x, y, luke);
	}
	else{
		if(x==3 && y==6){
			if(luke==1) return 0;
            else return 1;	
		}else{
			if (luke==0 && y!=6) return 0;
			else return -1;
		}
	}

}

int matrizDeathVPrimeira(int i, int j, int matrizDath[][3], int x, int y, int luke){
	if (i<3){
		if(j<3){
			if(i==j){
				if(matrizDath[i][j]==1) x++;	
				else y++;
			}else{
				if(matrizDath[i][j]==0) y++;
			}
			matrizDeathVPrimeira(i, ++j, matrizDath, x, y, luke);
		}
		else matrizDeathVPrimeira(++i, 0, matrizDath, x, y, luke);
	}
	else{
		if (x==3 && y==6){
			if (luke==1) return 0;
			else return 1;
		}
		else{
			int valor=matrizDeathV(0,0, matrizDath, 0,0, luke);
			return valor;
		}
	}

}

int amtrizLukeV(int i, int j, int matrizLuke[][3], int x, int y){
	if(i<3){
		if(j<3){
			if(i==0 && j==2|| i==1 && j==1 || i==2 && j==0){
				if(matrizLuke[i][j]==1) x++;	
				else y++;
			}else{
				if(matrizLuke[i][j]==0) y++;
			}
			amtrizLukeV(i, ++j, matrizLuke, x, y);
		}
		else amtrizLukeV(++i, 0, matrizLuke, x, y);
	}else{
		if(x==3 && y==6)return 1;
		else return 0;
	}

}

int matrizLukePrimeira(int i, int j, int matrizLuke[][3], int x, int y) {
	if(i<3){
		if(j<3){
			if(i==j){
				if(matrizLuke[i][j]==1) x++;	
			}else{
				if(matrizLuke[i][j]==0) y++;
			}
			matrizLukePrimeira(i, ++j, matrizLuke, x, y);
		}
		else matrizLukePrimeira(++i, 0, matrizLuke, x, y);
	}
	else{
		if(x==3 && y==6){
			return 1;
		}else{
			int luke=amtrizLukeV(0,0, matrizLuke, 0,0);
			return luke;
		}
	}

}

int lerMatrizDath(int i, int j, int matrizDath[][3], int matrizLuke[][3], int vidaL, int vidaD, int *flag){
	if(i<3){
		if(j<3){
		    if(scanf("%d", &matrizDath[i][j])==EOF) *flag=1;
			lerMatrizDath(i, ++j, matrizDath, matrizLuke, vidaL, vidaD, flag);
		}
		else lerMatrizDath(++i, 0, matrizDath, matrizLuke, vidaL, vidaD, flag);
	}else{
	   	int luke=matrizLukePrimeira(0, 0, matrizLuke, 0, 0);
		int valor=matrizDeathVPrimeira(0, 0, matrizDath, 0, 0,  luke);
		return valor;
	}
}

int lerMatrizLuke(int i, int j, int matrizLuke[][3]){
	if (i<3){
		if (j<3){
			scanf("%d", &matrizLuke[i][j]);
			lerMatrizLuke(i, ++j, matrizLuke);
		}
		else lerMatrizLuke(++i, 0, matrizLuke);
	}
}

void rounds(int matrizLuke[][3], int matrizDath[][3], int vidaD, int vidaL, int valor){	
    int flag=0;
	int x=lerMatrizLuke(0,0, matrizLuke);
	valor=lerMatrizDath(0, 0, matrizDath, matrizLuke, vidaL, vidaD, &flag);
		
	if(valor==1) vidaL-=15;
	else if(valor==-1)vidaD-=15;
	

    if(flag==1){
    	if(vidaL>vidaD) printf("Luke Skywalker venceu.\n");
    	else if(vidaD>vidaL) printf("Darth Vader venceu.\n");
    	else printf("Houve empate.\n");
    }else{
        rounds(matrizLuke, matrizDath, vidaD, vidaL, valor);
    }
}

int main(){
	int vidaL, vidaD;
	scanf("%d %d\n", &vidaL, &vidaD);
	int matrizLuke[3][3];
	int matrizDath[3][3];
	rounds(matrizLuke, matrizDath, vidaD, vidaL, 0);
	return 0;
}