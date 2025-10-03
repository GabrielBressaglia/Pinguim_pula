#include <iostream>

class Fila {
private:
    struct No {
        char pinguim;
        No* proximo;
        No(char x) : pinguim(x), proximo(nullptr) {}
    };

    No* inicio;
    No* fim;
    unsigned n_elementos;

public:
    Fila();
    ~Fila();

    bool vazia();
    void adicionar(char X, bool& feedback);
    void remover(char& X, bool& feedback);
    char frente(bool& feedback);
};

Fila::Fila() {
    inicio = nullptr;
    fim = nullptr;
    n_elementos = 0;
}

Fila::~Fila() {
    // Limpa toda a fila
    while (!vazia()) {
        char temp;
        bool fb;
        remover(temp, fb); 
    }
}

bool Fila::vazia() {
    return (n_elementos == 0);
}

void Fila::adicionar(char X, bool& feedback) {
    No* novo = new No(X);
    if (!novo) {  // checagem de memória
        feedback = false;
        return;
    }

    if (vazia()) {
        inicio = fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }

    n_elementos++;
    feedback = true;
}

void Fila::remover(char& X, bool& feedback) {
    if (vazia()) {
        feedback = false;
        return;
    }

    No* temp = inicio; 
    X = temp->pinguim;
    inicio = inicio->proximo;
    delete temp; //temporário para armazenar o valor removido

    n_elementos--;
    if (vazia()) {  // se remover último elemento
        fim = nullptr;
    }

     feedback = true;
}

char Fila::frente(bool& feedback) {
    if (vazia()) {
        feedback = false;  
        return '\0';       
    }
    feedback = true;
    return inicio->pinguim;  // retorna o valor do primeiro nó
}