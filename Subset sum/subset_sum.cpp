// Created by Facundo Gancedo on 02/04/2023.

#include <vector>
#include <iostream>
using namespace std;

vector<int> subset_sumLista(vector<int> lista,int idx,int k, int sum_rest, vector<int> *indices) {
    vector<int> falso;
    falso.push_back(-1);
    if (k == 0) return *indices;
    if (k < 0) return falso;
    if (k - sum_rest > 0) return falso;
    else {

        (*indices)[idx] = 1;//sumo el lugar donde estoy
        vector<int> result1 = subset_sumLista(lista, idx - 1, k-lista[idx], sum_rest - lista[idx], indices);

        (*indices)[idx] = 0;//no sumo el lugar dondeestoy
        vector<int> result2 = subset_sumLista(lista, idx - 1, k, sum_rest - lista[idx], indices);
        if (result1 != falso) {
            return result1;
        } else {
            return result2;
        }
    }
}

vector<int> llenarLista(vector<int> lista){
    cout << "Enter a list of numbers greater that 0, enter -1 to stop" << endl;
    int n =0;
    while(cin >> n && n != -1){
        lista.push_back(n);
    }
    return lista;
}




int main(){
    vector<int> prueba;
    prueba = llenarLista(prueba);
    vector<int> indices(prueba.size(),0);
    int sum_rest = 0;
    for(int i = 0;i<prueba.size();i++){
        sum_rest += prueba[i];
    }
    int k = 0;
    cout << "Ingrese la suma a la que quiere llegar:" << endl;
    cin>>k;
    vector<int> subsetSum = subset_sumLista(prueba, prueba.size()-1,k,sum_rest,&indices);
    cout << "Existe una combinacion de elementos que da esa suma" << endl;
    cout<< "El subconjunto es: {";
    for(int i = 0;i< subsetSum.size();i++){
        cout<<subsetSum[i]*prueba[i] <<",";

    }
    cout<< "}"<<endl;
    return 0;
}