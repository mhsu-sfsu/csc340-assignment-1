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

pair<int, int> sumIndices(vector<int>numberList, int sum){
    pair<int, int> indices = {-1, -1};
    int expected;
    int vectorsize = numberList.size();
    if (vectorsize < 2){
        indices.first = -1;
        indices.second = -1;
        return indices;
    }
    for (int i = 0; i < vectorsize; i++){
        expected = sum - numberList[i];
        for (int j = (i+1); j < vectorsize; j++){
            if (numberList[j] == expected){
                indices.first = i;
                indices.second = j;
                return indices;
            }
        }
    }
    indices.first = -1;
    indices.second = -1;
    return indices;
}