#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> tests_sizes = {10,50,100, 150, 300, 1000, 5000, 10000,20000,50000};
    vector<vector<int>> test_cases;
    
    for(int i =0; i < tests_sizes.size(); i++){
        vector<int> temp = {};
        for(int j = 0; j < tests_sizes[i]; j++){
            temp.push_back(rand()%100);
        }
        test_cases.push_back(temp);
    }

    for(int i =0; i < tests_sizes.size(); i++){
        ofstream output;
        output.open("./performance_test/test-" + to_string(test_cases[i].size()) + ".txt");
        if( !output ) { // file couldn't be opened
            cerr << "Error: file could not be opened" << endl;
            exit(1);
        }

        for(int j=0; j < test_cases[i].size(); j++){
            output << test_cases[i][j] << endl;
        }
    }

    return 0;
}