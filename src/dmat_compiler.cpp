/*
 * DMAT Official Compiling File
 * Written by ghgltggamer
 *
 * This library is licensed under the terms found in the LICENSE file.
 */
 

// DMAT Lang - version 1.0.1

#include "dmat.h"
#include <fstream>

std::string albedoF;
std::string normalF;
std::string heightF;
std::string roughnessF;
std::string metalicF;
float intensity;

int main(int argc, char* argv[]){
	
	std::string dmat_file_name = argv[1];
	
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
				
				
				// Intensity addition
				else if (txt.find("INORMAL:")!=-1){
					std::string name = "INORMAL:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Light Intensity Normal map...\n";
					Inormal = std::stoi(get);
				}
				
				else if (txt.find("IHEIGHT:")!=-1){
					std::string name = "IHEIGHT:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Light Intensity Normal map...\n";
					Iheight = std::stoi(get);
				}
				
				else if (txt.find("IROUGHNESS:")!=-1){
					std::string name = "IROUGHNESS:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Light Intensity roughness map...\n";
					Iroughness = std::stoi(get);
				}
				
				else if (txt.find("IMETALIC:")!=-1){
					std::string name = "IMETALIC:";
					std::string get = txt.substr(txt.find(name)+name.length());
					std::cout<<"Compiling "<<get<<"...\n";
					std::cout<<"Initalising Light Intensity metalic map...\n";
					Imetallic = std::stoi(get);
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
}