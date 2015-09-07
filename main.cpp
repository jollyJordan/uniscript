#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>


int main(int argc, char *argv[]){
	if(argc<=1)
		return 0;
	
	std::string buffer;
	std::map<std::string,int> dic;
	std::fstream fin;
	fin.open( argv[1] );
	std::pair<std::map<std::string,int>::iterator,bool> ret;

	while(fin>>buffer)
	{
		ret = dic.insert(std::pair<std::string,int>(buffer,1));
		
		// If word is already in dictionary
		if(!ret.second)
			dic[buffer]++;
	}
	
	std::map<std::string,int>::iterator it = dic.begin();
	std::cout << "mapped input:\n";
	
	for (it=dic.begin(); it!=dic.end(); ++it)
		std::cout<< it->second << "\t" << it->first <<"\n";
	 
	return 1;
}