/*
Author: Thiago Luiz Nunes
Project: TerrorOnTheHouse
*/
#include "GlutManager.hpp"
#include "TriangleGL.hpp"
#include "MakeTriangle.hpp"
#include "TextureGL.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  // std::string mypath = "./objects/Crate/Crate1.obj";
  std::string cube_obj = "./objects/teste.txt";
  std::string scene_texture = "./objects/ICG_scene_001/parede.jpg";
  std::string scene_obj = "./objects/ICG_scene_001/ICG_scene_001.obj";

  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<TextureGL*> _allTextures;

  // MakeTriangle _cube(cube_obj, texture);
  MakeTriangle _scene(scene_obj, scene_texture);

  _allObjects.push_back(_scene.getTriangles());
  _allTextures.push_back(_scene.getTexture());

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects, _allTextures);

  return 0;
}