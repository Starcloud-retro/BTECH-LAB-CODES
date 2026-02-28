package week9;

import java.awt.*;
import java.awt.event.*;

public class MouseEventDemo extends Frame implements MouseListener
{
    Label mainLabel;
    Label eventLabel;

    public MouseEventDemo()
    {
        setTitle("Mouse Event Demo");
        setSize(400, 300);
        setLayout(new BorderLayout());

        // Label that listens for mouse events
        mainLabel = new Label("Java is an OOP", Label.CENTER);
        mainLabel.setFont(new Font("Arial", Font.BOLD, 20));
        mainLabel.addMouseListener(this);
        add(mainLabel, BorderLayout.NORTH);

        // Label to show the event name
        eventLabel = new Label("", Label.CENTER);
        eventLabel.setFont(new Font("Arial", Font.PLAIN, 18));
        add(eventLabel, BorderLayout.CENTER);

        // Window close handler
        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent we)
            {
                dispose();
            }
        });

        setVisible(true);
    }

    // MouseListener methods
    public void mouseClicked(MouseEvent e) {
        eventLabel.setText("Mouse Clicked");
    }

    public void mousePressed(MouseEvent e) {
        eventLabel.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        eventLabel.setText("Mouse Released");
    }

    public void mouseEntered(MouseEvent e) {
        eventLabel.setText("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) {
        eventLabel.setText("Mouse Exited");
    }

    public static void main(String[] args) {
        new MouseEventDemo();
    }
}