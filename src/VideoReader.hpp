//
// Created by Gian Cedrick Epilan on 22/04/2020.
//

#ifndef video_reader_hpp
#define video_reader_hpp

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <inttypes.h>
#include <libswscale/swscale.h>
}

//refractoring the declarations here
class VideoReaderState {
public:
    //public things for other parts of the program to read from
    
    int width, height;
    uint8_t* frame_buffer;

    //private internal state
    AVFormatContext* av_format_ctx;
    AVCodecContext* av_codec_ctx;
    int video_stream_index;
    AVFrame* av_frame;
    AVPacket* av_packet;
    SwsContext* sws_scaler_ctx;
};

bool video_reader_open(VideoReaderState* state, const char* filename);
bool video_reader_read_frame(VideoReaderState* state, uint8_t* frame_buffer);
bool video_reader_close(VideoReaderState* state);

#endif