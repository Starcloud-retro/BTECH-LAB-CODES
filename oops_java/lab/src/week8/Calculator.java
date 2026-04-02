package week8;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener
{

    JTextField display;
    String input = "";

    Calculator()
    {
        setTitle("Calculator");
        setSize(345, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Use JTextField instead of AWT TextField
        display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 25));
        add(display, BorderLayout.NORTH);

        // Use JPanel instead of AWT Panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));

        String[] buttons = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        for (String label : buttons) {
            JButton b = new JButton(label);
            b.setFont(new Font("Arial", Font.BOLD, 20));
            b.addActionListener(this);
            buttonPanel.add(b);
        }

        add(buttonPanel, BorderLayout.CENTER);
        setVisible(true); // Call after adding all components
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Handle button actions here
        String command = e.getActionCommand();

        if(command.equalsIgnoreCase("C")) {
            input = "";
        }
        else if (command.equals("=")) {
            try {
                double result = evaluate(input);
                input = String.valueOf(result);
            } catch (Exception exc) {
                display.setText("Error");
            }
        }
        else {
            input += command;
        }
        display.setText(input);
    }

    public double evaluate(String exp) {
        String[] tokens = exp.split("(?<=[-+*/])|(?=[-+*/])");
        double result = Double.parseDouble(tokens[0]);

        for(int i=1;i<tokens.length;i+=2)
        {
            String operator = tokens[i];
            Double num = Double.parseDouble(tokens[i+1]);

            switch (operator)
            {
                case "+" -> result += num;
                case "-" -> result -= num;
                case "*" -> result *= num;
                case "/" -> result /= num;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        new Calculator();
    }
}