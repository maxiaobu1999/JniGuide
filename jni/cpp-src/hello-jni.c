#include <string.h>
#include <jni.h>
#include "com_norman_app_NativeUtil.h"
#include "util/log.h"


/**
 * JNI 示例，演示native方法返回一个字符串，Java 源码见
 * NDKBuildUtil.java
 */
JNIEXPORT jstring JNICALL Java_com_norman_app_NativeUtil_hello (
JNIEnv *env, jobject thiz,
jshort s, jint i, jlong l, jfloat f,jdouble d, jchar c, jboolean z, jbyte b,
jstring j_str, jobject jobj, jintArray j_int_arr) {

    LOGD( "s=%hd, i=%d, l=%ld, f=%f, d=%lf, c=%c, z=%d, b=%d", s, i, (long)l, f, d, c, z, b);
    const char *c_str = NULL;
    c_str = (*env)->GetStringUTFChars(env, j_str, NULL);
    LOGD( "j_str=%s", c_str);
    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI ");
}



