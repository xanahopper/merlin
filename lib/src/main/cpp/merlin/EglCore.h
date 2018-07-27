//
// Created by Xana Hopper on 2018/7/27.
//

#ifndef MERLIN_EGLCORE_H
#define MERLIN_EGLCORE_H

#ifdef __ANDROID__
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

#include <android/native_window.h>
#include <android/native_window_jni.h>
#elif defined(__APPLE__)

#endif

#include <memory>

namespace merlin {
    class EglCore {
    public:
        const int FLAG_TRY_OPENGL_ES3 = 1;
    public:
        EglCore();
        EglCore(int flags);
        EglCore(EGLContext *share_context, int flags);

        ~EglCore();

        EglCore(const EglCore &) = delete;
        EglCore& operator=(const EglCore &) = delete;

    private:
#ifdef __ANDROID__
        std::shared_ptr<EGLContext> m_egl_context;
        std::shared_ptr<EGLDisplay> m_egl_display;
        std::unique_ptr<EGLSurface> m_egl_surface;
#endif
    };
}


#endif //MERLIN_EGLCORE_H
