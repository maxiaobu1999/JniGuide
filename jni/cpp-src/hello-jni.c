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


JNIEXPORT jobject JNICALL Java_com_norman_app_jni_NativeUtil_accessStudent (
JNIEnv *env, jobject thiz,jobject student) {
    // 1.获取 Student 类的Class引用
    //通过object实例获取class
    //也可以通过完整的类名获取class示例： jclass clazz = (*env)->FindClass(env, "com/norman/app/jni/Student");
    jclass clazz = (*env)->GetObjectClass(env,student);

    // 2. 获取 Student 类实例变量 name 的属性ID
    jfieldID name_fid = (*env)->GetFieldID(env,clazz,"name", "Ljava/lang/String;");
    // 3. 获取实例变量 name 的值
    jstring name = (jstring)(*env)->GetObjectField(env,student,name_fid);
    // 4. 将unicode编码的java字符串转换成C风格字符串
    const char *c_name = NULL;
    c_name = (*env)->GetStringUTFChars(env,name,NULL);
    LOGD( "c_name=%s", c_name);
    (*env)->ReleaseStringUTFChars(env, name, c_name);
    // 5. 修改实例变量str的值
    jstring j_newName = (*env)->NewStringUTF(env, "李四");
    (*env)->SetObjectField(env, student, name_fid, j_newName);


    //访问静态变量
    //获取ClassField类静态变量age的属性ID
    jfieldID age_fid = (*env)->GetStaticFieldID(env, clazz, "age", "I");
    jint age = (*env)->GetStaticIntField(env,clazz,age_fid);
    LOGD( "age=%d", age);
    (*env)->SetStaticIntField(env, clazz, age_fid, 80);

    // 删除属部引用
    (*env)->DeleteLocalRef(env,clazz);
    return student;
}



