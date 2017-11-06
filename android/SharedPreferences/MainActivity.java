package de.savrasov.android.exercise42;

import android.content.Context;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import static java.lang.Boolean.FALSE;

public class MainActivity extends AppCompatActivity {


    public static final String MyPREFERENCES = "MyPrefs";
    public static final String Name = "nameKey";
    public static final String Phone = "phoneKey";
    public static final String Email = "emailKey";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final SharedPreferences sharedpreferences;
        final EditText ed1 = (EditText) findViewById(R.id.editText);
        final CheckBox cb1 = (CheckBox) findViewById(R.id.checkBox);
        final ToggleButton t1 = (ToggleButton) findViewById(R.id.toggleButton);
        final Button bt1 = (Button) findViewById(R.id.bt1);
        final Button bt2 = (Button) findViewById(R.id.bt2);
        sharedpreferences = getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);

        bt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String eT = ed1.getText().toString();
                Boolean cB = cb1.isChecked();
                Boolean tB = t1.isChecked();

                SharedPreferences.Editor editor = sharedpreferences.edit();

                editor.putString("editText", eT);
                editor.putBoolean("checkBox", cB);
                editor.putBoolean("toogleButton", tB);
                editor.commit();
                Toast.makeText(MainActivity.this, "Save", Toast.LENGTH_LONG).show();
            }
        });

        bt2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String eT = sharedpreferences.getString("editText", "");
                Boolean cB = sharedpreferences.getBoolean("checkBox", FALSE);
                Boolean tB = sharedpreferences.getBoolean("toogleButton", FALSE);
                ed1.setText(eT);
                cb1.setChecked(cB);
                t1.setChecked(tB);
                Toast.makeText(MainActivity.this, "Load", Toast.LENGTH_LONG).show();
            }
        });
    }
}
