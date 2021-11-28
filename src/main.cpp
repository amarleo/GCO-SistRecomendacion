#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> readFile(string filename) {

}



void arguments(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::string aux = argv[i];
        if (aux == "-f") {
            string filename = argv[i+1];
            cout << filename << endl;
        } else if (aux == "-n") {
            int neighbours = atoi(argv[i+1]);
            cout << neighbours << endl;
        } 
    }

    
}


int main(int argc, char** argv){
    arguments(argc, argv);
}