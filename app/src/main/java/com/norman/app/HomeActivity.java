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
        String s = nativeUtil.hello();
        Log.d(TAG, s);
    }
}
