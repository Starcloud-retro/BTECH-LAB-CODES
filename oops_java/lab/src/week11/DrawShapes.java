//11b
package week11;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DrawShapes extends JFrame
{
    enum ShapeType { LINE, RECTANGLE, OVAL }
    private ShapeType currentShape = ShapeType.LINE;
    private Point startPoint = null;
    private Point endPoint = null;

    public DrawShapes()
    {
        setTitle("Draw Shapes");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        DrawPanel canvas = new DrawPanel();
        add(canvas, BorderLayout.CENTER);

        JPanel controls = new JPanel();
        JButton lineBtn = new JButton("Line");
        JButton rectBtn = new JButton("Rectangle");
        JButton ovalBtn = new JButton("Oval");

        lineBtn.addActionListener(e -> currentShape = ShapeType.LINE);
        rectBtn.addActionListener(e -> currentShape = ShapeType.RECTANGLE);
        ovalBtn.addActionListener(e -> currentShape = ShapeType.OVAL);

        controls.add(lineBtn);
        controls.add(rectBtn);
        controls.add(ovalBtn);
        add(controls, BorderLayout.NORTH);

        canvas.addMouseListener(new MouseAdapter()
        {
            public void mousePressed(MouseEvent e)
            {
                startPoint = e.getPoint();
            }

            public void mouseReleased(MouseEvent e)
            {
                endPoint = e.getPoint();
                canvas.repaint();
            }
        });

        setVisible(true);
    }

    class DrawPanel extends JPanel
    {
        protected void paintComponent(Graphics g)
        {
            super.paintComponent(g);
            if (startPoint != null && endPoint != null)
            {
                int x = Math.min(startPoint.x, endPoint.x);
                int y = Math.min(startPoint.y, endPoint.y);
                int width = Math.abs(startPoint.x - endPoint.x);
                int height = Math.abs(startPoint.y - endPoint.y);

                switch (currentShape)
                {
                    case LINE:
                        g.drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
                        break;
                    case RECTANGLE:
                        g.drawRect(x, y, width, height);
                        break;
                    case OVAL:
                        g.drawOval(x, y, width, height);
                        break;
                }
            }
        }
    }

    public static void main(String[] args)
    {
        new DrawShapes();
    }
}