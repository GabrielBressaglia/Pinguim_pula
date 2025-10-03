#pragma once

#include <SFML/Graphics.hpp>
#include "../Cabecalhos/Pinguim.hpp"

// Pensar em uma forma de esvaziar

//CLASSE DO NÓ
class Node{
    private:
        PinguimColetavel pinguim; //Valor do nó
        Node* proximo; //Ponteiro para o próximo nó da classe Node

    public:
        //Construtor
        Node(const PinguimColetavel& p) :
        pinguim(p), 
        proximo(nullptr)
        {}

        //Métodos
        char getValor(){
            return pinguim.get_tipo_pinguim();
        }

        void setProximo(Node* p){
            proximo = p;
        }

        Node* getProximo(){
            return proximo;
        }

        
};


//CLASSE DA LISTA ENCADEADA
class ListaEncadeada{
    private:
        Node* cabeca;
        Node* final;

    public:
        //Construtor
        ListaEncadeada(){
            cabeca = nullptr;
            final = nullptr;
        }

        //Destrutor
        ~ListaEncadeada(){
            Node* atual = cabeca;
            while(atual!=nullptr){
                Node* temp = atual;
                atual = atual->getProximo();
                delete temp;
            }
            cabeca = nullptr;
            final = nullptr;
        }

        bool vazio(){
            if(cabeca == nullptr && final == nullptr){
                return true;
            } else {
                return false;
            }
        }
        void procuraX(const PinguimColetavel& valor, Node** P, Node** Anterior, bool& encontrouX) {
            *P = cabeca;
            *Anterior = nullptr;

            // anda até encontrar posição ou elemento maior
            while (*P != nullptr && (*P)->getValor() < valor.get_tipo_pinguim()) {
                *Anterior = *P;
                *P = (*P)->getProximo();
            }

            encontrouX = (*P != nullptr && (*P)->getValor() == valor.get_tipo_pinguim());
        }

       void adicionarEmOrdem(const PinguimColetavel& valor, bool& deuCerto) {
            Node* P, *Anterior;
            bool AchouX;

            procuraX(valor, &P, &Anterior, AchouX);

            if (AchouX) { // já existe um igual, não insere
                deuCerto = false;
                return;
            }

            Node* novo = new Node(valor);

            if (Anterior == nullptr) { // insere no início
                novo->setProximo(cabeca);
                cabeca = novo;
            } else { // insere depois do anterior
                Anterior->setProximo(novo);
                novo->setProximo(P);
            }

            if (P == nullptr) { // se inseriu no fim, atualiza final
                final = novo;
            }

            deuCerto = true;
        }

        void removerPorValor(const PinguimColetavel& valor, bool& deuCerto) {
            if (vazio()) {
                deuCerto = false;
                return;
            }

            Node* P, *Anterior;
            bool AchouX;

            procuraX(valor, &P, &Anterior, AchouX);

            if (!AchouX) {
                deuCerto = false;
                return;
            }

            if (Anterior == nullptr) { // removendo cabeça
                cabeca = cabeca->getProximo();
                if (P == final) final = nullptr;
            } else {
                Anterior->setProximo(P->getProximo());
                if (P == final) final = Anterior;
            }

            delete P;
            deuCerto = true;
        }
        bool contem(char tipo) const 
        {
            Node* atual = cabeca;
            while (atual != nullptr) {
                if (atual->getValor() == tipo) {
                    return true;
                }
                atual = atual->getProximo();
            }
            return false;
        }
        void deleta() {
            Node* atual = cabeca;
            while (atual != nullptr) {
                Node* temp = atual;
                atual = atual->getProximo();
                delete temp;
            }
            cabeca = nullptr;
            final = nullptr;
        }
    };