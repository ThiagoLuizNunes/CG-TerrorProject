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

  // std::string lamp_obj = "./objects/lamp/lampada.obj"; // SO MANY TRiANGLES
  // std::string lamp_texture = "./objects/lamp/lamp.jpg"; // SO MANY TRiANGLES

  std::string door_obj = "./objects/door/door.obj";
  std::string door_texture = "./objects/door/door.jpg";

  // std::string door_lock_obj = "./objects/door_lock/door_lock.obj";
  std::string door_lock_obj = "./objects/door_lock/fechadura.obj";
  std::string door_lock_texture = "./objects/door_lock/door_lock.jpg";

  std::string desk_obj = "./objects/desk/desk.obj";
  std::string desk_texture = "./objects/desk/desk.jpg";

  std::string painting01_obj = "./objects/painting01/painting01.obj";
  std::string painting01_texture = "./objects/painting01/painting01.jpg";

  std::string painting02_obj = "./objects/painting02/painting02.obj"; // JPEG NOT SUPPORTED
  std::string painting02_texture = "./objects/painting02/painting02.jpg"; // JPEG NOT SUPPORTED

  std::string painting03_obj = "./objects/painting03/painting03.obj";
  std::string painting03_texture = "./objects/painting03/painting03.jpg";

  std::vector< std::vector<TriangleGL> > _allObjects;
  std::vector<TextureGL*> _allTextures;

  MakeTriangle _wall(wall_obj, wall_texture);
  MakeTriangle _floor(floor_obj, floor_texture);
  MakeTriangle _ceiling(ceiling_obj, ceiling_texture);
  MakeTriangle _door(door_obj, door_texture);
  MakeTriangle _door_lock(door_lock_obj, door_lock_texture);
  MakeTriangle _desk(desk_obj, desk_texture);
  MakeTriangle _painting01(painting01_obj, painting01_texture);
  // MakeTriangle _painting02(painting02_obj, painting02_texture); // JPEG NOT SUPPORTED
  MakeTriangle _painting03(painting03_obj, painting03_texture);
  // MakeTriangle _lamp(lamp_obj, lamp_texture); // SO MANY TRiANGLES

  _allObjects.push_back(_wall.getTriangles());
  _allObjects.push_back(_floor.getTriangles());
  _allObjects.push_back(_ceiling.getTriangles());
  _allObjects.push_back(_door.getTriangles());
  _allObjects.push_back(_door_lock.getTriangles());
  _allObjects.push_back(_desk.getTriangles());
  _allObjects.push_back(_painting01.getTriangles());
  // _allObjects.push_back(_painting02.getTriangles()); // JPEG NOT SUPPORTED
  _allObjects.push_back(_painting03.getTriangles());
  // _allObjects.push_back(_lamp.getTriangles()); // SO MANY TRiANGLES

  _allTextures.push_back(_wall.getTexture());
  _allTextures.push_back(_floor.getTexture());
  _allTextures.push_back(_ceiling.getTexture());
  _allTextures.push_back(_door.getTexture());
  _allTextures.push_back(_door_lock.getTexture());
  _allTextures.push_back(_desk.getTexture());
  _allTextures.push_back(_painting01.getTexture());
  // _allTextures.push_back(_painting02.getTexture()); // JPEG NOT SUPPORTED
  _allTextures.push_back(_painting03.getTexture());
  // _allTextures.push_back(_lamp.getTexture()); // SO MANY TRiANGLES

  std::string name = "TerrorOnTheHouse";
  GlutManager myGlut(&argc, argv, 1024, 720, name, _allObjects, _allTextures);

  return 0;
}