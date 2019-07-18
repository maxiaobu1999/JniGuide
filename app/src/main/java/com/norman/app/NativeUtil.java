package com.norman.app;

public class NativeUtil {

    static {
        // 加载 JNI 库
        System.loadLibrary("hello-jni");
    }


    // 声明 Native 方法
    public static native String hello(short s, int i, long l, float f, double d, char c,
                               boolean z, byte b, String str, Object obj, int[] arr);

}
