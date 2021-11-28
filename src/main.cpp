#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void readFile(string filename) {
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
    cout << matrix.size() << endl;

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        for (long unsigned int j = 0; j < matrix[i].size(); j++) {
            
            matrix[i][j] = (v_lines[(i * rows) + j]);
        }
        //cout << i << " ";
        //std::cout << endl;
    }

    cout << matrix.size() << endl;
    for (long unsigned int i = 0; i < matrix.size(); i++) {
            for (long unsigned int j = 0; j < matrix[i].size(); j++) {
                //cout << j << " ";
                cout << matrix[i][j] << " ";
            }
            //cout << i << " ";
            cout << endl;
        }


    file.close();
}



void arguments(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::string aux = argv[i];
        if (aux == "-f") {
            string filename = argv[i+1];
            //cout << filename << endl;
            readFile(filename);
        } else if (aux == "-n") {
            int neighbours = atoi(argv[i+1]);
            //cout << neighbours << endl;
        } 
    }

    
}


int main(int argc, char** argv){
    arguments(argc, argv);
}