#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int>);
vector<int> sumIndicies(vector<int>, int);

vector<int> removeDuplicates(vector<int> numberList){
    int vectorsize = numberList.size();
    if (vectorsize < 2) return numberList;
    vector<int> copyList;
    bool found = false;

    for (int i = 0; i < vectorsize; i++){ // iterate through input
        for (int j = 0; j < copyList.size(); j++){ // iterate through copy of input
            if (numberList[i] == copyList[j]) {
                found = true;
                continue;
            }
        }
        if (!found){
            copyList.push_back(numberList[i]);
        }
        found = false;
    }

    return copyList;
}

vector<int> sumIndicies(vector<int>numberList, int sum){
    vector<int> indices;
    int expected;
    int vectorsize = numberList.size();
    if (vectorsize < 2){
        indices.push_back(-1);
        indices.push_back(-1);
        return indices;
    }
    for (int i = 0; i < vectorsize; i++){
        expected = sum - numberList[i];
        for (int j = (i+1); j < vectorsize; j++){
            if (numberList[j] == expected){
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }
    indices.push_back(-1);
    indices.push_back(-1);
    return indices;
}