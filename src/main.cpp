/*
Author: Thiago Luiz Nunes
Project: TerrorOnTheHouse
*/
#include "GlutManager.h"
#include "TriangleGL.hpp"
#include "MakeTriangle.hpp"
#include "TextureGL.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  // std::string mypath = "./objects/Crate/Crate1.obj";
  std::string mypath = "./objects/teste.txt";
  std::string texture = "./objects/Crate/crate_1.jpg";
  std::string scene_obj = "./objects/ICG_scene_001/ICG_scene_001.obj";

  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<TextureGL*> _allTextures;

  MakeTriangle _cube(scene_obj, texture);

  _allObjects.push_back(_cube.getTriangles());
  _allTextures.push_back(_cube.getTexture());

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects, _allTextures);

  return 0;
}