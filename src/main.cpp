/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "FileManager.cpp"
#include "GlutManager.h"
#include "ObjectGL.h"

#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

extern ObjectGL *_myObject = new ObjectGL;

int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  std::string mypath = "./objects/teste.txt";
  std::string line;
  
  std::vector<float> tokens;
  glm::vec3 _vertex;
  glm::vec3 _normal;
  glm::vec2 _texture;

  /*----------  Test block  ----------*/

  // std::vector<glm::vec3> _testeV , _testeVn;
  // std::vector<glm::vec2> _testeVt;

  /*----------  Test block  ----------*/


  FileManager* file_manager = nullptr;
 
    try {
        file_manager = new FileManager(mypath); 
    } catch (FileManagerException& exc) {
        std::cerr << "FileManagerException - what(): " << exc.what() << std::endl;
    }
 
    if (file_manager != nullptr) {
      
      /* Test block */
      // int _v = 0;
      // int _vn = 0;
      // int _vt = 0;

      do {

        line = file_manager->getNextLine();

        if (line.compare(0, 2, "v ") == 0) {  // Catch vertex
          tokens = file_manager->splitLine(line);

          _vertex.x = tokens.at(0);
          _vertex.y = tokens.at(1);
          _vertex.z = tokens.at(2);
          _myObject->putVertices(_vertex);

          /* Test block */
          // _testeV = _myObject->getVertices();
          // glm::vec3 temp = _testeV.at(_v);
          // std::clog << temp.x << " " << temp.y << " " << temp.z << std::endl;
          // _v++;

          tokens.clear();
        }

        else if (line.compare(0,2,"vn") == 0) {  // Catch normal vectors
          tokens = file_manager->splitLine(line);
          
          _normal.x = tokens.at(0);
          _normal.y = tokens.at(1);
          _normal.z = tokens.at(2);
          _myObject->putNormals(_normal);

          /* Test block */
          // _testeVn = _myObject->getNormals();
          // glm::vec3 temp = _testeVn.at(_vn);
          // std::clog << temp.x << " " << temp.y << " " << temp.z << std::endl;
          // _vn++;

          tokens.clear();
        }

        else if (line.compare(0, 2, "vt") == 0) { // Catch texture
          tokens = file_manager->splitLine(line);

          _texture.x = tokens.at(0);
          _texture.y = tokens.at(1);
          _myObject->putTextures(_texture);

          /* Test block */
          // _testeVt = _myObject->getTextures();
          // glm::vec2 temp = _testeVt.at(_vt);
          // std::clog << temp.x << " " << temp.y << std::endl;
          // _vt++;

          tokens.clear();
        }

      } while (!line.empty());
 
        delete file_manager;
    }
    
    std::string name = "TerrorOnTheHouse";
    GlutManager myGlut(&argc, argv, 1024, 720, name);

  return 0;
}
