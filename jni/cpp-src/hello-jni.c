#include <string.h>
#include <jni.h>
#include "com_norman_app_jni_NativeUtil.h"
#include "util/log.h"


/**
 * JNI 示例，演示native方法返回一个字符串，Java 源码见
 * NDKBuildUtil.java
 */
JNIEXPORT jstring JNICALL Java_com_norman_app_jni_NativeUtil_hello (
JNIEnv *env, jobject thiz,
jshort s, jint i, jlong l, jfloat f,jdouble d, jchar c, jboolean z, jbyte b,
jstring j_str, jobject jobj, jintArray j_int_arr) {

    LOGD( "s=%hd, i=%d, l=%ld, f=%f, d=%lf, c=%c, z=%d, b=%d", s, i, (long)l, f, d, c, z, b);
    const char *c_str = NULL;
    c_str = (*env)->GetStringUTFChars(env, j_str, NULL);
    LOGD( "j_str=%s", c_str);
    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI ");
}

//studentFieldIds:结构变量
//struct fieldIds {
 //   jclass studentClass;
   // jfieldID name;
   // jfieldID age;
//}studentFieldIds;
JNIEXPORT jobject JNICALL Java_com_norman_app_jni_NativeUtil_accessStudent (
JNIEnv *env, jobject thiz,jobject student) {

    //得java自定义类Student, FindClass的参数,指明的是从source file开始的Student类的路径
    //studentFieldIds.studentClass = (*env)->FindClass(env, "com/norman/app/jni/Student");
    //studentFieldIds.name = (*env)->GetFieldID(env, studentFieldIds.studentClass, "name", "Ljava/lang/String;");
    //LOGD( "studentFieldIds.name=%s",studentFieldIds.name);

    //studentFieldIds.age = (*env)->GetFieldID(env, studentFieldIds.studentClass, "age", "I");
     // change the 'age' value of student
    //(*env)->SetIntField(env, student, studentFieldIds.age, 20);
    return student;
}



