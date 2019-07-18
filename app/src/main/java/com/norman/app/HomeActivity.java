package com.norman.app;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class HomeActivity extends AppCompatActivity {
    public static final String TAG = "HomeActivity+++:";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        NativeUtil nativeUtil = new NativeUtil();
        String obj = "obj";
        short s = 1;
        long l = 20;
        byte b = 127;
        String string = nativeUtil.hello(s, 1, l, 1.0f, 10.5, 'A', true, b, "中国", obj, new int[] {});
        Log.d(TAG, string);
    }
}
