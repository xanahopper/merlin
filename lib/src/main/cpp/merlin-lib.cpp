#include <jni.h>
#include <string>
extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libavcodec/jni.h>
    #include "android_log.h"
}


jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    av_jni_set_java_vm(vm, nullptr);

    return JNI_VERSION_1_6;
}

void set_debug_log(bool enable) {
    set_ffmpeg_log_debug(enable ? 1 : 0);
    av_log_set_callback(enable ? ffmpeg_android_log_callback : nullptr);
}