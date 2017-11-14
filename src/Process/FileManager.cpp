#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <vector>

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
    std::vector<float> splitLine( std::string& line, char c) {
        std::string temp = line;
        std::size_t first_space = line.find_first_of(" ");

        /*----------  Erasing first space +1  ----------*/
        if (first_space != std::string::npos)
            temp.erase(0, first_space + 1);

        /*----------  Split line at vector<string>  ----------*/
        std::vector<float> tokens;
        std::istringstream ss(temp);
        std::string token;

        while (std::getline(ss, token, c)) {
            float f_token = strtof((token).c_str(), 0);
            tokens.push_back(f_token);
        }
        return tokens;
    }
    std::vector<int> splitLineInteger( std::string& line, char c) {
        std::string temp = line;
        std::size_t first_space = line.find_first_of(" ");

        /*----------  Erasing first space +1  ----------*/
        if (first_space != std::string::npos)
            temp.erase(0, first_space + 1);
        
        /*----------  Split line at a vector<string>  ----------*/
        std::vector<std::string> tokens;
        std::istringstream ss(temp);
        std::string token; 

        while (std::getline(ss, token, c)) {
            tokens.push_back(token);
        }
        /*----------  Convert vector<string> to vector<int>  ----------*/
        std::vector<int> _tokens;
        for (int i = 0; i < tokens.size(); i++) {

            std::string _temp = tokens.at(i);
            std::istringstream _ss(_temp);
            std::string _token; 

            while (std::getline(_ss, _token, '/')) {
                int result;
                std::stringstream(_token) >> result;
                _tokens.push_back(result);
            }
        }
        return _tokens;
    }
};