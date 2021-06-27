cmake_minimum_required(VERSION 3.10.2)
project("jnitest")

#add_library(native-lib
##        SHARED
##        native-lib.cpp main-jni.cpp)
##transfer folder
add_library(native-lib
        SHARED
        shared/native-lib.cpp shared/main-jni.cpp)


add_library(static-lib STATIC static/static-lib.cpp)

#build path reference
#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/.cxx/cmake/debug/arm64-v8a
#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/build/intermediates/cmake/debug/obj/x86_64


find_library(
        log-lib
        log )

#for generation of static library testStaticLib.a
#static samples
add_library(testStaticLib STATIC testStatic/TestStatic1.cpp testStatic/TestStatic2.cpp)
# Specifies a path to native header files.
include_directories(src/main/cpp/testStatic/include/)
#end static samples
# include testStaticLib in target link libraries below to regenerate the static library
#for generation of static library testStaticLib.a


target_link_libraries(native-lib static-lib testStaticLib ${log-lib} )
