#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void writeVectorToFile(const std::vector<int>& vec, const std::string& filename) {
    std::ofstream outputFile(filename);

    if(outputFile.is_open()){
        for(int num:vec){
            outputFile<<num<<" ";
        }
        outputFile.close();
        std::cout<<"Zapisano v datoteko: "<<filename<<std::endl;
    } else {
        std::cerr<<"Napaka pri odpiranju: "<<filename<<std::endl;
    }
}

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
    int size = myVector.size();
    std::vector<std::pair<int, int>> vec;
    std::vector<int> decimalVector;

    int binaryArrayTemp[size][8];
    //kopiram v temp
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 8; ++j) {
            binaryArrayTemp[i][j] = binaryArray[i][j];
        }
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<size;j++){
            vec.push_back(std::make_pair(binaryArrayTemp[j][i],j));

        }
        std::stable_sort(vec.begin(), vec.end(),
                         [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                             return a.first < b.first;
                         });
        //print2DArray(size,8,binaryArray);
        //cout<<endl;
        for(int o=0;o<size;o++) {
            for (int p=0; p<8; p++) {
                binaryArrayTemp[o][p] = binaryArray[vec[o].second][p];
            }
        }
        for (int l=0; l<size; l++) {
            for (int j=0; j<8; j++) {
                binaryArray[l][j] = binaryArrayTemp[l][j];
            }
        }
        vec.clear();

        //cout<<"\n";
        //print2DArray(4,8,binaryArrayTemp);
    }
    for (int i = 0; i < size; i++) {
        //pretvorim v decimalno
        int decimal = binaryToDecimal(binaryArray[i], 8);
        //shranim v vektor
        decimalVector.push_back(decimal);
    }

    return decimalVector;
}

int main(int argc, char* argv[]) {

    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    int size=0;
    std::vector<int> numbers;
    int num;
    std::vector<unsigned char> myVector;

    while (input_file >> num) {
        myVector.push_back(num);
        size++;
    }

    std::vector<int> binaryNumberVector(8,0);
    int binaryArray[size][8];
    fillBinaryVector(myVector,binaryArray,binaryNumberVector);
    writeVectorToFile(radixSort(myVector,binaryArray),"out.txt");


    return 0;
}
