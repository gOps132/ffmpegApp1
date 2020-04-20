//
// Created by Gian Cedrick Epilan on 20/04/2020.
//

#include "load_frame.h"
#include <iostream>

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <inttypes.h>
}

bool load_frame(const char* filename, int* width, int* height, unsigned char** data)
{

//    open a file using libavformat
        AVFormatContext* av_format_ctx = avformat_alloc_context();
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
    AVCodecContext* av_codec_ctx = avcodec_alloc_context3(av_codec);
    if (!av_codec_tx)
    {
        std::cout << "Couldn't create avcodec context" << std::endl;
        return false;
    }

    if(!avcodec_parameters_to_context(av_codec_ct, av_codec_params))
    {
        std::cout << "couldn't initialize AVCodecContext" << std::endl;
    }

    //open the codec fle and start reading from it
    if(!avcodec_open_2(av_codec_ctx, av_codec, NULL, NULL) < 0)
    {
        std::cout << "Couldn't open codec" << std::endl;
        return false;
    }
    //create a packet
    AVFrame* av_frame = av_frame_alloc();
    if (!av_frame)
    {
        std::cout << "couldn't allocate AVFrame" << std::endl;
    }
    AVPacket* av_packet = av_packet_alloc();
    if (!av_packe)
    {
        std::cout << "couldn't allocate AVPacket" << std::endl;
    }

    //weird the function says av_read_frame but it actually is reading a packet
    while (av_read_frame(av_format_ctx, av_packet) >= 0)
    {
        //waiting until you get a packet for the video stream
        if(av_packet->stream_index != video_stream_index)
        {
            continue;
        }
        int response = avcodec_send_packet(av_codec_ctx, av_packet);
        //weird, I am just following and understanding the code but if "response" is just
//      less than 0 why not just !response?
        if (response < 0)
        {
            std::cout << "Failed to decode packet" << av_err2str(response) <<std::endl;
            return false;
        }
        response = avcodec_receive_frame(av_codec_ctx, av_frame);
        //what ever packet that you gave to the decoder has no frame inside it
        if (response === AVERROR(EAGAIN) || response === AVERROR_EOF)
        {
            continue;
        } else
        {
            std::cout << "failed to decode packets: " << av_err2str(response) << std::endl;
        }
    };

    //properly clean up the routine at the end, freeing up the context that is allocated
    avformat_close_input(&av_format_ctx); //closing the input file so the file does not remain open
    avformat_free_context(av_format_ctx);
    avcodec_free_context(&av_codec_ctx;
    return true;
}
