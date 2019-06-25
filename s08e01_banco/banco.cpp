#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

struct Client{
    string id;
    int docs;
    int pac;

    Client(string id,int docs, int pac){
        this->id = id;
        this->docs = docs;
        this->pac = pac;
    }

    void show(){
        cout<< this->id << ":" << this->docs << ":" << this->pac ;
    }
};

struct Banco{
    int docs_ad = 0;
    int docs_pe = 0;
    vector<Client*> caixas;
    list<Client*> fila_entrada;
    list<Client*> fila_saida;


    void init(int n){
        for(int i = 0; i < n; i++){
            caixas.push_back(nullptr);
        }
    }

    void in (string nome, int docs, int pac){
        Client *new_client = new Client(nome,docs,pac);
        fila_entrada.push_back(new_client);
    }

    void show(){
        for(int i = 0; i < (int) caixas.size();i++){
            if(caixas[i]!= nullptr) {
                cout << "[";
                caixas[i]->show();
                cout << "]";
            }
            else
                cout << "[" << "]";
        }
        cout << endl << "in :{ ";
        for(auto it = fila_entrada.begin(); it != fila_entrada.end();it++){
            Client *aux = *it;
            aux->show();
            cout << " ";
        }
        cout <<"}";

        cout << endl << "out:{ ";
        for(auto it = fila_saida.begin(); it != fila_saida.end();it++){
            Client *aux = *it;
            aux->show();
            cout << " ";
        }
        cout <<"}" << endl;
    }

    void tic(){
        fila_saida.erase(fila_saida.begin(),fila_saida.end());

        for(int i = 0; i < (int) caixas.size();i++){
            if(caixas[i] != nullptr){
                if(caixas[i]->docs > 0){
                    caixas[i]->docs --;
                    this->docs_ad ++;
                }
                else{
                    fila_saida.push_back(caixas[i]);
                    caixas[i] = nullptr;
                }
            }
            else{
                if(fila_entrada.size() > 0){
                    auto it = fila_entrada.front();
                    caixas[i] = it;
                    fila_entrada.pop_front();
                }
            }
        }

        for(auto it = fila_entrada.begin(); it != fila_entrada.end();){
            Client *aux = *it;
            if(aux->pac > 0)
                aux->pac --;
            else{
                this->docs_pe+=aux->docs;
                fila_saida.push_back(aux);
                auto it2 = it;
                it++;
                fila_entrada.erase(it2);
                continue;
            }
            it++;
        }

    }
};




int main() {
    Banco *bradesco = new Banco();
    string cmd, linha;
    int tics = 0;

    while(true){
        getline(cin,linha);
        stringstream cut(linha);
        cut >> cmd;
        if(cmd == "init"){
            int n;
            cut >> n;
            
            bradesco->init(n);
            
        }
        else if(cmd == "in"){
            string id;
            int docs;
            int pac;
            while(cut >> id && cut >> docs && cut >> pac){
                bradesco->in(id,docs,pac);
            }
        }
        else if(cmd == "show")
            bradesco->show();
        else if(cmd == "tic"){
            tics++;
            bradesco->tic();
        }
        else if(cmd == "finish")
            break;
    }

    //------Banco fechou-------//

    while(true){
        bool existe = false;
        if(bradesco->fila_entrada.size() > 0){
            bradesco->tic();
            continue;
        }
        else{
            for(int i = 0; i < (int) bradesco->caixas.size(); i++){
                if(bradesco->caixas[i] != nullptr){
                    existe = true;
                }
            }       
        }
        if(existe){
            bradesco->tic();
        }
        else
            break;
    }


    if((int) bradesco->fila_saida.size() > 0)
        bradesco->fila_saida.erase(bradesco->fila_saida.begin(),bradesco->fila_saida.end());

    cout << "received: " << bradesco->docs_ad << endl;
    cout << "lost: " << bradesco->docs_pe << endl;
    cout << "tics: " << tics << endl;

}