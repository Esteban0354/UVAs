

#include <iostream>
#include <vector>

using namespace std;

class Candidato{
private:
    string nombre;
    string partido;
    int votos;
public:
    Candidato(string nombre, string partido, int votos);
    bool operator < (const Candidato& otro)const{
        return votos < otro.votos;
    }
    string getNombre(){
        return nombre;
    }
    string getPartido(){
        return partido;
    }
    int getVotos(){
        return votos;
    }
    void addVoto(){
        votos++;
    }

};

Candidato::Candidato(string nombre, string partido, int votos) {
    this->nombre = nombre;
    this->partido = partido;
    this->votos = votos;
}





int main(){
    vector<Candidato> candidatos;
    vector<string> nombresVotacion;
    string nombreCandidato;
    string partidoCandidato;
    string candidatoVotado;
    int votosCandidato;
    int cases;
    int numCandidates;
    int numVotes;
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; ++i) {
        cin >> numCandidates;
        cin.ignore();
        for (int j = 0; j < numCandidates; ++j) {
            getline(cin,nombreCandidato);
            getline(cin,partidoCandidato);
            candidatos.push_back({nombreCandidato,partidoCandidato,0});
        }
        cin >> numVotes;
        cin.ignore();
        for (int j = 0; j < numVotes; ++j) {
            getline(cin,candidatoVotado);
            nombresVotacion.push_back(candidatoVotado);
        }
        for (int j = 0; j < nombresVotacion.size(); ++j) {
            for (vector<Candidato>::iterator it = candidatos.begin(); it != candidatos.end(); ++it) {
                if (nombresVotacion[j] == it->getNombre()) {
                    it->addVoto();
                }
            }
        }

        int maxVoto = 0;
        bool tie = false;
        Candidato* ganador = nullptr;
        for (int j = 0; j < candidatos.size(); ++j) {
            if(candidatos[j].getVotos() > maxVoto){
                maxVoto = candidatos[j].getVotos();
                ganador = &candidatos[j];
            }else if(candidatos[j].getVotos() == maxVoto){
                tie = true;
            }
        }
        if (tie){
            cout << "tie"<<endl;

        }else{
            cout << ganador->getPartido();
        }

    }
    return 0;
}

/*
#include <queue>
#include <iostream>

using namespace std;

class Candidato{
private:
    string nombre;
    string partido;
    int votos;
public:
    Candidato(string nombre, string partido, int votos);
    bool operator < (const Candidato& otro)const{
        return votos < otro.votos;
    }
    string getNombre(){
        return nombre;
    }
    string getPartido(){
        return partido;
    }
    int getVotos(){
        return votos;
    }
    void addVoto(){
        votos++;
    }
};


int main(){
    priority_queue<Candidato> elecciones;
    priority_queue<Candidato> votaciones;
    string nombreCandidato;
    string partidoCandidato;
    int votosCandidato;
    int cases;
    int numCandidates;
    int numVotes;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        cin >> numCandidates;
        for (int j = 0; j < numCandidates; ++j) {
            while(!elecciones.empty()) {
                elecciones.pop();
            }
            cin >> nombreCandidato;
            cin >> partidoCandidato;
            Candidato aux (nombreCandidato,partidoCandidato,0);
            elecciones.push(aux);
        }
        cin >> numVotes;
        for (int j = 0; j < numVotes; ++j) {
            cin >> nombreCandidato;
            while (!elecciones.empty()) {
                Candidato c = elecciones.top();
                elecciones.pop();
                if (c.getNombre() ==nombreCandidato) {
                    c.addVoto();
                }
                votaciones.push(c);
            }
            while (!elecciones.empty()) {
                elecciones.pop();
            }
            elecciones = votaciones;
        }
        if (elecciones.empty()) {
            cout << "tie" << endl;
        } else {
            Candidato ganador = elecciones.top();
            if (ganador.getPartido() == "independent") {
                cout << "independent" << endl;
            } else {
                cout << ganador.getPartido() << endl;
            }
        }

    }

    return 0;
}
 */