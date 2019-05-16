#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define INF 100000123
#define esquerda(u) (u<<1)
#define direita(u) ((u<<1)+1)
#define mid(l,r) ((l+r)>>1)

using namespace std;

vi M,m;
vi val;
int n,k;

void build(int node,int l,int r){
   if(l == r){
       M[node] = val[l];
       m[node] = val[l];
   }
   else{
       build(esquerda(node),l,mid(l,r));
       build(direita(node),mid(l,r)+1,r);
       M[node] = max(M[esquerda(node)],M[direita(node)]);
       m[node] = min(m[esquerda(node)],m[direita(node)]);
   }
}

void update(int node,int l,int r,int idx,int new_val){
   if(l == r){
       val[idx] = new_val;
       M[node] = new_val;
       m[node] = new_val;
   }
   else{
       if(l<=idx && idx<=mid(l,r)) update(esquerda(node),l,mid(l,r),idx,new_val);
       else update(direita(node),mid(l,r)+1,r,idx,new_val);
       M[node] = max(M[esquerda(node)],M[direita(node)]);
       m[node] = min(m[esquerda(node)],m[direita(node)]);
   }
}

int findMaior(int node,int left,int right,int l,int r){
   if(r < left || right < l) return 0;
   if(l <= left && right <= r) return M[node];
   int ans1 = findMaior(esquerda(node),left,mid(left,right),l,r);
   int ans2 = findMaior(direita(node),mid(left,right)+1,right,l,r);
   return max(ans1,ans2);
}

int findMenor(int node,int left,int right,int l,int r){
   if(r < left || right < l) return INF;
   if(l <= left && right <= r) return m[node];
   int ans1 = findMenor(esquerda(node),left,mid(left,right),l,r);
   int ans2 = findMenor(direita(node),mid(left,right)+1,right,l,r);
   return min(ans1,ans2);
}

int main(){_
    while(cin >> n){
        M = vi(4*n+1);
        m = vi(4*n+1);
        val = vi(n);
        for(int i=0;i<n;i++) cin >> val[i];
        build(1,0,n-1);
        cin >> k;
        while(k--){
            int op,a,b;
            cin >> op >> a >> b;
            if(op == 1) update(1,0,n-1,a-1,b);
            else{
                int maior = findMaior(1,0,n-1,a-1,b-1);
                int menor = findMenor(1,0,n-1,a-1,b-1);
                cout << abs(maior-menor) << endl;
            }
        }
    }
   return 0;
}
