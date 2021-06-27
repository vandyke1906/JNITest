//
// Created by Anonymous on 27/06/2021.
//

#include <jni.h>
#include <stdio.h>

#include "include/TestStatic1.h"
#include "include/TestStatic2.h"

extern "C" JNIEXPORT jint JNICALL Java_com_example_jnitest_MainActivity_add(
        JNIEnv* env,
        jobject /* this */) {
    jint result = add(5,2);
    return result;
}

extern "C" JNIEXPORT jint JNICALL Java_com_example_jnitest_MainActivity_minus(
        JNIEnv* env,
        jobject /* this */) {
    jint result = minus(5,2);
    return result;
}
