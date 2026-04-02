package week8;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("unused")
public class OrgCalculator
{
    public OrgCalculator()
    {
        //GRID LAYOUT - CALCULATOR
//        JFrame fGRID = new JFrame("Frame2 - GRID");
//        fGRID.setTitle("CALCULATOR");
//        fGRID.setSize(600, 500);
//        fGRID.setLayout(new GridLayout(5,4));
//        fGRID.setVisible(true);
//        fGRID.setBackground(Color.ORANGE);
//
//        fGRID.add(new JTextField());
//        fGRID.add(new JTextField());
//        fGRID.add(new JTextField());
//        fGRID.add(new JTextField());
//        fGRID.add(new JButton("1"));
//        fGRID.add(new JButton("2"));
//        fGRID.add(new JButton("+"));
//        fGRID.add(new JButton("3"));
//        fGRID.add(new JButton("4"));
//        fGRID.add(new JButton("-"));
//        fGRID.add(new JButton("5"));
//        fGRID.add(new JButton("6"));
//        fGRID.add(new JButton("*"));
//        fGRID.add(new JButton("7"));
//        fGRID.add(new JButton("8"));
//        fGRID.add(new JButton("/"));
//        fGRID.add(new JButton("9"));
//        fGRID.add(new JButton("0"));
//        fGRID.add(new JButton("%"));
//        fGRID.add(new JButton("="));

        Frame fGRID = new Frame("Frame1 - GRID");
        fGRID.setTitle("CALCULATOR");
        fGRID.setSize(500, 600);
        fGRID.setLayout(new GridLayout(6,3));
        fGRID.setVisible(true);
        //fGRID.setBackground(Color.ORANGE);

        TextField t1 = new TextField();
        TextField t2 = new TextField();
        TextField t3 = new TextField();
        TextField t4 = new TextField();

        fGRID.add(t1);
        fGRID.add(t2);
        fGRID.add(t3);
        //fGRID.add(t4);

        Button b1 = new Button("1");
        Button b2 = new Button("2");
        Button b3 = new Button("+");
        Button b4 = new Button("3");
        Button b5 = new Button("4");
        Button b6 = new Button("-");
        Button b7 = new Button("5");
        Button b8 = new Button("6");
        Button b9 = new Button("*");
        Button b10 = new Button("7");
        Button b11 = new Button("8");
        Button b12 = new Button("/");
        Button b13 = new Button("9");
        Button b14 = new Button("0");
        Button b15 = new Button("=");
        Button b16 = new Button("%");

        fGRID.add(b1);
        fGRID.add(b2);
        fGRID.add(b3);
        fGRID.add(b4);
        fGRID.add(b5);
        fGRID.add(b6);
        fGRID.add(b7);
        fGRID.add(b8);
        fGRID.add(b9);
        fGRID.add(b10);
        fGRID.add(b11);
        fGRID.add(b12);
        fGRID.add(b13);
        fGRID.add(b14);
        fGRID.add(b15);
        fGRID.add(b16);

        fGRID.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent we)
            {
                System.exit(0);
            }
        });
    }

    public static void main(String [] args)
    {
        new OrgCalculator();
    }
}
