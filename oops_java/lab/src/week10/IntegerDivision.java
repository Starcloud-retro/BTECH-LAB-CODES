package week10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class IntegerDivision extends JFrame
{

    IntegerDivision(){
        setTitle("IntegerDivision");
        setSize(300,200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(4,2));

        JLabel l1 = new JLabel("Num1");
        l1.setFont(new Font("Arial",Font.BOLD,20));
        JTextField t1 = new JTextField();
        JLabel l2 = new JLabel("Num2");
        l2.setFont(new Font("Arial",Font.BOLD,20));
        JTextField t2 = new JTextField();

        JLabel l3 = new JLabel("result");
        l3.setFont(new Font("Arial",Font.BOLD,20));
        JTextField t3 = new JTextField();
        t3.setEditable(false);

        JButton b =  new JButton("DIVIDE");
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e)
            {

                try {
                    int num1 = Integer.parseInt(t1.getText());
                    int num2 = Integer.parseInt(t2.getText());

                    if(num2 == 0) {
                        throw new ArithmeticException("Cannot Divide by Zero");
                    }

                    int result = num1/num2;
                    t3.setText(String.valueOf(result));
                }
                catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Please enter a numeric value");
                }
                catch (ArithmeticException ex) {
                    JOptionPane.showMessageDialog(null, "Divide by Zero is not Possible");
                }
            }
        });

        add(l1);add(t1);
        add(l2);add(t2);
        add(l3);add(t3);
        add(b);

        setVisible(true);
    }

    public static void main(String[] args){
        new IntegerDivision();
    }
}