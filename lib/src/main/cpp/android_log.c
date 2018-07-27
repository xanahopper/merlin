//
// Created by xana/cuixianming on 2018-01-22.
// Copyright (c) 2018 Keep. All rights reserved.
//

#include "android_log.h"

int FFMPEG_ANDROID_DEBUG = 0;

void set_ffmpeg_log_debug(int enable) {
    FFMPEG_ANDROID_DEBUG = enable;
}

void ffmpeg_android_log_callback(void *ptr, int level, const char *fmt, va_list vl) {
    if (FFMPEG_ANDROID_DEBUG) {
        switch (level) {
            case AV_LOG_DEBUG:
                logd(fmt, vl);
                break;
            case AV_LOG_VERBOSE:
                logv(fmt, vl);
                break;
            case AV_LOG_INFO:
                logi(fmt, vl);
                break;
            case AV_LOG_WARNING:
                logw(fmt, vl);
                break;
            case AV_LOG_ERROR:
                loge(fmt, vl);
                break;
        }
    }
}
