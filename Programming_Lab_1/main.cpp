#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <chrono>

using namespace std;

bool fileExists(string path){
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << path << "'" << endl;
        return false;
    }
    return true;
}

vector<int> createSumVectorFromFile(string path){
    vector<int> output = {};
    ifstream input_file(path);
    int i = 0;
    int number;
    while (input_file >> number) {
        output.push_back(number);
        i++;
    }
    input_file.close();

    return output;
}

int sumVector(vector<int> vect){
    int sum = 0;
    for(const int & num : vect){
        sum += num;
    }    
    return sum;
}

double calcTimeElapsed(chrono::time_point<chrono::high_resolution_clock> begin, 
    chrono::time_point<chrono::high_resolution_clock> end){
    return chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
}

void logSumResult(vector<int> vect,  int sum, double elapsed_secs){
    int vect_size = vect.size();
    cout << "Time Elapsed for "<< vect_size << " numbers is: " 
        << elapsed_secs << setprecision(9)<<" nanosec" <<endl;
    cout << "Sum: " << sum <<endl;
}

int main(int argc, char *argv[]){
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    vector<vector<int>> sum_vectors;

    if(argc > 1){
        if(!fileExists(argv[1])) return EXIT_FAILURE;
        
        vector<int> vect = createSumVectorFromFile(argv[1]);
        sum_vectors.push_back(vect);
    
    }else{
        string path = "./performance_test";
        vector<string> paths;

        for (const auto & file : filesystem::directory_iterator(path)){
            paths.push_back(file.path());
        }

        for(int i= 0; i < paths.size(); i++){
            string fn = paths[i];
            vector<int> new_vector = createSumVectorFromFile(fn);
            sum_vectors.push_back(new_vector);
        }

        sort(sum_vectors.begin(), sum_vectors.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() < b.size(); });
    }

    for(const auto & vect : sum_vectors){
        auto begin = chrono::high_resolution_clock::now();
        int sum = sumVector(vect);
        auto end = chrono::high_resolution_clock::now();
        
        double elapsed_secs = calcTimeElapsed(begin, end);
        
        logSumResult(vect, sum, elapsed_secs);
    }
    
    return 0;
}