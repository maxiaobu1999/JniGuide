native代码变更后需执行
./gradlew externalNativeBuildDebug
./gradlew media_arm:externalNativeBuildDebug



##cmake定义和打印变量值
使用${}进行变量的引用。在 IF 等语句中,是直接使用变量名而不通过${}取值
 看下面的例子，我们在cmake定义了一个变量“USER_KEY”，并打印此变量值。status表示这是一般的打印信息，我们还可以设置为“ERROR”，表示这是一种错误打印信息。
 SET(USER_KEY "Hello World")
 MESSAGE( STATUS "this var key = ${USER_KEY}.")


#cmake 常用变量
如果是 in source 编译,指得就是工程顶层目录,如果是 out-of-source 编译,指的是工程编译发生的目录
CMAKE_BINARY_DIR:/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/.externalNativeBuild/cmake/debug/
PROJECT_BINARY_DIR :/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/.externalNativeBuild/cmake/debug/x86_64
 <projectname>_BINARY_DIR:不会用
 
不论采用何种编译方式,都是工程顶层目录。
CMAKE_SOURCE_DIR：/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/src/main/cpp
PROJECT_SOURCE_DIR:/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/src/main/cpp

指的是当前处理的 CMakeLists.txt 所在的路径
CMAKE_CURRENT_SOURCE_DIR：/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/src/main/cpp

如果是 in-source 编译,它跟 CMAKE_CURRENT_SOURCE_DIR 一致,如果是 out-of-source 编译,他指的是 target 编译目录。
CMAKE_CURRRENT_BINARY_DIR：未输出

输出调用这个变量的 CMakeLists.txt 的完整路径
CMAKE_CURRENT_LIST_FILE：/Users/v_maqinglong/Documents/AndroidProject/JniGuide/jni/src/main/cpp/CMakeLists.txt

输出这个变量所在文件第几行
CMAKE_CURRENT_LIST_LINE：3

这个变量用来定义自己的 cmake 模块所在的路径，默认为null
CMAKE_MODULE_PATH



###############jni
#JNIEnv
JNIEnv类型是一个指向全部JNI方法的指针。该指针只在创建它的线程有效，不能跨线程传递
#jobject thiz

#JavaVM
JavaVM是虚拟机在JNI中的表示，一个JVM中只有一个JavaVM对象，这个对象是线程共享的。


#JVM 查找 native 方法的规则
##按照 JNI 规范的命名规则
1\编写Java类
2\用 javac 命令将.java源文件编译成.class字节码文件
 javac /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/com/norman/app/NativeUtil.java -d /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/
 -d 表示将编译后的 class 文件放到指定的目录下
3、用 javah -jni 命令，根据class字节码文件生成.h头文件（-jni 参数是可选的）
 javah -jni -classpath /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/ -d ./ com.norman.app.NativeUtil
同时编译多个类：
    javac /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/com/norman/app/jni/*.java -d /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/com/norman/app/jni
    javah -jni -classpath /Users/v_maqinglong/Documents/AndroidProject/JniGuide/app/src/main/java/ -d ./ com.norman.app.jni.NativeUtil
###JNIEXPORT和JNICALL
宏，定义在NDK_ROOT / platforms / android-9 / arch-arm / usr / include / jni.h
简单理解：说明该函数为JNI函数，在Java虚拟机加载的时候会链接对应的native方法，将函数添加到动态表中


##手动注册调native方法：用 JNI 提供的 RegisterNatives 函数，将本地函数注册到 JVM 中。
JNI在加载时，会调用JNI_OnLoad，而卸载时会调用JNI_UnLoad，所以我们可以通过在JNI_OnLoad里面注册我们的native函数来实现JNI。
当Android的VM(Virtual Machine)执行到C组件(即*so档)里的System.loadLibrary()函数时，首先会去执行C组件里的JNI_OnLoad()函数。