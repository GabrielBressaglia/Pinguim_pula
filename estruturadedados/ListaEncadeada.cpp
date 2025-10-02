#include <iostream>
#include <vector>
using std::string;

//CLASSE DO NÓ
class Node{
    private:
        string valor; //Valor do nó
        Node* proximo; //Ponteiro para o próximo nó da classe Node

    public:
        //Construtor
        Node(string v){
            valor = v;
            proximo = nullptr;
        }

        //Métodos
        string getValor(){
            return valor;
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
        int tamanho;

    public:
        //Construtor
        ListaEncadeada(){
            cabeca = nullptr;
            final = nullptr;
            tamanho = 0;
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
            tamanho = 0;

        }

        bool vazio(){
            if(cabeca == nullptr && final == nullptr){
                return true;
            } else {
                return false;
            }
        }

        void adicionarNoFinal(string valor){
            Node* novo = new Node(valor);
            if(vazio()==true){
                cabeca = final = novo;
            } else{
                final->setProximo(novo);
                final = novo; 

            }
            tamanho++;
        }

        void removerPorValor(string valor){
            if (vazio()){
                std::cout << "Lista vazia, nada a remover.\n";
                return;
            }

            Node* atual = cabeca;
            Node* anterior = nullptr;

            while (atual != nullptr && atual->getValor() != valor) {
                anterior = atual;
                atual = atual->getProximo();
            }

            if (atual == nullptr) {
                std::cout << "Valor não encontrado na lista.\n";
                return;
            }

            if (anterior == nullptr) { 
                cabeca = cabeca->getProximo();
                if (atual == final) final = nullptr; 
            } else { 
                anterior->setProximo(atual->getProximo());
                if (atual == final) final = anterior;
            }

            delete atual;
            tamanho--;
        }

        void imprimir() {
            if (vazio()) {
                std::cout << "Lista vazia.\n";
                return;
            }

            Node* atual = cabeca;
            while (atual != nullptr) {
                std::cout << atual->getValor() << " -> ";
                atual = atual->getProximo();
            }
            std::cout << "nullptr\n";
        }

        int getTamanho() {
            return tamanho;
        }

        void removerDoInicio() {
            if (vazio()) {
                std::cout << "Lista vazia, nada a remover.\n";
                return;
            }

            Node* temp = cabeca;           
            cabeca = cabeca->getProximo(); 

            if (temp == final) {            
                final = nullptr;
            }

            delete temp;                    
            tamanho--;                     
        }



    };