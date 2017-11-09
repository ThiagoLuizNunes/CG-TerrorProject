/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "FileManager.cpp"
#include "GlutManager.h"
#include <iostream>
#include <string>

const static std::string path;


int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  std::string mypath = "./objects/teste.txt";

  FileManager* file_manager = nullptr;
 
    try {
        file_manager = new FileManager(mypath); 
    } catch (FileManagerException& exc) {
        std::cerr << "FileManagerException - what(): " << exc.what() << std::endl;
    }
 
    if (file_manager != nullptr) {

      std::clog << std::endl;
      std::string line;
      
      do {

        line = file_manager->getNextLine();

        if (line.compare(0, 2, "v ") == 0) {// Catch vertex
          std::clog << "Vertex: " << line << std::endl;
        }

        else if (line.compare(0,2,"vn") == 0) {  // Catch normal vectors
          std::clog << "Normal vector : " << line << std::endl;
        }

        else if (line.compare(0, 2, "vt") == 0) { // Catch texture
          std::clog << "Texture : " << line << std::endl;
        }

      } while (!line.empty());
 
        delete file_manager;
    }
    
    std::string name = "TerrorOnTheHouse";
    GlutManager myGlut(&argc, argv, 1024, 720, name);

  return 0;
}
