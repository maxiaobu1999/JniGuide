package com.norman.app.jni;

public class Student {
    public String name;
    public static int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return "Student:" + name + ":" + age;
    }
}
