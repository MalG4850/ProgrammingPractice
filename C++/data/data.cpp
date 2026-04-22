#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string filename;
    int targetLength;
    int count = 0;
    std::string word;
     std::cout<<"enter the file name: ";
     std::cin>>filename;
     std::cout<<"target length (n): ";
     std::cin>>targetLength;

     std::ifstream file(filename);

     while(file>>word){
         if(word.length() == targetLength){
             count++;
         }
     }
     std::cout << "-----------------------------------\n\n";
    std::cout << "Found " << count << " words with exactly " << targetLength << " characters.\n\n";

    file.close();
    return 0;
}
