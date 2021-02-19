//
//  shader.hpp
//  openGLPractice
//
//  Created by luao on 2021/2/19.
//

#ifndef shader_hpp
#define shader_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    // tools to set uniform value
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type) const;
};

#endif /* shader_hpp */
