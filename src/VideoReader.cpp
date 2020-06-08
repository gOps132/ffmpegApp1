//
// Created by Gian Cedrick Epilan on 22/04/2020.
//

#include "VideoReader.hpp"
#include <iostream>

bool video_reader_open(VideoReaderState* state, const char* filename){

    //unpack members of state
    auto& width = state->width;
    auto& height = state->height;
    auto& av_format_ctx = state->av_format_ctx;
    auto& av_codec_ctx = state->av_codec_ctx;
    auto& video_stream_index = state->video_stream_index;
    auto& av_frame = state->av_frame;
    auto& av_packet = state->av_packet;

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
    video_stream_index = -1;
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
            width = av_codec_params->width;
            height = av_codec_params->height;
            video_stream_index = i;
            break;
        }

        auto stream = av_format_ctx->streams[i];

    }

    if (video_stream_index == -1)
    {
        std::cout << "couldn't find valid stream inside video file" << std::endl;
        return false;
    }

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
        return false;
    }
    av_packet = av_packet_alloc();
    if (!av_packet)
    {
        std::cout << "couldn't allocate AVPacket" << std::endl;
        return false;
    }

        return true;
}


bool video_reader_read_frame(VideoReaderState* state, uint8_t* frame_buffer){

    //unpack members of state
    auto& width = state->width;
    auto& height = state->height;
    auto& av_format_ctx = state->av_format_ctx;
    auto& av_codec_ctx = state->av_codec_ctx;
    auto& video_stream_index = state->video_stream_index;
    auto& av_frame = state->av_frame;
    auto& av_packet = state->av_packet;
    auto& sws_scaler_ctx = state->sws_scaler_ctx;

    int response;
    //the function says av_read_frame but it actually is reading a packet
    while (av_read_frame(av_format_ctx, av_packet) >= 0){
        //waiting until you get a packet for the video stream
        if(av_packet->stream_index != video_stream_index){
            continue;
        }
        response = avcodec_send_packet(av_codec_ctx, av_packet);
        //I am just following and understanding the code but if "response" is just
        //less than 0 why not just !response?
        if (response < 0){
            std::cout << "Failed to decode packet" << av_err2str(response) <<std::endl;
            return false;
        }
        response = avcodec_receive_frame(av_codec_ctx, av_frame);
        //what ever packet that you gave to the decoder has no frame inside it
        if (response == AVERROR(EAGAIN) || response == AVERROR_EOF){
            continue;
        } else if (response < 0){
            std::cout << "failed to decode packets: " << av_err2str(response) << std::endl;
            return false;
        }

        //at this point you've got raw data decoded in your AVFrame
        //dummy statement
        av_packet_unref(av_packet);
        break;
    }

    // setup sws scaler to convert the pixel data from the internal format of the video file
    // to RGB0 so we can put it into openGLq
    if (!sws_scaler_ctx) {
    sws_scaler_ctx = sws_getContext(width, height, av_codec_ctx->pix_fmt,
                                    width / 2, height / 2, AV_PIX_FMT_RGB0, SWS_BILINEAR,
                                    NULL, NULL, NULL );
    }
    if (!sws_scaler_ctx){
        std::cout << "Couldn't initialize sws_scaler" << std::endl;
        return false;
    }

    uint8_t* dest[4] = { frame_buffer, NULL, NULL, NULL};
    int dest_linesize[4] =  { width * 4, 0, 0, 0 };
    sws_scale(sws_scaler_ctx, av_frame->data, av_frame->linesize, 0, av_frame->height, dest, dest_linesize);
 
    return true;
} 

bool video_reader_close(VideoReaderState* state){
    //properly clean up the routine at the end, freeing up the context that is allocated
    sws_freeContext(state->sws_scaler_ctx);
    av_frame_free(&state->av_frame);
    av_packet_free(&state->av_packet);
    avformat_close_input(&state->av_format_ctx); //closing the input file so the file does not remain open
    avformat_free_context(state->av_format_ctx);
    avcodec_free_context(&state->av_codec_ctx);
}
