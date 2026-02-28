package practice;

import java.awt.*;
import java.awt.event.*;


public class Form extends Frame
{
    Form()
    {
        setTitle("STUDENT REGISTRATION");
        setSize(360,460);
        setLayout(null);
        setVisible(true);

        Label l1 = new Label("Student Name:");
        l1.setBounds(20,40,100, 25);
        add(l1);

        TextField t1 = new TextField();
        t1.setBounds(130, 40, 180, 25);
        add(t1);

        Label l2 = new Label("Student Roll No.:");
        l2.setBounds(20, 80, 100, 25);
        add(l2);

        TextField t2 = new TextField();
        t2.setBounds(130, 80, 180, 25);
        add(t2);

        Label l3 = new Label("Address:");
        l3.setBounds(20, 120, 100, 25);
        add(l3);

        TextArea t3 = new TextArea();
        t3.setBounds(130, 120, 180, 60);
        add(t3);

        Label l4 = new Label("Select Languages Known:");
        l4.setBounds(20, 200, 150, 25);
        add(l4);

        Checkbox c1 = new Checkbox("English");
        c1.setBounds(180, 200, 215, 25);
        add(c1);
        Checkbox c2 = new Checkbox("Hindi");
        c2.setBounds(180, 220, 215, 25);
        add(c2);
        Checkbox c3 = new Checkbox("Telugu");
        c3.setBounds(180, 240, 215, 25);
        add(c3);
        Checkbox c4 = new Checkbox("ALL");
        c4.setBounds(180, 260, 215, 25);
        add(c4);

        Label l5 = new Label("Select Gender:");
        l5.setBounds(20, 300, 150, 25);
        add(l5);

        CheckboxGroup cg1 = new CheckboxGroup();

        Checkbox cb1 = new Checkbox("Male", cg1 ,false);
        cb1.setBounds(180, 300, 215, 25);
        add(cb1);
        Checkbox cb2 = new Checkbox("Female", cg1 ,false);
        cb2.setBounds(180, 320, 215, 25);
        add(cb2);
        Checkbox cb3 = new Checkbox("Others", cg1 ,false);
        cb3.setBounds(180, 340, 215, 25);
        add(cb3);

        Button b1 = new Button("Submit");
        b1.setBounds(40, 380, 100, 25);
        add(b1);

        Button b2 = new Button("Cancel");
        b2.setBounds(220, 380, 100, 25);
        add(b2);


        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                dispose();
            }
        });
    }
    @SuppressWarnings("unused")
    public static void main(String [] args)
    {
        Form f = new Form();
    }
}
