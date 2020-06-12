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

/*
    Class that holds the current state and metadata of the input file needed in order for
    openGL and ffmpeg to read and write from it.
*/
class VideoReaderState {
public:    
    int width, height;
    int video_stream_index;
    uint8_t* frame_buffer;
    AVRational time_base;
    AVFormatContext* av_format_ctx;
    AVCodecContext* av_codec_ctx;
    AVFrame* av_frame;
    AVPacket* av_packet;
    SwsContext* sws_scaler_ctx;
};

/* Opens the file and setups the Video reader state metadata */
bool video_reader_open(VideoReaderState* state, const char* filename);

/* Reads frame from packets, and reads back a frame buffer */
bool video_reader_read_frame(VideoReaderState* state, uint8_t* frame_buffer, int64_t* pts);

bool video_reader_seek_frame(VideoReaderState* state, int64_t ts);

/* properly clean up the routine at the end, freeing up the context that is allocated */
void video_reader_close(VideoReaderState* state);

#endif