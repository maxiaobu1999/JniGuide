#include <string.h>
#include <jni.h>
#include "com_norman_app_jni_NativeUtil.h"
#include "util/log.h"
#include <assert.h>


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


    //访问Java实例构造方法，并创建实例
    jmethodID mid_construct = (*env)->GetMethodID(env,clazz, "<init>","()V");
    jobject jstudent_new =  (*env)->NewObject(env,clazz,mid_construct);

    //访问对象实例普通方法
    //"(Ljava/lang/String;I)V"：参数签名 ()代表无参数   V表示无返回值
    jmethodID mid_instance = (*env)->GetMethodID(env, clazz, "normalMethod", "(Ljava/lang/String;I)V");
    jstring str_arg = (*env)->NewStringUTF(env,"我是实例方法");
    //CallVoidMethod函数的原型:void (JNICALL *CallVoidMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);
    (*env)->CallVoidMethod(env,jstudent_new,mid_instance,str_arg,200);

    //访问Java的静态方法
    jmethodID mid_static =(*env)->GetStaticMethodID(env,clazz,"staticMethod","(Ljava/lang/String;)Ljava/lang/String;");
    jobject static_return = (*env)->CallStaticObjectMethod(env,clazz,mid_static, (*env)->NewStringUTF(env,"我是静态方法"));


    // 删除属部引用
    (*env)->DeleteLocalRef(env,clazz);
    return student;
}

//当Android的VM(Virtual Machine)执行到C组件(即*so档)里的System.loadLibrary()函数时，首先会去执行C组件里的JNI_OnLoad()函数。
//JavaVM *vm  JavaVM是虚拟机在JNI中的表示，一个JVM中只有一个JavaVM对象，这个对象是线程共享的
//void *reserved:??保留的
//return：告诉VM此C组件使用那一个JNI版本。
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved){
    LOGD( "JNI_OnLoad执行开始");
    //JNIEnv类型是一个指向全部JNI方法的指针。该指针只在创建它的线程有效，不能跨线程传递
    //使用GetEnv 获取 JNIEnv
    JNIEnv* env = NULL;
    //GetEnv()返回当前线程所在的JNIEnv*
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);
    LOGD( "JNI_OnLoad执行结束");
  return JNI_VERSION_1_4;
}

JNIEXPORT void JNI_OnUnload(JavaVM *jvm, void *reserved){
    LOGD( "JNI_OnUnload 执行");

}

