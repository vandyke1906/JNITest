//
// Created by Anonymous on 26/06/2021.
//
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitest_MainActivity_stringFromStaticJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from Static C++";
    return env->NewStringUTF(hello.c_str());
}
