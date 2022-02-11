 //LAB 11
 //NAME:P.THARAK
 //ROLLNO:CS20B1111

 import java.applet.Applet;
 import java.awt.Graphics;
 import java.awt.Color;
 public class tharak_applet extends Applet
 { 
     public void paint(Graphics g)
     {
        Color c= new Color(255,0,0);
        //Font f= new Font("Lucida Bright", Font.PLAIN, 32);

         g.drawOval(950,10,50,100);
         g.drawOval(960,25,29,70);
         g.setColor(Color.red);
         g.fillOval(960,25,30,70);
 
         g.setColor(Color.yellow);
         g.fillRect(10,600,150,100);
 
         g.setColor(Color.green);
         g.drawRect(35,620,100,60);
 
         g.setColor(Color.orange);
         g.fillOval(450,300,150,150);
 
         g.setColor(Color.black);
         g.drawString("P THARAK",480,375);
     }
 }
 /*
 <applet code="tharak_applet" width="1024" height="720">
 </applet>
 */