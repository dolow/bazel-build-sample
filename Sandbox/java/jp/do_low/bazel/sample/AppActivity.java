package jp.do_low.bazel.sample;

import android.app.Activity;
import android.os.Bundle;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.view.ViewGroup.LayoutParams;
import android.util.Log;

public class AppActivity extends Activity
{
    static {
        System.loadLibrary("android_app");
    }

    private native static void jniCallback(String text);
    
    @Override
    protected void onCreate(final Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        
        RelativeLayout layout = new RelativeLayout(this);
        RelativeLayout.LayoutParams relativeParams = new RelativeLayout.LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
        
        TextView textView = new TextView(getApplicationContext());
        textView.setText("Hello Bazel !");
        layout.addView(textView, relativeParams);
        
        setContentView(layout);
        
        jniCallback("string from java");
    }

    public static void jniCall(String text)
    {
        Log.d("sandbox", text);
    }
}
