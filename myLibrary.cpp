#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

vector<int> removeDuplicates(vector<int>);
pair<int, int> sumIndices(vector<int>, int);

//removeDuplicates takes in a vector of numbers called numberList and returns a new vector containing positive nonduplicate numbers
vector<int> removeDuplicates(vector<int> numberList){

    int vectorsize = numberList.size();
    if (vectorsize < 2) return numberList;
    vector<int> copyList;
    bool found;

    for (int i = 0; i < vectorsize; i++){ // Iterate through input
        found = false;
        if (numberList[i] > -1){ // Disregards any negative input 
            for (int j = 0; j < copyList.size(); j++){ 
                if (numberList[i] == copyList[j]) { // If the value is found, change boolean and continue
                    found = true;
                    continue;
                }
            }
            if (!found){ //After going through the values in the vector being returned, if there is no match, adds it to the vector
                copyList.push_back(numberList[i]);
            }
        }
    }
    return copyList;
}

//sumIndices is a function which takes a vector of nonrepeating numbers and an integer sum. It returns a pair containing the two indices of the vector which have values adding up to the sum. Otherwise, returns a pair containing the numbers -1, -1.
pair<int, int> sumIndices(vector<int>numberList, int sum){
    pair<int, int> indices = {-1, -1};

    // If the sum or vector size are invalid, immediately returns default values
    if (sum < 1) return indices;
    int vectorsize = numberList.size();
    if (vectorsize < 2){
        return indices;
    }

    int expected; // This number is the number being searched for in the following loop
    for (int i = 0; i < vectorsize; i++){
        expected = sum - numberList[i];
        for (int j = (i+1); j < vectorsize; j++){ //Loops through remaining vector to search for matches, hence j being set to (i + 1).
            if (numberList[j] == expected){
                indices.first = i;
                indices.second = j;
                return indices;
            }
        }
    }
    return indices;
}