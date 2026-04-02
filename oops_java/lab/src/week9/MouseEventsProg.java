package week9;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MouseEventsProg extends Frame
{
    public MouseEventsProg()
    {
        Label l1 = new Label("Java is an OOP");
        l1.setBounds(150, 150, 500, 100);
        add(l1);
        setSize(500, 500);
        setLayout(null);
        setVisible(true);
        l1.setFont(new Font("Arial", Font.BOLD, 18));
        l1.addMouseListener(new MouseListener()
        {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                System.out.println("Mouse is Clicked");
            }

            @Override
            public void mousePressed(MouseEvent e)
            {
                System.out.println("Mouse is Pressed");
            }

            @Override
            public void mouseReleased(MouseEvent e)
            {
                System.out.println("Mouse is Released");
            }

            @Override
            public void mouseEntered(MouseEvent e)
            {
                System.out.println("Mouse is on the Text");
            }

            @Override
            public void mouseExited(MouseEvent e)
            {
                System.out.println("Mouse is out of the Text");
            }
        });

        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                dispose();
            }
        });

    }

    public static void main(String [] args)
    {
        new MouseEventsProg();
    }
}