#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 500

using namespace std;

int vis[MAXN][MAXN],n,m,cont;
char mat[MAXN][MAXN];

void ff(int i,int j){
    if(i>n || j>m || j<1 || i<1) return ; //Caso saia da matriz
    if(vis[i][j]!=0 || mat[i][j]!='C') return ; //Caso já tenha sido visitada, ou for diferente da condição de Castelo
    vis[i][j]=1; //Marcar a posição como visitada
    ++cont; //Contador, quantidade de posições visitadas
    ff(i+1,j); //Baixo
    ff(i-1,j);  //Cima
    ff(i,j+1);  //Direita
    ff(i,j-1);  //Esquerda
}

int main(){_
    int tot=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>mat[i][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cont=0;
            ff(i,j);
            if(cont>tot) tot=cont;
        }
    }
    cout<<tot<<endl;


    return 0;
}
