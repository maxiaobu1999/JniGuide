package com.norman.app.jni;

public class Student {
    public String name;
    public int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return "Student:" + name + ":" + age;
    }
}
