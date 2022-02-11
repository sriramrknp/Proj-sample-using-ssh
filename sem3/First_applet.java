// CS20B1107, CHEERLA SRIRAM REDDY

// Implementing java applets, with some shapes

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Color;


public class First_applet extends Applet
{
    public void paint(Graphics g){
        int width=100,height=100;
        Color c= new Color(255,0,0);
        Font f= new Font("Lucida Bright", Font.PLAIN, 32);
        g.setFont(f);
        g.setColor(c);

        // Oval, top right
        g.setColor(Color.blue);
        g.drawOval(820, 0, 2*width, height);
        g.setColor(Color.yellow);
        g.drawOval(870, 25, width, height/2);
        g.fillOval(870, 25, width, height/2);

        // Circle, middle
        g.setColor(Color.gray);
        g.fillOval(400, 200, 150, 150);
        g.setColor(Color.white);
        g.drawString("REDDY",420,280);

        // Rectangle, bottom left
        g.setColor(Color.green);
        g.drawRect(0,520, 3*width, 2*height);
        g.fillRect(0,520,3*width, 2*height);
        g.setColor(Color.red);
        g.drawRect(75,570, 150, 100);
    
    }
}
/*
<applet code="First_applet.class" width="1024" height="720"> 
</applet> 
*/