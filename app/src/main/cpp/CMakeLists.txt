cmake_minimum_required(VERSION 3.10.2)
project("jnitest")

add_library(native-lib
        SHARED
        native-lib.cpp main-jni.cpp)


#add_library( static-lib
#        STATIC
#        static-lib.cpp)

add_library(static-lib STATIC static-lib.cpp)

#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/.cxx/cmake/debug/arm64-v8a
#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/build/intermediates/cmake/debug/obj/x86_64


find_library(
        log-lib
        log )

#for generation of static library testStaticLib.a
#static samples
add_library(testStaticLib STATIC TestStatic1.cpp TestStatic2.cpp)
# Specifies a path to native header files.
include_directories(src/main/cpp/include/)
#end static samples
# include testStaticLib in target link libraries below to regenerate the static library
#for generation of static library testStaticLib.a


target_link_libraries(native-lib static-lib testStaticLib ${log-lib} )
