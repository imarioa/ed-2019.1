#include <iostream>
#include <iomanip>
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

        while(node->next != first){
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
        }
        if( (node->value == esc) && (esc > 0)){
                cout << node->value << ">" <<  " ";
            }else if((node->value == esc) && (esc < 0)){
                 cout << "<"  << node->value << " ";
            }else{
                cout << node->value << " ";
            }

        cout << "]\n";
    }

    void push_front(int value){
        Node *node = new Node(value, first, first->prev);
        if(first->next == first){
            first->next = node;
            first->prev = first;
            first = node;
        }else{
            first->prev->next = node;
            first->prev = node;
            first = node;
        }
    }
    void push_back(int value){
        Node *node = new Node(value, first, first->prev);
        if(first->next == first){
            first->next = node;
            first = node;
            first->prev = first;
            
            
        }else{
            first->prev->next = node;
            first->prev = node;
            //first=node;
        }
    }
    void insert(Node *ref, int value){
        Node *node = new Node(value, ref, ref->prev);

        ref->prev = node;
        ref->prev->next = node;
    }
    void pop_front(){
        if(first->next == first)
            return;
        remove(first);
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
    void mostrar(){
        Node *node = first->next;
        cout << node->prev->value << " ";
        while(node != first){
            cout << node->value << " ";
            node = node->next;
        }
        cout << "\n";
    }
    
    
};

int main(){
   
    Lista lista;
    int num;
    int fase;
    int esc;

    cin >> num >> esc >> fase;
    
    for(int i = 0; i < num; i++){
        lista.push_back(((i + 1) * fase)); 
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
            //cout << aux->next->value << "\n";
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
    

