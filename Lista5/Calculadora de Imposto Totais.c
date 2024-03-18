#include <stdio.h>

void calcularValorProduto(double cotacaoDolar,double *vProduto){
    *vProduto*=cotacaoDolar;
}

void calcularValorFrete(double cotacaoDolar,double *vFrete){
    *vFrete*=cotacaoDolar;
}
int main() {
    double cotacaoDolar, aliquotaICMS, vProduto, vFrete, vProdutoSemFrete;
    scanf("%lf%lf%lf%lf", &cotacaoDolar, &aliquotaICMS, &vProduto, &vFrete);
    int frete=1;
    if(vProduto>=2500){
        frete=0;
    }
    calcularValorProduto(cotacaoDolar, &vProduto);
    calcularValorFrete(cotacaoDolar, &vFrete);
    double total=vFrete+vProduto;
    if(frete){
        vProdutoSemFrete=total;
    }else{
        vProdutoSemFrete=total-vFrete;
    }
    double importacao=vProdutoSemFrete*.6;
    double valorFinal=(vProdutoSemFrete+importacao)/(1-(aliquotaICMS/100));
    double vICMS=valorFinal*(aliquotaICMS/100);
    double totalImposto=vICMS+importacao;
    if(!frete){
        valorFinal+=vFrete;
    }
    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n",cotacaoDolar,vProduto, vFrete, total, importacao,vICMS,totalImposto,valorFinal);

    if(frete){
        printf("Impostos calculados com o frete");
    }else{
        printf("Impostos calculados sem o frete");
    }
	return 0;
}
