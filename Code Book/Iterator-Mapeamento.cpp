#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;
typedef map<string,int>mk;

int main(){_
    string mat,morto;
    mk m,k;
    int aux;
    while(cin>>mat>>morto){
        ++m[mat];
        ++k[morto];
    }
    cout<<"HALL OF MURDERERS"<<endl;
    mk::iterator i;
    for(i=m.begin();i!=m.end();++i){ //Iterator indo do início do map até o final
        aux=k[i->first];
        if(aux==0) cout<<i->first<<" "<<i->second<<endl;
    }

    return 0;
}
