#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

vector<int> removeDuplicates(vector<int>);
vector<int> sumIndicies(vector<int>, int);

// The function removeDuplicates takes a vector of numbers and returns a new vector which removes any duplicate numbers and any invalid input (negative numbers).
vector<int> removeDuplicates(vector<int> numberList){
    int vectorsize = numberList.size();
    if (vectorsize < 2) return numberList;
    vector<int> copyList;
    bool found;

    for (int i = 0; i < vectorsize; i++){ // Iterates through the vector
        found = false;
        if (numberList[i] > -1){ // Function checks and ignores invalid input before checking it against the list of numbers that is being returned
            for (int j = 0; j < copyList.size(); j++){ 
                if (numberList[i] == copyList[j]) {
                    found = true;
                    continue; // Function moves onto the next iteration of the loop if a match is found
                }
            }
            // If function goes through the array without any matches, it adds the number to the vector of returned values.
            if (!found) copyList.push_back(numberList[i]);
        }
    }
    return copyList;
}

// This function takes a vector of integers and a sum, returning a pair of integers afterward. It sequentially goes through the numbers in the list and returns the indices of two values which add up into the sum. If no match is found, it returns -1, -1.
pair<int, int> sumIndices(vector<int>numberList, int sum){
    pair<int, int> indices = {-1, -1};
    int vectorsize = numberList.size();

    // Addresses any edge cases including the validity of the sum as well as the size of the vector
    if (sum < 1) return indices;
    if (vectorsize < 2) return indices;

    int expected;
    for (int i = 0; i < vectorsize; i++){
        expected = sum - numberList[i];
        for (int j = (i+1); j < vectorsize; j++){ // This loop sets j to one after i so that there is no unnecessary checking of values
            if (numberList[j] == expected){
                indices.first = i;
                indices.second = j;
                return indices;
            }
        }
    }
    return indices;
}