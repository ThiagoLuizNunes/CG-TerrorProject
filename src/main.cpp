/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "FileManager.cpp"
#include "GlutManager.h"
#include "ObjectGL.h"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"

#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  std::string mypath = "./objects/teste.txt";
  // std::string mypath = "./objects/farmhouse_obj.obj";
  std::string line;
  
  ObjectGL *_myObject = new ObjectGL;
  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<float> _tokens;
  std::vector<int> _tokens_face;

  glm::vec3 _vertex;
  glm::vec3 _normal;
  glm::vec2 _texture;

  FileManager* file_manager = nullptr;
 
    try {
        file_manager = new FileManager(mypath); 
    } catch (FileManagerException& exc) {
        std::cerr << "FileManagerException - what(): " << exc.what() << std::endl;
    }
 
    /**
     *
     * OPEN .OBGJ FILE SECTION
     *
     */

    if (file_manager != nullptr) {
      
      do {

        line = file_manager->getNextLine();

        if (line.compare(0, 2, "v ") == 0) {  // Catch vertex
          
          _tokens = file_manager->splitLine(line, ' ');
          _vertex.x = _tokens.at(0);
          _vertex.y = _tokens.at(1);
          _vertex.z = _tokens.at(2);
          _myObject->putVertices(_vertex);
          _tokens.clear();

        }

        else if (line.compare(0,2,"vn") == 0) {  // Catch normal vectors
          
          _tokens = file_manager->splitLine(line, ' ');
          _normal.x = _tokens.at(0);
          _normal.y = _tokens.at(1);
          _normal.z = _tokens.at(2);
          _myObject->putNormals(_normal);
          _tokens.clear();

        }

        else if (line.compare(0, 2, "vt") == 0) { // Catch textures

          _tokens = file_manager->splitLine(line, ' ');
          _texture.x = _tokens.at(0);
          _texture.y = _tokens.at(1);
          _myObject->putTextures(_texture);
          _tokens.clear();

        }
        else if (line.compare(0, 2, "f ") == 0) { // Catch faces(triangle)
          
          _tokens_face = file_manager->splitLineInteger(line, ' ');
          _myObject->putFaces(_tokens_face);
          _tokens_face.clear(); 
          
        }

      } while (!line.empty());
 
        delete file_manager;
    }
    
    /**
     *
     * VERTICES IN TRIANGLE SECTION
     *
     */
    
    int count = _myObject->getSizeFaces();

    std::vector<glm::vec3> vertices_ = _myObject->getVertices(); 
    std::vector<glm::vec3> normals_ = _myObject->getNormals(); 
    std::vector<glm::vec2> textures_ = _myObject->getTextures();
    std::vector< std::vector<int> > faces_ = _myObject->getFaces();

    std::vector<TriangleGL> _triangles;

    for (int i = 0; i < count; i++) {

      std::vector<int> face = faces_.at(i);

      VertexGL v_first(vertices_.at(face.at(0) - 1), normals_.at(face.at(2) - 1), textures_.at(face.at(1) - 1));
      VertexGL v_second(vertices_.at(face.at(3) - 1), normals_.at(face.at(5) - 1), textures_.at(face.at(4) - 1));
      VertexGL v_third(vertices_.at(face.at(6) - 1), normals_.at(face.at(8) - 1), textures_.at(face.at(7) - 1));

      TriangleGL _triangle(&v_first, &v_second, &v_third);
      _triangles.push_back(_triangle);

      face.clear();
      
    }
    _allObjects.push_back(_triangles);
    // std::clog << "Triangle faces: " << _triangles.size() << std::endl;
    
    /**
     *
     * GLUT SECTION
     *
     */
    
    std::string name = "TerrorOnTheHouse";
    GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects);

  return 0;
}

  /*----------  Test block  ----------*/

  // std::vector<glm::vec3> _testeV , _testeVn;
  // std::vector<glm::vec2> _testeVt;
  // std::vector< std::vector<int> > _testeFaces;

  /*----------  Test block  ----------*/
/* Test block */
      // int _v = 0;
      // int _vn = 0;
      // int _vt = 0;
      // int _f = 0;
/* Test block - catch vertex */
          // _testeV = _myObject->getVertices();
          // glm::vec3 temp = _testeV.at(_v);
          // std::clog << temp.x << " " << temp.y << " " << temp.z << std::endl;
          // _v++;
/* Test block - catch normal vectors */
          // _testeVn = _myObject->getNormals();
          // glm::vec3 temp = _testeVn.at(_vn);
          // std::clog << temp.x << " " << temp.y << " " << temp.z << std::endl;
          // _vn++;
/* Test block - catch textures */
          // _testeVt = _myObject->getTextures();
          // glm::vec2 temp = _testeVt.at(_vt);
          // std::clog << temp.x << " " << temp.y << std::endl;
          // _vt++;
/* Test block - catch faces(triangle */
          // _testeFaces = _myObject->getFaces();
          // for (int i = 0; i < _testeFaces.at(_f).size(); i++)
          // {
          //   std::clog << _testeFaces.at(_f).at(i) << " ";
          // }
          // std::clog << std::endl;
          // _f++;
      /*----------  Test block vertices in triangles  ----------*/
      // VertexGL *v_first = nullptr;
      // VertexGL *v_second = nullptr;
      // VertexGL *v_third = nullptr;
      // TriangleGL *triangle = nullptr;

      // v_first = new VertexGL(vertices_.at(face.at(0) - 1), normals_.at(face.at(2) - 1), textures_.at(face.at(1) - 1));
      // v_second = new VertexGL(vertices_.at(face.at(3) - 1), normals_.at(face.at(5) - 1), textures_.at(face.at(4) - 1));
      // v_third = new VertexGL(vertices_.at(face.at(6) - 1), normals_.at(face.at(8) - 1), textures_.at(face.at(7) - 1));
      
      // delete v_first;
      // delete v_second;
      // delete v_third;