#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> merge(vector<int> vect1, vector<int> vect2){
    vector<int> output;
    int i = 0, j = 0;
    int vect1_size = vect1.size();
    int vect2_size = vect2.size();

    while(i < vect1_size and j < vect2_size){
        if(vect1[i] < vect2[j]){
            output.push_back(vect1[i]);
            i++;
        }else{
            output.push_back(vect2[j]);
            j++;
        }
    }

    while(i < vect1_size){
        output.push_back(vect1[i]);
        i++;
    }

    while(j < vect2_size){
        output.push_back(vect2[j]);
        j++;
    }

    return output;
}

vector<int> mergeSort(vector<int> vect){
    if(vect.size() == 1)
        return vect;
    
    int middle = vect.size() / 2;

    vector<int> left_side = vector<int>(vect.begin(), vect.begin() + middle);
    vector<int> right_side = vector<int>(vect.begin()+ middle, vect.end());

    vector<int> vect1 = mergeSort(left_side);
    vector<int> vect2 = mergeSort(right_side);
    
    return merge(vect1, vect2);
}

vector<int> createVector(int n){
    vector<int> new_vect;
    if(n > 0){
        int num;
        for(int i=0; i < n; i++){
            cin >> num;
            new_vect.push_back(num);
        }
    }
    return new_vect;
}

void printVector(vector<int> vect){
    int vector_size = vect.size();
    for(int i = 0; i < vector_size; i++){
        if(i != vector_size - 1)
            cout<<vect[i]<<",";
        else
            cout<<vect[i]<<endl;
    }
    return;
}

int main(){
    int vector_length;
    cin >> vector_length;

    if(vector_length < 0){
        cout << "Vector length error." << endl;
        cout << "Cannot create vector of length < 0." << endl;
        return 0;
    } else if(vector_length == 0){
        cout << "Empty vector" << endl;
        return 0;
    }

    vector<int> vect = createVector(vector_length); 
    vector<int> result = mergeSort(vect);
    
    cout<<"Vector Original: "<<endl;
    printVector(vect);
    
    cout<<"Vector Ordenado: "<<endl;
    printVector(result);
    
    return 0;
}