#pragma once

#include <iostream>
#include <map>

class TextureUtil {
  private:
    static std::map<std::string, unsigned int> texMap;

    explicit TextureUtil() = default;

  public:
    virtual ~TextureUtil() = default;

    static bool Init();
    static unsigned int AddTexture(std::string texName, std::string imagePath);
    static unsigned int GetTexture(std::string texName);
};
