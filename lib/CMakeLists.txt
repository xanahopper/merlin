# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(libs/include)

aux_source_directory(src/main/cpp SRCS)

aux_source_directory(src/main/cpp/merlin MERLIN_SRCS)

add_library( # Sets the name of the library.
             merlin

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${SRCS}
             ${MERLIN_SRCS})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

add_library(avcodec STATIC IMPORTED)
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavcodec.a)
add_library(avdevice STATIC IMPORTED)
set_target_properties(avdevice
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavdevice.a)

add_library(avfilter STATIC IMPORTED)
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavfilter.a)

add_library(avformat STATIC IMPORTED)
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavformat.a)

add_library(avresample STATIC IMPORTED)
set_target_properties(avresample
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavresample.a)

add_library(avutil STATIC IMPORTED)
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libavutil.a)

add_library(postproc STATIC IMPORTED)
set_target_properties(postproc
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libpostproc.a)

add_library(swresample STATIC IMPORTED)
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libswresample.a)

add_library(swscale STATIC IMPORTED)
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libswscale.a)

add_library(x264 STATIC IMPORTED)
set_target_properties(x264
        PROPERTIES IMPORTED_LOCATION
        ../../../../libs/${ANDROID_ABI}/libx264.a)
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )
find_library(z-lib z)
find_library(dl-lib dl)
find_library(c-lib c)
find_library(m-lib m)
find_library(egl-lib EGL)
find_library(gles2-lib GLESv2)
find_library(gles3-lib GLESv3)
# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                        merlin
                        avfilter
                        postproc
                        avresample
                        avdevice
                        avformat
                        avcodec
                        swscale
                        swresample
                        avutil
                        x264
                        ${z-lib}
                        ${dl-lib}
                        ${c-lib}
                        ${m-lib}
                        ${egl-lib}
                        ${gles2-lib}
                        ${gles3-lib}
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )