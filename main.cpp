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

int main() {
    std::vector<int> binary;
    numToBinary(10, binary);
    for (int i=binary.size()-1; i>=0; i--) {
        std::cout << binary[i];
    }
    cout<<endl;
    return 0;
}
