#include <iostream> 
#include "funcs.h"
#include <fstream>
#include <cstdlib>
#include <climits>
int main()
{
	int numberOfCerly = 0;
	std::string line;
	std::ifstream gin("poorFormat.txt");
	std::cout << "This is the bad format: \n";
	while(getline(gin, line)){
		std::cout << line << '\n';
	}
	std::cout << "--------------------------------\n";
	gin.close();
	std::ifstream fin("poorFormat.txt");
	if(fin.fail()){
		std::cerr << "Fail to open";
		exit(1);
	}
	std::cout << "This is the good format: \n";
	while(getline(fin, line)){
		line = removeLeadingSpaces(line);
		std::string tab = "";
		if(foundOpenCerly(line)){
			numberOfCerly++;
		}
		if(foundCloseCerly(line)){
			numberOfCerly--;
		}
		if(numberOfCerly == -1){
			numberOfCerly = 0;
		}
		if(numberOfCerly > 0){
			for(int i = 0; i < numberOfCerly; i++){
				//line = "\t" + line + '\n'; 
				tab += "\t";
			}
			std::cout << tab + line << '\n';
			tab = "";
		}
		else{
			std::cout << line << "\n";
		}
	}
	fin.close();
	//std::string edit = removeLeadingSpaces("");
	//int index = foundOpenCerly("if(number == 2)");
	//std::cout << index  << '\n';
	return 0;
}
