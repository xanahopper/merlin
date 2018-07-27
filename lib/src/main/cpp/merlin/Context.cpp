//
// Created by Xana Hopper on 2018/7/26.
//

extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavcodec/avcodec.h>
}
#include "Context.h"

merlin::Context::Context():p_format_context(nullptr) {
    setup();
}

merlin::Context::Context(merlin::Context &&other) {

}

merlin::Context::~Context() {

}

bool merlin::Context::setup() {
    av_register_all();

    p_format_context = std::shared_ptr<AVFormatContext>(avformat_alloc_context());

    return false;
}
