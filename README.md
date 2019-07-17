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
