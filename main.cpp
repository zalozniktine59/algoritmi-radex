#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print2DArray(int rows, int cols, int (*binaryArray)[8]) {
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            std::cout<<binaryArray[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

void numToBinary(int number, std::vector<int>& binaryNumberVector){
    binaryNumberVector.clear();
    for (int i=0; i<8; i++) {
        binaryNumberVector.push_back(number & 1);
        number >>= 1;
    }
}
int binaryToDecimal(int binary[], int length) {
    int decimal = 0;
    for (int i=length-1; i>=0; i--) {
        decimal= (decimal << 1) | binary[i];
    }
    return decimal;
}

void fillBinaryVector(const std::vector<unsigned char>myVector, int (*binaryArray)[8], std::vector<int>& binaryNumberVector){
    for(int j=0;j<myVector.size();j++){
        numToBinary(myVector[j], binaryNumberVector);
        for(int i=0;i<8;i++){
            binaryArray[j][i] = binaryNumberVector[i];
        }
    }
    //print2DArray(myVector.size(),8,binaryArray);
}

std::vector<int> radixSort(std::vector<unsigned char>myVector, int (*binaryArray)[8]){

}

int main() {
    std::vector<unsigned char> myVector;
    myVector = {4,5,1,3,9};
    int size=5;
    int binaryArray[size][8];
    std::vector<int> binaryNumberVector(8,0);
    fillBinaryVector(myVector,binaryArray,binaryNumberVector);

    /*
    std::vector<int> binary;
    numToBinary(10, binary);
    for (int i=binary.size()-1; i>=0; i--) {
        std::cout << binary[i];
    }
    cout<<endl;

    int decimal = binaryToDecimal(&binary[0], binary.size());
    cout<<"Decimalno stevilo: "<<decimal<<endl;
     */
    return 0;
}
