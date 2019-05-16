#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio();

using namespace std;

struct tpessoa{ //Organização em uma struct
    int nota;
    string nome;
};

int cmp(tpessoa a,tpessoa b){
    if(a.nota!=b.nota) return a.nota<b.nota; //Ordenação crescente de nota
    return a.nome>b.nome; //Ordenação decrescente de nome do final por inicio
}

int main(){_
    tpessoa pessoa[101];
    int n,i,k;
    k=1;
    while(cin>>n){
        for(i=0;i<n;++i){
            cin>>pessoa[i].nome>>pessoa[i].nota;
        }
        sort(pessoa, pessoa+n,cmp);
        cout<<"Instancia "<<k<<endl<<pessoa[0].nome<<endl<<endl;
        //Printa o nome da pessoa na primeira posição
        ++k;
    }

    return 0;
}
