//
// Created by Gian Cedrick Epilan on 20/04/2020.
//
// will be continuing documenting the functions and each line of code later
//

#include "load_frame.h"
#include <iostream>

extern "C"
{
//    video stuff
    #include <libavcodec/avcodec.h>
//    reading the video files and other data manipulation
    #include <libavformat/avformat.h>
//    use uint
    #include <inttypes.h>
//    using swscale for the color conversion and more
    #include <libswscale/swscale.h>
}

bool load_frame(const char* filename, int* width_out, int* height_out, unsigned char** data_out)
{
//   refractoring the declarations here
    AVFormatContext* av_format_ctx;
    AVCodecContext* av_codec_ctx;
    AVFrame* av_frame;
    AVPacket* av_packet;
    SwsContext* sws_scaler_ctx;

//    open a file using libavformat
    av_format_ctx = avformat_alloc_context();
    if (!av_format_ctx) {
        std::cout << "couldn't create avformat ctx" << std::endl;
        return false;
    }

    if(avformat_open_input(&av_format_ctx, filename, NULL, NULL) !=0)
    {
        std::cout << "couldn't open video file" << std::endl;
        return false;
    };

    //find the first valid video stream inside the file
    int video_stream_index = -1;
    AVCodecParameters* av_codec_params;
    AVCodec* av_codec;

    //document this loop
    for (int i = 0; i < av_format_ctx->nb_streams; ++i)
    {
        av_codec_params = av_format_ctx->streams[i]->codecpar;
        av_codec = avcodec_find_decoder(av_codec_params->codec_id);

        if (!av_codec)
        {
            continue;
        }

        if (av_codec_params->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            video_stream_index = i;
            break;
        }

//        if (av_codec->codec_type === AVMEDIA_TYPE_AUDIO)
//        {
//
//        }

        auto stream = av_format_ctx->streams[i];

    }

    if (video_stream_index == -1)
    {
        std::cout << "couldn't find valid stream inside video file" << std::endl;
        return false;
    }

//    sample "video frame" returns a buffer of red pixels
//    *width = 100;
//    *height = 100;
//    *data = new unsigned char[100 * 100 * 3];
//    auto ptr = *data;
//    for (int x = 0; x < 100; ++x) {
//        for (int y = 0; y < 100; ++y) {
//            *ptr++ = 0xff;
//            *ptr++ = 0x00;
//            *ptr++ = 0x00;
//        }
//    }

    //setup codec context fro the decoder
    av_codec_ctx = avcodec_alloc_context3(av_codec);
    if (!av_codec_ctx)
    {
        std::cout << "Couldn't create avcodec context" << std::endl;
        return false;
    }

    if(avcodec_parameters_to_context(av_codec_ctx, av_codec_params) < 0)
    {
        std::cout << "couldn't initialize AVCodecContext" << std::endl;
        return false;
    }

    //open the codec fle and start reading from it
    if(avcodec_open2(av_codec_ctx, av_codec, NULL) < 0)
    {
        std::cout << "Couldn't open codec" << std::endl;
        return false;
    }
    //create a packet
    av_frame = av_frame_alloc();
    if (!av_frame)
    {
        std::cout << "couldn't allocate AVFrame" << std::endl;
    }
    av_packet = av_packet_alloc();
    if (!av_packet)
    {
        std::cout << "couldn't allocate AVPacket" << std::endl;
    }

    int response;

    //weird the function says av_read_frame but it actually is reading a packet
    while (av_read_frame(av_format_ctx, av_packet) >= 0)
    {
        //waiting until you get a packet for the video stream
        if(av_packet->stream_index != video_stream_index)
        {
            continue;
        }
        response = avcodec_send_packet(av_codec_ctx, av_packet);
        //weird, I am just following and understanding the code but if "response" is just
//      less than 0 why not just !response?
        if (response < 0)
        {
            std::cout << "Failed to decode packet" << av_err2str(response) <<std::endl;
            return false;
        }
        response = avcodec_receive_frame(av_codec_ctx, av_frame);
        //what ever packet that you gave to the decoder has no frame inside it
        if (response == AVERROR(EAGAIN) || response == AVERROR_EOF)
        {
            continue;
        } else if (response < 0)
        {
            std::cout << "failed to decode packets: " << av_err2str(response) << std::endl;
            return false;
        }

        //at this point you've got raw data decoded in your AVFrame
        //dummy statement
        av_packet_unref(av_packet);
        break;
    };

//    at this point we have a AV_FRAME variable and that stores the raw data, that is decompressed from the codec
//    and it will store it in YUV format

    //get the data from the av_frame and put it in some rectangle
    //allocate some data
    //making RGB data
//    unsigned char* data = new unsigned char[av_frame->width * av_frame->height * 3];
    //? converting and returning YUV to RGB
//    for (int x = 0; x < av_frame->width; ++x)
//    {
//        returning RGB (red block)
//        for (int y = 0; y < av_frame->height; ++y)
//        {
//            //filling in the data
//            data[y * av_frame->width * 3 + x * 3] = 0xff;   //RED
//            data[y * av_frame->width * 3 + x * 3 + 1] = 0x00;   //BLUE
//            data[y * av_frame->width * 3 + x * 3 + 2] = 0x00;   //GREEN
//            the "data" does not have any actual data, it's stil a red block but it still have the dimensions of the frame
//        }

//        convert raw YUV data format from frame to RGB
//        for (int y = 0; y < av_frame->height; ++y)
//        {
//            //filling in the data
//            //returning gray scale pixel data
//            data[y * av_frame->width * 3 + x * 3    ] = av_frame->data[0][y * av_frame->linesize[0] + x];
//            data[y * av_frame->width * 3 + x * 3 + 1] = av_frame->data[0][y * av_frame->linesize[0] + x];
//            data[y * av_frame->width * 3 + x * 3 + 2] = av_frame->data[0][y * av_frame->linesize[0] + x];
//        }
//    }
//    *width_out = av_frame->width;
//    *height_out = av_frame->height;
//    *data_out = data;

// allocate the buffer, 4 bytes for everypixel
    uint8_t* data = new uint8_t[av_frame->width * av_frame->height * 4];

//create a swscalar context, which is all the data that the data that the scalar needs to be converting color spaces
//    or converting sizes  of the image
    sws_scaler_ctx = sws_getContext(
            av_frame->width,
            av_frame->height,
            av_codec_ctx->pix_fmt,
            av_frame->width,
            av_frame->height,
            AV_PIX_FMT_RGB0,
            SWS_BILINEAR,
            NULL,
            NULL,
            NULL
            );

    if (!sws_scaler_ctx)
    {
        std::cout << "Couldn't initialize sws_scaler" << std::endl;
        return false;
    }

    uint8_t* dest[4] = { data, NULL, NULL, NULL};
    int dest_linesize[4] =  { av_frame->width * 4, 0, 0, 0 };
    sws_scale(sws_scaler_ctx, av_frame->data, av_frame->linesize, 0, av_frame->height, dest, dest_linesize);
    sws_freeContext(sws_scaler_ctx);

    *width_out = av_frame->width;
    *height_out = av_frame->height;
    *data_out = data;

    //properly clean up the routine at the end, freeing up the context that is allocated
    av_frame_free(&av_frame);
    av_packet_free(&av_packet);
    avformat_close_input(&av_format_ctx); //closing the input file so the file does not remain open
    avformat_free_context(av_format_ctx);
    avcodec_free_context(&av_codec_ctx);

    return true;
}
