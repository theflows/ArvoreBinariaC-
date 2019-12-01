#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <iostream>
using namespace std;
//Busca BINARIA

template <typename Tipo>

struct Node{
    Node <Tipo> *pEsq;
    Node <Tipo> *pDir;
    Tipo info;
};

template <typename Tipo>

struct Bst{
    Node <Tipo> *pRaiz;

    Bst(){
        pRaiz = NULL;
    }

    void insere(Node<Tipo>*&t, Tipo x){
        if(t == NULL){
            t = new Node<Tipo>;
            t->info = x;
            t->pEsq = NULL;
            t->pDir = NULL;
        }
        else{
            if(x < t->info){
                insere(t->pEsq, x);
            }

            else{
                insere(t->pDir, x);
            }
        }
    }
    bool listavazia(){
       return pRaiz==NULL;
    }

    void emOrdem(Node<Tipo>*&t){
        if(t != NULL){
            emOrdem(t->pEsq);
            cout << t -> info << " ";
            emOrdem(t->pDir);
        }

    }
    void preOrdem(Node<Tipo>*&t){
        if(t != NULL){
            cout << t -> info << " ";
            preOrdem(t->pEsq);
            preOrdem(t->pDir);
        }

    }
    void posOrdem(Node<Tipo>*&t){
        if(t != NULL){
            posOrdem(t->pEsq);
            posOrdem(t->pDir);
            cout << t -> info << " ";
        }

    }

    int removeRaiz (Node<Tipo>*&t, int valor)
    {
        Node<Tipo>*temp = NULL;

        if(t == NULL)
            return 0;
        if(valor == t->info)
        {
            temp = t;
            if(pRaiz->pEsq == NULL)
                t = t->pDir;
            else if(t->pDir == NULL)
                t = t->pEsq;
            else
            {
                t = temp;
            }
            delete temp;
            return 1;
        }
        else if(valor < t->info)
            return removeRaiz(t->pEsq, valor);
        else
            return removeRaiz(t->pDir, valor);

    }
    Tipo noMaior(Node<Tipo>*&t)
    {
        Node<Tipo>*temp = NULL;
        temp = t;
        if(temp->pDir == NULL)
        {
            t = t->pEsq;
            return temp->info;
        }
        else
            return noMaior(t->pDir);
    }
    Tipo noMenor(Node<Tipo>*&t)
    {
        Node<Tipo>*temp = NULL;
        temp = t;
        if(temp->pEsq == NULL)
        {
            t = t->pEsq;
            return temp->info;
        }
        else
            return noMenor(t->pEsq);
    }
    bool busca (Node<Tipo>*&t, int valor)
    {   bool v=true;
        while (t != NULL)
        {
            if (t->info == valor)
                return v;
            else if (valor < t->info)
                t = t->pEsq;
            else
                t = t->pDir;
        }

        return 0;
    }
};


#endif // 3_H_INCLUDED
