#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnitest_MainActivity_stringFromSharedJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from Shared Library";
    return env->NewStringUTF(hello.c_str());
}