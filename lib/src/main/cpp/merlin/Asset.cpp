//
// Created by Xana Hopper on 2018/7/26.
//

#include "Asset.h"

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libavcodec/avcodec.h>
}

merlin::Asset::Asset(): m_asset_type(none) {

}

merlin::Asset::Asset(merlin::Asset &&other) {
    this->m_asset_type = other.m_asset_type;
    this->m_uri = std::move(other.m_uri);
}

merlin::Asset::~Asset() {

}
