#include <iostream>
#include <GLFW/glfw3.h>
#include "load_frame.h"

int main(int argc, const char* argv[])
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        std::cout << "couldnt intialize" << std::endl;
        return 1;
    }

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "Couldn't open the window" << std::endl;
        return 1;
    }

    //create te a buffer for the pixels
    unsigned char* data = new unsigned char[100 * 100 * 3];
    for (int y = 0; y < 100; ++y)
    {
         for (int x = 0; x < 100; ++x)
        {
            data[y * 100 * 3 + x * 3    ] = 0xff;
            data[y * 100 * 3 + x * 3 + 1] = 0x00;
            data[y * 100 * 3 + x * 3 + 2] = 0x00;

        }
    }
    for (int y = 25; y < 75; ++y)
    {   
         for (int x = 25; x < 75; ++x)
        {
            data[y * 100 * 3 + x * 3    ] = 0x00;
            data[y * 100 * 3 + x * 3 + 1] = 0x00;
            data[y * 100 * 3 + x * 3 + 2] = 0xff;
        }
    }

    int frame_width, frame_height;
    unsigned char* frame_data;
    if(!load_frame("/Users/giancedrickepilan/Desktop/bbepisode4.mp4", &frame_width, &frame_height, &frame_data))
    {
        std::cout << "Couldn't load video frame" << std::endl;
        return 1;
    };

    glfwMakeContextCurrent(window);

    //Generating the textures
    GLuint tex_handle;
    glGenTextures(1, &tex_handle);
    glBindTexture(GL_TEXTURE_2D, tex_handle);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame_width, frame_height, 0, GL_RGB, GL_UNSIGNED_BYTE, frame_data);

    //run loop
    while(!glfwWindowShouldClose(window))
    {
        //inside here you can do ur renders
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //setup orthographic projection
        int window_width, window_height;
        glfwGetFramebufferSize(window, &window_width, &window_height);
        // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, window_width, 0, window_height, -1, 1);
        glMatrixMode(GL_MODELVIEW);

        //Render whatever you want
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex_handle);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0); glVertex2i(200,200);  
            glTexCoord2d(1,0); glVertex2i(200 + frame_width , 200 );
            glTexCoord2d(1,1); glVertex2i(200 + frame_width , 200 + frame_height);
            glTexCoord2d(0,1); glVertex2i(200 , 200 + frame_height);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);

        glfwWaitEvents();
    }

    return 0;
};
