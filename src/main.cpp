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

  std::string wall_obj = "./objects/wall/wall.obj";
  std::string wall_texture = "./objects/wall/wall.jpg";

  std::string floor_obj = "./objects/floor/floor.obj";
  std::string floor_texture = "./objects/floor/floor.jpg";

  std::string ceiling_obj = "./objects/ceiling/ceiling.obj";
  std::string ceiling_texture = "./objects/ceiling/ceiling.jpg";


  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<TextureGL*> _allTextures;

  MakeTriangle _wall(wall_obj, wall_texture);
  MakeTriangle _floor(floor_obj, floor_texture);
  MakeTriangle _ceiling(ceiling_obj, ceiling_texture);

  _allObjects.push_back(_wall.getTriangles());
  _allObjects.push_back(_floor.getTriangles());
  _allObjects.push_back(_ceiling.getTriangles());

  _allTextures.push_back(_wall.getTexture());
  _allTextures.push_back(_floor.getTexture());
  _allTextures.push_back(_ceiling.getTexture());

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects, _allTextures);

  return 0;
}