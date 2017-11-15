/*
Author: Thiago Luiz Nunes
Project: TerrorOnTheHouse
*/
#include "GlutManager.h"
#include "TriangleGL.hpp"
#include "MakeTriangle.hpp"
#include "SOIL.h" 

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  // std::string mypath = "./objects/Crate/Crate1.obj";
  std::string mypath = "./objects/teste.txt";
  std::vector< std::vector<TriangleGL> > _allObjects;

  MakeTriangle _cube(mypath);
  _allObjects.push_back(_cube.getTriangles());

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects);

  return 0;
}