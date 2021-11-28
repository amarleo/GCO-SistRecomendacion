#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

void printMatrix(vector<vector<string>> matrix) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        for (long unsigned int j = 0; j < matrix[i].size(); j++) {
            //cout << j << " ";
            cout << matrix[i][j] << " ";
        }
        //cout << i << " ";
        cout << endl;
    }
}

vector<vector<string>> readFile(string filename) {
    string lines;
    
    string source = "./files/" + filename;
    vector<vector<string>> matrix;
    vector<string> v_lines;
    std::stringstream ss;
    cout << source << endl;
    ifstream file(source);
    long unsigned int cols = 0;
    long unsigned int rows = 0;
    while (getline(file, lines)) {
        //std::cout << lines.size() << endl;
        for (unsigned int i = 0; i < lines.size(); i++) {
            
            if (lines[i] != ' ') {
                string s_aux(1, lines[i]);

                v_lines.push_back(s_aux);

            }
            
        }   
        cols++;
        
    }

    rows = v_lines.size() / cols;
    matrix.resize(cols, vector<string>(rows));

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        for (long unsigned int j = 0; j < matrix[i].size(); j++) {            
            matrix[i][j] = (v_lines[(i * rows) + j]);
        }
    }

    file.close();
    return matrix;
}


void correlacionPearson(vector<vector<string>> matrix, int neighbours) {
    vector<string> u, v;
    vector<int> usuario;
    int contador_else = 0;
    int sumU = 0, sumV = 0, sumUV = 0;
    int squareSumU = 0, squareSumV = 0, contador = 0, index = 1;

    //     for(int i = 0; i < u.size(); i++) {
    //         cout << u[i] << endl;
    // }

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        for (long unsigned int j = 0; j < matrix[i].size(); j++) {   
            if (matrix[i][j] == "-") {
                usuario.push_back(i);
                cout << i;
            }
        }
    }
    for (int k = 0; k < usuario.size(); k++) {
        
        u = matrix[usuario[k]];

            if ((k + neighbours) < matrix.size()) {
                v = matrix[k + neighbours];
            } else {
                v = matrix[contador_else];
                contador_else++;
                cout << " "<<contador_else << " " << endl;
            }
            
            for(int i = 0; i < matrix.size(); i++) {

                if ((u[i] != "-") && (v[i]) != "-") {

                    sumU = sumU + stoi(u[i]);
                    sumV = sumV + stoi(v[i]);
                    sumUV = sumUV + stoi(u[i]) * stoi(v[i]);

                    squareSumU = squareSumU + stoi(u[i]) * stoi(u[i]);
                    squareSumV = squareSumV + stoi(v[i]) * stoi(v[i]);
                    contador++;
                }
            }
            float correlacion = (float)(contador * sumUV - sumU * sumV) / sqrt((contador * squareSumU - sumU * sumU) * (contador * squareSumV - sumV * sumV));
            cout << "sim(Person" << neighbours - 1 << ", Person" << k + neighbours  << ")= "<< correlacion << endl;
            index++;
    }

    


}

int main(int argc, char** argv){

    int neighbours;
    vector<vector<string>> matrix;
    for (int i = 0; i < argc; i++) {
        std::string aux = argv[i];
        if (aux == "-f") {
            string filename = argv[i+1];
            matrix = readFile(filename);

        } else if (aux == "-n") {
            neighbours = atoi(argv[i+1]);
        } 
    }



    unsigned int metric;
    unsigned int prediction;
    cout << "Introduzca el número que referencia a la métrica deseada:\n1. Correlación de Pearson\n2. Distancia coseno\n3. Distancia Euclídea\n -> ";
    cin >> metric;

    switch(metric) {
        case 1: 
         for (int i = 1; i <= neighbours; i++) {
             correlacionPearson(matrix, i);
         }
        

        break;
        case 2: 

        break;
        case 3:
        break;

        default: 
            cout << "ERROR: Se ha introducido un valor erróneo.";
        break;
    }

}