cmake_minimum_required(VERSION 3.10.2)
project("jnitest")


# set up common compile options
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -fno-exceptions -fno-rtti")



#########################
##### TEST EACH SEPARATE
#########################
####ORIGINAL
#add_library(native-lib SHARED shared/native-lib.cpp)
#find_library(log-lib log)
##target_link_libraries(native-lib ${log-lib} )
####ORIGINAL
#
#
### STATIC
#add_library(static-lib static/static-lib.cpp)
#target_link_libraries(static-lib PUBLIC StaticLib)
#target_include_directories(static-lib PUBLIC ${ANDROID_NDK}/sources/android/static-lib)
#
#add_library(testStaticLib STATIC testStatic/TestStatic1.cpp testStatic/TestStatic2.cpp)
#target_link_libraries(testStaticLib PUBLIC TestStaticLib)
#target_include_directories(testStaticLib PUBLIC ${ANDROID_NDK}/sources/android/testStaticLib)
#include_directories(src/main/cpp/testStatic/include/)
#
#add_library(staticLoadA
#        STATIC
#        IMPORTED
#        )
#set_target_properties(staticLoadA
#        PROPERTIES IMPORTED_LOCATION
#        $ENV{HOME}/app/libs/libstatic-lib.a)
#
##$ENV{HOME}/app/build/intermediates/cmake/debug/obj/arm64-v8a/libstatic-lib.a )
#
#########################
##### TEST EACH SEPARATE
#########################




########################
#### OLD WORKING
########################

add_library(native-lib
        SHARED
        shared/native-lib.cpp shared/main-jni.cpp prebuild/libstatic-lib.a)
#target_link_libraries(native-lib ${log-lib} )


add_library(static-lib STATIC static/static-lib.cpp)
target_include_directories(static-lib PUBLIC
        ${ANDROID_NDK}/sources/android/static-lib)



#build path reference
#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/.cxx/cmake/debug/arm64-v8a
#/Users/anonymous/Documents/Apps/company-project/tests/JNITest/app/build/intermediates/cmake/debug/obj/arm64-v8a/libstatic-lib.a


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



target_link_libraries(native-lib static-lib testStaticLib)
#target_link_libraries(native-lib static-lib testStaticLib ${log-lib} ) //working for adding and minus
#target_link_libraries(static-lib testStaticLib)

#target_link_libraries(native-lib ${log-lib} )
#target_link_libraries(static-lib)
#target_link_libraries(testStaticLib)

add_library(staticLoadA
        STATIC
        IMPORTED
        )
set_target_properties(staticLoadA
        PROPERTIES IMPORTED_LOCATION
        $ENV{HOME}/app/build/intermediates/cmake/debug/obj/arm64-v8a/libstatic-lib.a )

########################
#### OLD WORKING
########################