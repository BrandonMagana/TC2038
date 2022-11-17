/*
  Autores:
   - Brandon Josué Magaña Mendoza - A01640162
   - Santiago González de Cosío Romero - A01640329

  El presente programa implementa el algoritmo Randomized Binary Search para
  encontrar el índice de un     número dentro de un arreglo de números enteros.

  Time Complexity: O(log n)
  
  Instrucciones:
  - g++ main.cpp -o main
  - ./main < test.txt
*/
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getRandom(int x, int y) {
  srand(time(NULL));
  return (x + rand() % (y - x + 1));
}

int rBS(int target, vector<int> nums, int left, int right) {
  if (left > right)
    return -1;

  int x = getRandom(left, right);

  if (nums[x] == target) {
    return x;
  }

  if (nums[x] > target) {
    return rBS(target, nums, left, x - 1);
  }

  return rBS(target, nums, x + 1, right);
}

vector<int> createNumsVector(string numsString) {
  stringstream ss(numsString);
  vector<int> nums;

  for (int i; ss >> i;) {
    nums.push_back(i);
    if (ss.peek() == ',')
      ss.ignore();
  }
  return nums;
}

int main() {
  int target;
  cin >> target;
  string numsS;
  getline(cin >> std::ws, numsS);

  vector<int> nums = createNumsVector(numsS);

  int result = rBS(target, nums, 0, nums.size() - 1);

  if (result >= 0) {
    cout << "El elemento esta presente en el indice: " << result << endl;
  } else {
    cout << "El elemento no esta presente en el arreglo" << endl;
  }
  
  return 0;
}
