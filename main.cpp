#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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

int main() {
    std::vector<int> binary;
    numToBinary(10, binary);
    for (int i=binary.size()-1; i>=0; i--) {
        std::cout << binary[i];
    }
    cout<<endl;

    int decimal = binaryToDecimal(&binary[0], binary.size());
    cout<<"Decimalno stevilo: "<<decimal<<endl;
    return 0;
}
