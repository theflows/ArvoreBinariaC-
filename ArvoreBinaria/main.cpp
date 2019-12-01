#include <iostream>
#include "ARVORE.h"

using namespace std;

int main()
{
    cout << "B S T" << endl;
    Bst <int> t;
    int opc, x;
    do{
        cout<<"1- insere"<<endl;
        cout<<"2- Remover"<<endl;
        cout<<"3- exibir a fila"<<endl;
        cout<<"4- Buscar"<<endl;
        cout<<"5- Mostrar numero Maior"<<endl;
        cout<<"6- Mostrar numero Menor"<<endl;
        cout<<"9- fim"<<endl;
        cout<<"Selecione:";
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Digite o numero:";
            cin>>x;
            t.insere(t.pRaiz, x);
            cout<<"Sucesso!"<<endl;
            break;
        case 2:
           if(t.listavazia()){
               cout<<"Fila vazia..."<<endl;
           }
            else{
                cout<<"Insira o valor para remover : "<<endl;
                cin>>x;
                if(t.removeRaiz(t.pRaiz,x)){
                 cout<<"Sucesso!"<<endl;
                }
                else
                    cout<<"Valor n encontrado!"<<endl;
            }
            break;
       case 4:
            if(t.listavazia()){
                cout<<"Lista vazia..."<<endl;
            }
            else{
            cout<<"Insira o valor para Busca : "<<endl;
            cin>>x;
            if(t.busca(t.pRaiz,x)){
                 cout<<"Sucesso! "<<x<<" Encontrado"<<endl;
                }
                else
                    cout<<"Valor "<<x<<" n encontrado!"<<endl;
            }
            break;
        case 3:
                cout<<"\nPre ordem"<< endl;
                t.preOrdem(t.pRaiz);

                cout<<"\nEm ordem"<< endl;
                t.emOrdem(t.pRaiz);

                cout<<"\nPos Ordem" <<endl;
                t.posOrdem(t.pRaiz);
            cout<<"\n-------------"<<endl;
            break;
            case 5:
            cout<< "O maior valor: "<<t.noMaior(t.pRaiz)<<endl;
            break;
            case 6:
            cout<< "O menor valor: "<<t.noMenor(t.pRaiz)<<endl;
            break;
        case 9:
            cout<<"fim"<<endl;
            break;
        default:
            cout<<"opcao invalida"<<endl;
            break;
        }
    }while (opc!=9);
    return 0;
}
