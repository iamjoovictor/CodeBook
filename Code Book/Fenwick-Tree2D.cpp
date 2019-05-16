#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1112

using namespace std;

int ft[MAXN][MAXN],tam;

int getft(int n,int m){
	int v=0;
	for(int i=n; i; i-=i&-i){ //O princípio é o mesmo, aplica-se lsb para ambos os for's
		for(int j=m; j; j-=j&-j){
			v+=ft[i][j];
		}
	}
	return v;
}

void setft(int n,int m,int value){
	for(int i=n;i<=tam;i+=i&-i){
		for(int j=m;j<=tam;j+=j&-j){
			ft[i][j]+=value;
		}
	}
}

int main(){_
	int a,b,xi,yi,xii,yii,ga,gb,n,gc,gd,inte;
	while(cin>>tam>>n){
		for(int i=1;i<=tam;++i){ //Inicialização das posições iguais a 0
			for(int j=1;j<=tam;++j){ //Pois, a questão é por EOF
				ft[i][j]=0;
			}
		}
		for(int i=1;i<=tam;++i){ //Set das posições da matriz
			for(int j=1;j<=tam;++j){
				cin>>inte; //1 ou 0
				setft(i,j,inte);
			}
		}
		for(int i=0;i<n;++i){
			cin>>a>>b; 
			cin>>xi>>yi>>xii>>yii;
			setft(a,b,1); //Set 1, na posição (i,j)
			ga=getft(xii,yii);
			gb=getft(xi-1,yi-1); 
			gc=getft(xii,yi-1);
			gd=getft(xi-1,yii);
			cout<<ga+gb-gc-gd<<endl; //Diagrama de Venn, gb está contido em gc e gd por isso soma-se gb
		}
	}
	

	return 0;
}

