package de.savrasov.android.exercise6;

import android.hardware.SensorEvent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import java.util.List;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.hardware.SensorEventListener;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements SensorEventListener {

    SensorManager smm;
    List<Sensor> sensor;
    ListView lv;
    private SensorManager senSensorManager;
    private Sensor senAccelerometer;
    private TextView tV, tVRekord, tVAktuell;
    private float x, y, z, rekord, summe;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        rekord = 0;
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        smm = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        lv = (ListView) findViewById (R.id.listView1);
        sensor = smm.getSensorList(Sensor.TYPE_ALL);
        lv.setAdapter(new ArrayAdapter<Sensor>(this, android.R.layout.simple_list_item_1,  sensor));

        senSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        senAccelerometer = senSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        senSensorManager.registerListener(this, senAccelerometer , SensorManager.SENSOR_DELAY_NORMAL);

        tV = (TextView) findViewById(R.id.textView1);
        tVRekord = (TextView) findViewById(R.id.textViewRekord);
        tVAktuell = (TextView) findViewById(R.id.textViewAktuell);
    }

    @Override
    public void onSensorChanged(SensorEvent sensorEvent) {
        Sensor mySensor = sensorEvent.sensor;

        if (mySensor.getType() == Sensor.TYPE_ACCELEROMETER) {
            x = sensorEvent.values[0];
            y = sensorEvent.values[1];
            z = sensorEvent.values[2];
            summe = x + y + z;
            if(summe > rekord)
                rekord = summe;
            tV.setText("(x, y, z): "+ Float.toString(x) + ", " + Float.toString(y) + ", " + Float.toString(z) + " (x,y,z)");
            tVRekord.setText("Rekord: " + Float.toString(rekord));
            tVAktuell.setText("Beschleunigung: " + Float.toString(summe));
        }
    }

    public void onButtonClick(View v){
        rekord = 0;
        tVRekord.setText("Rekord: 0");
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    protected void onPause() {
        super.onPause();
        senSensorManager.unregisterListener(this);
    }
    protected void onResume() {
        super.onResume();
        senSensorManager.registerListener(this, senAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }


}
