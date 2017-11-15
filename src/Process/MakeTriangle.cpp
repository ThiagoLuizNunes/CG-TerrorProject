#include "MakeTriangle.hpp"

MakeTriangle::MakeTriangle(std::string& mypath, std::string& texture_path) {
  
  ObjectGL *_myObject = new ObjectGL;
  std::string line;
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

        if (line.compare(0, 2, "v ") == 0) { // Catch vertex
          _tokens = file_manager->splitLine(line, ' ');
          _vertex.x = _tokens.at(0);
          _vertex.y = _tokens.at(1);
          _vertex.z = _tokens.at(2);
          _myObject->putVertices(_vertex);
          _tokens.clear();
        }
        else if (line.compare(0,2,"vn") == 0) { // Catch normal vectors
          _tokens = file_manager->splitLine(line, ' ');
          _normal.x = _tokens.at(0);
          _normal.y = _tokens.at(1);
          _normal.z = _tokens.at(2);
          _myObject->putNormals(_normal);
          _tokens.clear();
        }
        else if (line.compare(0, 2, "vt") == 0) {// Catch textures
          _tokens = file_manager->splitLine(line, ' ');
          _texture.x = _tokens.at(0);
          _texture.y = _tokens.at(1);
          _myObject->putTextures(_texture);
          _tokens.clear();
        }
        else if (line.compare(0, 2, "f ") == 0) {// Catch faces(triangle)
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

    for (int i = 0; i < count; i++) {

      std::vector<int> face = faces_.at(i);
      VertexGL v_first(vertices_.at(face.at(0) - 1), normals_.at(face.at(2) - 1), textures_.at(face.at(1) - 1));
      VertexGL v_second(vertices_.at(face.at(3) - 1), normals_.at(face.at(5) - 1), textures_.at(face.at(4) - 1));
      VertexGL v_third(vertices_.at(face.at(6) - 1), normals_.at(face.at(8) - 1), textures_.at(face.at(7) - 1));

      TriangleGL _triangle(&v_first, &v_second, &v_third);
      this->_triangles.push_back(_triangle);

      int width, height;
      unsigned char* image =
          SOIL_load_image(texture_path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

      // _texture = new TextureGL(width, height, image);
      face.clear();
    }
}
MakeTriangle::~MakeTriangle() {}

std::vector<TriangleGL> MakeTriangle::getTriangles(void) {
	return this->_triangles;
}
TextureGL* MakeTriangle::getTexture(void) {
  return this->_texture;
}
