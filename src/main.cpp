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

  std::string maze_obj = "./objects/maze/maze.obj";
  std::string maze_texture = "./objects/maze/maze-wall.jpg";

  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<TextureGL*> _allTextures;

  MakeTriangle _maze(maze_obj, maze_texture);

  _allObjects.push_back(_maze.getTriangles());

  _allTextures.push_back(_maze.getTexture());

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects, _allTextures);

  return 0;
}