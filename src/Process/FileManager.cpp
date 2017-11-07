#include <string>
#include <fstream>
#include <iostream>
#include <exception>
 
class FileManagerException:  public std::runtime_error{

public:
    FileManagerException() : runtime_error("File Manager Exception") {}
    FileManagerException(const std::string& msg) : runtime_error(msg.c_str()) {}
};
 
class FileManager {

private:
    std::fstream file_manager_;
    std::string   file_path_;
public:
    FileManager(const std::string& file_path) throw(FileManagerException) : file_path_(file_path) {
        this->file_manager_.open(this->file_path_, std::ios::in);
 
        if (!this->file_manager_.is_open()) {
            throw FileManagerException("Could not open file: " + this->file_path_);
        }
    }
 
    ~FileManager() {
        this->file_manager_.close();
    }
 
    std::string getNextLine() {
        std::string line;
        std::getline(this->file_manager_, line);
        return line;
    }
};