package com.holamundondk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class HolaMundoNDK extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    private TextView salida;



    static {
        System.loadLibrary("holamundondk");//"native-lib");
    }

    public native String dameDatos();
    public native String funcion1(String message);
    public native void funcion2();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hola_mundo_ndk);
        setTitle(dameDatos());
        salida = (TextView) super.findViewById(R.id.output);
        // Example of a call to a native method
        //TextView tv = (TextView) findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     * <p>
     * public native String stringFromJNI();
     */
    public void button0(View v) {
        salida.setText(funcion1("testString"));
    }

    public void button1(View v) {
        funcion2();
    }

    public void funcion3Callback() {
        String message = "funcion3Callback llamada por la funcion2 nativa";
        salida.setText(message);
    }

    public void run() {
    }
}
