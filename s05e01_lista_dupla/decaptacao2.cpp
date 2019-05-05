#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
    Node(int value = 0, Node *next = nullptr, Node *prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;

    }
};

struct Lista{
    
    Node *first;
    
    Lista(){
        first = new Node();
        first->prev = first;
        first->next = first;  
    }

    void show(int esc){
        cout << "[ ";
        Node *node = first;

        do{
            if( (node->value == esc) && (esc > 0)){
                cout << node->value << ">" <<  " ";
                node = node->next;
            }else if((node->value == esc) && (esc < 0)){
                 cout << "<"  << node->value << " ";
                 node = node->next;
            }else{
                cout << node->value << " ";
                node = node->next;
            }
        }while(node->next != first->next);
    
        cout << "]\n";
    }

    void inserir(int value){
        Node *node = new Node(value, first, first->prev);
        if(first->next == first){
            first = node;
            first->prev = first;          
        }else{
            first->prev->next = node;
            first->prev = node;
        }
    }

    void remove(Node *ref){
        if(ref == first){
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
        }else{
            ref->prev->next = ref->next;
            ref->next->prev = ref->prev;
        }
        delete ref;
    }
};

int main(){
   
    Lista lista;
    int num;
    int fase;
    int esc;

    
    cin >> num >> esc >> fase;
    

    for(int i = 0; i < num; i++){
        lista.inserir(((i + 1) * fase)); 
        fase *= -1;
    }  
    Node *aux = lista.first;
     for(int i = 0; i < num; i++){
        if(esc ==  (aux->value * -1)){
            esc = esc * -1;
        }
        aux = aux->next;
    }
    
    while(aux->value != esc){
            aux = aux->next;
    }

   while(lista.first != lista.first->next){
        lista.show(esc);
        if(esc > 0){
            lista.remove(aux->next);
            
            for(int i = 0; i < esc; i++){
                aux = aux->next;
            }
            esc = aux->value;          
        }else{
            lista.remove(aux->prev);
            for(int i = 0; i < (esc * (-1)); i++){
                aux = aux->prev;
            }
            esc = aux->value;
        }
   }
        cout << "[ ";
        if(esc > 0){
            cout << aux->value << ">";
        }else{
             cout << "<" << aux->value;
        }
        cout << " ]\n";
        return 0;
    }