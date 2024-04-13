#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

void writeVectorToFile(const std::vector<int>& vec, const std::string& filename);
void print2DArray(int rows, int cols, int (*binaryArray)[8]);
void numToBinary(int number, std::vector<int>& binaryNumberVector);
int binaryToDecimal(int binary[], int length);
void fillBinaryVector(const std::vector<unsigned char> myVector, int (*binaryArray)[8], std::vector<int>& binaryNumberVector);
std::vector<int> radixSort(std::vector<unsigned char> myVector, int (*binaryArray)[8]);


int testRadixSort() {
    std::vector<unsigned char> myVector = {5, 10, 3, 7, 15, 1, 8, 12};
    int size = myVector.size();
    int binaryArray[size][8];
    std::vector<int> binaryNumberVector(8, 0);
    fillBinaryVector(myVector, binaryArray, binaryNumberVector);
    std::vector<int> sortedVector = radixSort(myVector, binaryArray);
    bool sortedCorrectly = std::is_sorted(sortedVector.begin(), sortedVector.end());
    if (sortedCorrectly) {
        std::cout << "The vector is sorted correctly." << std::endl;
        return 0;
    } else {
        std::cout << "The vector is NOT sorted correctly." << std::endl;
        return 1;
    }
}

#endif // MAIN_H