package com.norman.app.jni;

import android.util.Log;

public class Student {
    public static final String TAG = "HomeActivity+++:";

    public String name;
    public static int age;

    //jni调用默认构造，不写出来报错
    public Student() {

    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void normalMethod(String s,int i) {
        Log.d(TAG, "Student类normalMethod()执行，参数String s="+s+"参数：int i="+i);
    }

    public static String staticMethod(String s) {
        Log.d("Student", "Student类staticMethod()执行，参数String s="+s);
        return "normalMethod()的返回值";
    }



    public String toString() {
        return "Student:" + name + ":" + age;
    }
}
