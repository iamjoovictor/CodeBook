#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100123

using namespace std;

int vet[MAXN];

int f(int mid,int x){
    return(vet[mid]>=x); //Verificar se vet[pos] maior que o valor procurado
}

int busca(int num,int tam){
    int lo=0,hi=tam-1,mid;
    while(lo<hi){
        mid=lo+((hi-lo)/2); //Valor médio
        if(f(mid,num)) hi=mid; //Se a posição que estou é maior que o valor procurado, o final se torna o meio do vetor
        else lo=mid+1;
    }
    return lo;

}

int main(){_
    int n,q,num,pos,t=0;
    while(cin>>n>>q && (n||q)){
        for(int i=0;i<n;++i) cin>>vet[i];
        sort(vet,vet+n); //Ordenação do vetor, para o princípio de busca binária
        cout<<"CASE# "<<++t<<":"<<endl;
        for(int i=0;i<q;++i){
            cin>>num;
            pos=busca(num,n);
            if(vet[pos]==num) cout<<num<<" found at "<<pos+1<<endl;
            else cout<<num<<" not found"<<endl;

        }
    }
}
