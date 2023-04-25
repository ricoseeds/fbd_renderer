#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#define GLEW_STATIC
#include "GL/glew.h"
#include <string>
using std::string;
// #define STB_IMAGE_IMPLEMENTATION
// #include "../include/stb_image.h"

class Texture2D
{
public:
	Texture2D();
	virtual ~Texture2D();

	bool loadTexture(const string &fileName, bool generateMipMaps = true);
	void bind(GLuint texUnit = 0);
	void unbind(GLuint texUnit = 0);
	void saveImage(int width, int height, char *filepath);

private:
	Texture2D(const Texture2D &rhs)
	{
	}
	Texture2D &operator=(const Texture2D &rhs) {}

	GLuint mTexture;
};
#endif // TEXTURE2D_H
