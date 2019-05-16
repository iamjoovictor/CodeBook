#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio (0);
#define MAXN 100123

using namespace std;

int FT [MAXN];

int getFT(int n){ //Captação do Valor da somatória
    int v=0;
    for(int i=n;i;i-= i&-i) v+=FT [i];
    return v;
}

void setFT(int n,int value,int tam){ //Atualização
    for(int i=n;i<tam+1;i+= i&-i) FT[i]+=value;
}

int main (){_
    int n,x,a,b,result,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
    	    cin>>x;
    	    setFT(i+1,x,n+5);
    	}
    	for(int i=0;i<q;++i){
    	    cin>>a>>b;
    	    result=getFT(b)-getFT(a-1); //Soma dos valores até b menos soma dos valores até a-1
    	    cout << (result%2==0 ? "Sim":"Nao")<<endl;
    	
    	}

    return 0;
}
