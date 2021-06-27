package com.example.jnitest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int adding = add();
        int subs = minus();
        Integer resAdd= new Integer(adding);
        Integer resSubtract= new Integer(subs);

        // Example of a call to a native method
        TextView tv1 = findViewById(R.id.tv1);
        TextView tv2 = findViewById(R.id.tv2);
        TextView tv3 = findViewById(R.id.tv3);

        tv1.setText(stringFromSharedJNI());
        tv2.setText("Static Add " + resAdd.toString());
        tv3.setText("Static Subtract " + resSubtract.toString());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromSharedJNI();
    private native int add();
    private native int minus();
}