// #include "../include/Texture2D.h"
// #include <iostream>
// #include <cassert>
// #define STB_IMAGE_IMPLEMENTATION
// // #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "../include/stb_image.h"
// // #include "../include/stb_image_write.h"

// //-----------------------------------------------------------------------------
// // Constructor
// //-----------------------------------------------------------------------------
// Texture2D::Texture2D()
// 	: mTexture(0)
// {
// }

// //-----------------------------------------------------------------------------
// // Destructor
// //-----------------------------------------------------------------------------
// Texture2D::~Texture2D()
// {
// 	glDeleteTextures(1, &mTexture);
// }

// //-----------------------------------------------------------------------------
// // Load a texture with a given filename using stb image loader
// // http://nothings.org/stb_image.h
// // Creates mip maps if generateMipMaps is true.
// //-----------------------------------------------------------------------------
// bool Texture2D::loadTexture(const string &fileName, bool generateMipMaps)
// {
// 	int width, height, components;

// 	// Use stbi image library to load our image
// 	unsigned char *imageData = stbi_load(fileName.c_str(), &width, &height, &components, STBI_rgb_alpha);

// 	if (imageData == NULL)
// 	{
// 		std::cerr << "Error loading texture '" << fileName << "'" << std::endl;
// 		return false;
// 	}

// 	// Invert image
// 	int widthInBytes = width * 4;
// 	unsigned char *top = NULL;
// 	unsigned char *bottom = NULL;
// 	unsigned char temp = 0;
// 	int halfHeight = height / 2;
// 	for (int row = 0; row < halfHeight; row++)
// 	{
// 		top = imageData + row * widthInBytes;
// 		bottom = imageData + (height - row - 1) * widthInBytes;
// 		for (int col = 0; col < widthInBytes; col++)
// 		{
// 			temp = *top;
// 			*top = *bottom;
// 			*bottom = temp;
// 			top++;
// 			bottom++;
// 		}
// 	}

// 	glGenTextures(1, &mTexture);
// 	glBindTexture(GL_TEXTURE_2D, mTexture); // all upcoming GL_TEXTURE_2D operations will affect our texture object (mTexture)

// 	// Set the texture wrapping/filtering options (on the currently bound texture object)
// 	// GL_CLAMP_TO_EDGE
// 	// GL_REPEAT
// 	// GL_MIRRORED_REPEAT
// 	// GL_CLAMP_TO_BORDER
// 	// GL_LINEAR
// 	// GL_NEAREST
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

// 	if (generateMipMaps)
// 		glGenerateMipmap(GL_TEXTURE_2D);

// 	stbi_image_free(imageData);
// 	glBindTexture(GL_TEXTURE_2D, 0); // unbind texture when done so we don't accidentally mess up our mTexture

// 	return true;
// }

// //-----------------------------------------------------------------------------
// // Bind the texture unit passed in as the active texture in the shader
// //-----------------------------------------------------------------------------
// void Texture2D::bind(GLuint texUnit)
// {
// 	assert(texUnit >= 0 && texUnit < 32);

// 	glActiveTexture(GL_TEXTURE0 + texUnit);
// 	glBindTexture(GL_TEXTURE_2D, mTexture);
// }

// //-----------------------------------------------------------------------------
// // Unbind the texture unit passed in as the active texture in the shader
// //-----------------------------------------------------------------------------
// void Texture2D::unbind(GLuint texUnit)
// {
// 	glActiveTexture(GL_TEXTURE0 + texUnit);
// 	glBindTexture(GL_TEXTURE_2D, 0);
// }

// // void Texture2D::saveImage(int width, int height, char *filepath)
// // {
// // 	// Allocate memory for the pixel data
// // 	GLubyte *pixels = new GLubyte[width * height * 4];

// // 	// Read the pixel data from the framebuffer
// // 	glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

// // 	// Flip the pixel data vertically
// // 	for (int y = 0; y < height / 2; ++y)
// // 	{
// // 		for (int x = 0; x < width; ++x)
// // 		{
// // 			int top = y * width * 4;
// // 			int bottom = (height - y - 1) * width * 4;
// // 			GLubyte temp = pixels[top + x];
// // 			pixels[top + x] = pixels[bottom + x];
// // 			pixels[bottom + x] = temp;
// // 		}
// // 	}

// // 	// Write the pixel data to an image file
// // 	stbi_write_png(filepath, width, height, 4, pixels, width * 4);

// // 	// Free the memory used for the pixel data
// // 	delete[] pixels;
// // }