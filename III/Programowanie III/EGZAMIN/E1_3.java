import javax.swing.*;
import java.awt.*;

class Shape extends JPanel {
    @Override
    public void paint(Graphics g) {
        setSize(200, 200);
        g.drawRect(25, 25, 150, 150);
        g.drawLine(25, 25, 175, 175);
        g.drawLine(25, 175, 175, 25);
    }
}

public class E1_3 {
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setSize(225, 250);
        Shape ShapePanel = new Shape();
        frame.add(ShapePanel);
        frame.getContentPane().setBackground(Color.YELLOW);
        frame.setVisible(true);
    }
}