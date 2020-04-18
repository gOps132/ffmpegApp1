#include <iostream>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

int main(int argc, const char* argv[])
{
    //some sample algorithm to test the program
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " ";
        if ( i >= argc)
        {
            std::cout << " " << std::endl;
            break;
        }
    }
    std::cout << "END" << std::endl;
};