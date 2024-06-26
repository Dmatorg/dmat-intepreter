#include "dmat.h"
#include <fstream>

std::string albedoF;
std::string normalF;
std::string heightF;
std::string roughnessF;
std::string metalicF;

int main(){
	while (1){
		std::cout<<"Enter the dmat file path: ";
	std::string dmat_file_name;
	std::getline(std::cin, dmat_file_name);
	
	if (dmat_file_name.find(".dmat")!=-1){
		std::ifstream dmat(dmat_file_name);
		
		if (dmat.is_open()){
			std::string txt;
			while (std::getline(dmat, txt)){
				if (txt.find("DMAT_ALBEDO:")!=-1){
					std::string name = "DMAT_ALBEDO:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Dmat image as albedoF...\n";
					albedoF = get;
				}
				
				
				else if (txt.find("DMAT_NORMALS:")!=-1){
					std::string name = "DMAT_NORMALS:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising normal map as normalF...\n";
					normalF = get;
				}
				
				
				
				else if (txt.find("DMAT_HEIGHTS:")!=-1){
					std::string name = "DMAT_HEIGHTS:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising height map as heightF...\n";
					heightF = get;
				}
				
				
				
				else if (txt.find("DMAT_ROUGHNESSS:")!=-1){
					std::string name = "DMAT_ROUGHNESSS:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Roughness map as roughnessF...\n";
					roughnessF = get;
				}
				
				
				
				else if (txt.find("DMAT_METALICS:")!=-1){
					std::string name = "DMAT_METALICS:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Metalic map as metalicF...\n";
					metalicF = get;
				}
				
				
				else if (txt.find("EXIT&BUILD")!=-1){
					DMAT_FINAL_PROCESS(albedoF, normalF, heightF, roughnessF, metalicF);
					std::cout<<"\nCompilation done\n";
				}
				
				
			}
		}
		else{
			std::cout<<"\nError : Fatal - File doesnot exists\n";
		}
	}
	else{
		std::cout<<"\nError: Fatal - The file your write is not a DMAT file\n";
	}
	}// while
}