#include <iostream> 

std::string removeLeadingSpaces(std::string line){
	std::string newLine = "";
	for(int i = 0; i < line.length(); i++){
		if(!isspace(line[i])){
			newLine = line.substr(i,(line.length() - i));
			break;
		}
	}
	return newLine;
}
bool foundOpenCerly(std::string line){
	if(line.find('{') != -1){
		return true;
	}
	else{
		return false;
	}
}
bool foundCloseCerly(std::string line){
	if(line.find('}') != -1){
		return true;
	}
	else{
		return false;
	}
}
