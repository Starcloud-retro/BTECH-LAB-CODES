package guiPractice;

import java.awt.*;
import javax.swing.*;

public class SwingGui
{
    public static void main(String [] args)
    {

        //NO LAYOUT!
        JFrame fNOBORDER = new JFrame("Frame0 - NO BORDER");
        fNOBORDER.setTitle("STUDENT FORM");
        fNOBORDER.setSize(500,500);
        fNOBORDER.setLayout(null);
        fNOBORDER.setVisible(true);

        //Multiple Buttons Selections
        JLabel l4 = new JLabel("Select Languages Known:");
        l4.setBounds(20, 200, 150, 25);
        l4.setForeground(Color.BLUE);
        fNOBORDER.add(l4);

        JCheckBox c1 = new JCheckBox("English");
        c1.setBounds(180, 200, 215, 25);
        fNOBORDER.add(c1);
        JCheckBox c2 = new JCheckBox("Hindi");
        c2.setBounds(180, 220, 215, 25);
        fNOBORDER.add(c2);
        JCheckBox c3 = new JCheckBox("Telugu");
        c3.setBounds(180, 240, 215, 25);
        fNOBORDER.add(c3);
        JCheckBox c4 = new JCheckBox("ALL");
        c4.setBounds(180, 260, 215, 25);
        fNOBORDER.add(c4);
        //RADIO BUTTONS
        JLabel l5 = new JLabel("Select Gender:");
        l5.setBounds(20, 300, 150, 25);
        l5.setForeground(Color.BLUE);
        fNOBORDER.add(l5);

        ButtonGroup gGroup = new ButtonGroup();
        JRadioButton rb1 = new JRadioButton("Male");
        rb1.setBounds(180, 300, 215, 25);
        gGroup.add(rb1);
        JRadioButton rb2 = new JRadioButton("Female");
        rb2.setBounds(180, 320, 215, 25);
        gGroup.add(rb2);
        JRadioButton rb3 = new JRadioButton("Others");
        rb3.setBounds(180, 340, 215, 25);
        gGroup.add(rb3);

        fNOBORDER.add(rb1);
        fNOBORDER.add(rb2);
        fNOBORDER.add(rb3);

        //DROPDOWN
        Label l6 = new Label("Select the Programming Languages known: ");
        l6.setBounds(20, 380, 235, 25);
        l6.setForeground(Color.BLUE);
        fNOBORDER.add(l6);

        Choice ch1 = new Choice();
        ch1.setBounds(270, 380, 150,25);
        ch1.add("C");
        ch1.add("C++");
        ch1.add("Python");
        ch1.add("CSS");

        fNOBORDER.add(ch1);



        //BORDER LAY0UT
        JFrame fBORDER = new JFrame("Frame1 - BORDER");
        fBORDER.setTitle("STUDENT REGISTRATION");
        fBORDER.setSize(500, 560);
        fBORDER.setLayout(new BorderLayout());
        fBORDER.setVisible(true);
        fBORDER.setBackground(Color.LIGHT_GRAY);

        fBORDER.add(new JButton("CENTER"), BorderLayout.CENTER);
        fBORDER.add(new JButton("NORTH"), BorderLayout.NORTH);
        fBORDER.add(new JButton("SOUTH"), BorderLayout.SOUTH);
        fBORDER.add(new JButton("EAST"), BorderLayout.EAST);
        fBORDER.add(new JButton("WEST"), BorderLayout.WEST);


        //GRID LAYOUT - CALCULATOR
        JFrame fGRID = new JFrame("Frame2 - GRID");
        fGRID.setTitle("CALCULATOR");
        fGRID.setSize(345, 500);
        fGRID.setLayout(new GridLayout(5,4));
        fGRID.setVisible(true);
        fGRID.setBackground(Color.ORANGE);

        fGRID.add(new JTextField());
        fGRID.add(new JTextField());
        fGRID.add(new JTextField());
        fGRID.add(new JTextField());
        fGRID.add(new JButton("1"));
        fGRID.add(new JButton("2"));
        fGRID.add(new JButton("+"));
        fGRID.add(new JButton("3"));
        fGRID.add(new JButton("4"));
        fGRID.add(new JButton("-"));
        fGRID.add(new JButton("5"));
        fGRID.add(new JButton("6"));
        fGRID.add(new JButton("*"));
        fGRID.add(new JButton("7"));
        fGRID.add(new JButton("8"));
        fGRID.add(new JButton("/"));
        fGRID.add(new JButton("9"));
        fGRID.add(new JButton("0"));
        fGRID.add(new JButton("%"));
        fGRID.add(new JButton("="));

//        JLabel l1 = new JLabel("CALCULATOR");
//        l1.setForeground(Color.ORANGE);
//        fGRID.add(l1);


        // FLOW LAYOUT
//        JFrame fFLOW = new JFrame("FLOW LAYOUT");
//        fFLOW.setSize(500,500);
//        fFLOW.setVisible(true);
//        fFLOW.setBackground(Color.BLUE);
//        fFLOW.setLayout(new FlowLayout(FlowLayout.RIGHT, 10, 15));
//
//        fFLOW.add(new JButton("JAVA"));

        JFrame f1 = new JFrame("CENTER");
        f1.setLayout(new FlowLayout(FlowLayout.CENTER));
        f1.setSize(200, 100);
        f1.add(new JButton("A"));
        f1.add(new JButton("B"));
        f1.setVisible(true);

        JFrame f2 = new JFrame("LEFT");
        f2.setLayout(new FlowLayout(FlowLayout.LEFT));
        f2.setSize(200, 100);
        f2.add(new JButton("C"));
        f2.add(new JButton("D"));
        f2.setVisible(true);

        JFrame f3 = new JFrame("RIGHT");
        f3.setLayout(new FlowLayout(FlowLayout.RIGHT));
        f3.setSize(200, 100);
        f3.add(new JButton("E"));
        f3.add(new JButton("F"));
        f3.setVisible(true);

    }

}
