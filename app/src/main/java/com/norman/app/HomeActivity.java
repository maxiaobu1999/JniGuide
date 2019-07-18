package com.norman.app;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import com.norman.app.jni.NativeUtil;
import com.norman.app.jni.Student;

public class HomeActivity extends AppCompatActivity {
    public static final String TAG = "HomeActivity+++:";
    private Activity mActivity;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        mActivity = this;

        final NativeUtil nativeUtil = new NativeUtil();
        addButton("nativeUtil.hello").setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String obj = "obj";
                short s = 1;
                long l = 20;
                byte b = 127;
                String string = nativeUtil.hello(s, 1, l, 1.0f, 10.5, 'A', true, b, "中国", obj, new int[]{});
                Log.d(TAG, string);
            }
        });
        addButton("nativeUtil.accessStudent").setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Student student = new Student("张三", 11);
                Student studentNew = nativeUtil.accessStudent(student);
                Log.d(TAG, "studentNew.name:" + studentNew.name);
                Log.d(TAG, "studentNew.age:" + Student.age);
            }
        });


        addButton("nativeUtil.dynamicRegister").setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nativeUtil.dynamicRegister("11111111");
            }
        });

    }


    private Button addButton(String string) {
        Button button = new Button(mActivity);
        FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 300);
        params.topMargin = 50;
        button.setLayoutParams(params);
        button.setText(string);
        LinearLayout ll = findViewById(R.id.ll_container);
        ll.addView(button);
        return button;
    }
}
