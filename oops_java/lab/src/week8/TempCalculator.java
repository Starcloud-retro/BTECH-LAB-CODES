package week8;

import java.awt.*;
import java.awt.event.*;

public class TempCalculator extends Frame implements ActionListener
{
    TextField display;
    Panel buttonPanel;
    String currentInput = "";
    double firstOperand = 0;
    String operator = "";

    public TempCalculator()
    {
        setTitle("A.W.T Calculator");
        setSize(300, 400);
        setLayout(new BorderLayout());

        // Display field
        display = new TextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 24));
        add(display, BorderLayout.NORTH);

        // Button panel with GridLayout
        buttonPanel = new Panel();
        buttonPanel.setLayout(new GridLayout(5, 4, 5, 5));

        // Button labels in your exact format
        String[] buttons =
        {
                "A/C","%","<-","/",
                "7", "8", "9", "*",
                "4", "5", "6", "-",
                "1", "2", "3", "+",
                "=", "0", ".", " "
        };

        for (String label : buttons)
        {
            if (!label.equals(" "))
            {
                Button b = new Button(label);
                b.setFont(new Font("Arial", Font.BOLD, 20));
                b.addActionListener(this);
                buttonPanel.add(b);
            }
            else
            {
                buttonPanel.add(new Label()); // Empty space filler
            }
        }

        add(buttonPanel, BorderLayout.CENTER);

        // Handle window close
        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent we)
            {
                dispose();
            }
        }
        );

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        String command = e.getActionCommand();

        if ("0123456789".contains(command))
        {
            currentInput += command;
            display.setText(currentInput);
        }
        else if (command.equals("."))
        {
            if (!currentInput.contains("."))
            {
                currentInput += ".";
                display.setText(currentInput);
            }
        }
        else if ("+-*/%".contains(command))
        {
            if (!currentInput.isEmpty())
            {
                firstOperand = Double.parseDouble(currentInput);
                operator = command;
                currentInput = "";
            }
        }
        else if (command.equals("="))
        {
            if (!currentInput.isEmpty() && !operator.isEmpty())
            {
                double secondOperand = Double.parseDouble(currentInput);
                double result = 0;

                switch (operator)
                {
                    case "+": result = firstOperand + secondOperand; break;
                    case "-": result = firstOperand - secondOperand; break;
                    case "*": result = firstOperand * secondOperand; break;
                    case "/": result = secondOperand != 0 ? firstOperand / secondOperand : 0; break;
                    case "%": result = firstOperand % secondOperand; break;
                }

                display.setText(String.valueOf(result));
                currentInput = "";
                operator = "";
            }
        }
        else if (command.equals("A/C"))
        {
            currentInput = "";
            firstOperand = 0;
            operator = "";
            display.setText("");
        }
        else if (command.equals("<-"))
        {
            if (!currentInput.isEmpty())
            {
                currentInput = currentInput.substring(0, currentInput.length() - 1);
                display.setText(currentInput);
            }
        }
    }

    public static void main(String[] args)
    {
        new TempCalculator();
    }
}