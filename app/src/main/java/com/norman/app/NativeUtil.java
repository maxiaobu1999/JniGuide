package com.norman.app;

public class NativeUtil {

    static {
        // 加载 JNI 库
        System.loadLibrary("hello-jni");
    }


    // 声明 Native 方法
    public native String hello();

}
