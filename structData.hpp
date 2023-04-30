#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <list>
using std::map;
using std::string;
using std::vector;
using std::list;



class Espace
{
public:
    int indice;
    string name;
    Espace(int indice, string name) : indice(indice), name(name){};
};

class Reaction
{
    public:
    Espace *enzyme;
    Espace *substats[16];
    int n_substats;
    Espace *products[16];
    int n_products;
    Espace *units[16];
    int n_units;
    double *concentrations[16];
    double Kcat;
    vector<Reaction *> suivants;
};

class Inhibition
{
    public:
    Espace *enzyme;
    Espace *substats[1];
    int n_substats;
    Espace *units[1];
    int n_units;
    double *concentrations[1];
    vector<Inhibition *> suivants;
};

class Edge{
    public:
    vector<int> fromIndices;
    vector<int> toIndices;
    void addFromIndice(int indice){ this->fromIndices.push_back(indice); };
    void addToIndice(int indice){ this->toIndices.push_back(indice); };
};

struct nodeFromTo{
    vector<int> from;
    vector<int> to;
};





