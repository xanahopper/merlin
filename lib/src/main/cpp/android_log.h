//
// Created by xana/cuixianming on 2018-01-22.
// Copyright (c) 2018 Keep. All rights reserved.
//

#ifndef FFMPEGUTILS_ANDROID_LOG_H
#define FFMPEGUTILS_ANDROID_LOG_H
#include "libavutil/log.h"

#define LOG_TAG "merlin-native"
#include <android/log.h>

#define logv(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG ,__VA_ARGS__)
#define logd(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG ,__VA_ARGS__)
#define logi(...) __android_log_print(ANDROID_LOG_INFO,  LOG_TAG ,__VA_ARGS__)
#define logw(...) __android_log_print(ANDROID_LOG_WARN,  LOG_TAG ,__VA_ARGS__)
#define loge(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG ,__VA_ARGS__)
#define logf(...) __android_log_print(ANDROID_LOG_FATAL, LOG_TAG ,__VA_ARGS__)

void set_ffmpeg_log_debug(int enable);
void ffmpeg_android_log_callback(void *ptr, int level, const char *fmt, va_list vl);

#endif //FFMPEGUTILS_ANDROID_LOG_H
