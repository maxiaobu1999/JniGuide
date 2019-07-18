package com.norman.app.jni;
public class NativeUtil {

    static {
        // 加载 JNI 库
        System.loadLibrary("hello-jni");
    }


    // 声明 Native 方法
    public  native String hello(short s, int i, long l, float f, double d, char c,
                               boolean z, byte b, String str, Object obj, int[] arr);


    //使用javac时，使用*.java，把Student.java包含进去
    public  native Student accessStudent(Student student);


    //动态注册native   方法
    public  native void dynamicRegister(String s);

}
