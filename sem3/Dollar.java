//ROLLNO:CS20B1111
//NAME:P.Tharak
//Simple calculator using applets

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class Dollar extends Applet implements ActionListener, TextListener
{
    Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,dollar,AED,pound;
    TextField tf1,tf2;
    public void init()
    {
        Frame title = (Frame) this.getParent().getParent();
        title.setTitle("Converter");
        setLayout(null);
        tf1 = new TextField();
        tf1.setBounds(350,100,220,25);
        add(tf1);
        tf2 = new TextField();
        tf2.setBounds(350,130,220,25);
        add(tf2);
        b1=new Button("1");
        b1.setBounds(350,160,50,50);
        b1.setBackground(Color.yellow);
        b1.setForeground(Color.black);
        add(b1);
        b2=new Button("2");
        b2.setBounds(405,160,50,50);
        b2.setBackground(Color.yellow);
        b2.setForeground(Color.black);
        add(b2);
        b3=new Button("3");
        b3.setBounds(460,160,50,50);
        b3.setBackground(Color.yellow);
        b3.setForeground(Color.black);
        add(b3);
        b4=new Button("4");
        b4.setBounds(350,215,50,50);
        b4.setBackground(Color.yellow);
        b4.setForeground(Color.black);
        add(b4);
        b5=new Button("5");
        b5.setBounds(405,215,50,50);
        b5.setBackground(Color.yellow);
        b5.setForeground(Color.black);
        add(b5);
        b6=new Button("6");
        b6.setBounds(460,215,50,50);
        b6.setBackground(Color.yellow);
        b6.setForeground(Color.black);
        add(b6);
        b7=new Button("7");
        b7.setBounds(350,270,50,50);
        b7.setBackground(Color.yellow);
        b7.setForeground(Color.black);
        add(b7);
        b8=new Button("8");
        b8.setBounds(405,270,50,50);
        b8.setBackground(Color.yellow);
        b8.setForeground(Color.black);
        add(b8);
        b9=new Button("9");
        b9.setBounds(460,270,50,50);
        b9.setBackground(Color.yellow);
        b9.setForeground(Color.black);
        add(b9);
        b0=new Button("0");
        b0.setBounds(405,325,50,50);
        b0.setBackground(Color.yellow);
        b0.setForeground(Color.black);
        add(b0);
        dollar = new Button("Dollars");
        dollar.setBounds(190,80,60,15);
        add(dollar);
        AED = new Button("aed");
        AED.setBounds(50,80,60,20);
        add(AED);
        pound = new Button("Pounds");
        pound.setBounds(120,80,60,18);
        add(pound);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b0.addActionListener(this);
        dollar.addActionListener(this);
        AED.addActionListener(this);
        pound.addActionListener(this);
    }

    public void paint(Graphics g) 
    {
        g.setColor(Color.green);
        g.fillRect(310,70,300,330);
        g.setColor(Color.black);
        g.drawRect(310,70,300,330);
    }

    public void actionPerformed(ActionEvent ae)
    {
        String st=ae.getActionCommand();
        String s1;
        if(st.equals("0") || st.equals("1") || st.equals("2") || st.equals("3") || st.equals("4") || st.equals("5") || st.equals("6") || st.equals("7") || st.equals("8") || st.equals("9") || st.equals("0"))
        {
            s1=tf1.getText()+st;
            tf1.setText(s1);
        }
        if(st.equals("dollar"))
        {
           double d=Double.parseDouble(tf1.getText());
           //converting rupees to dollar
           double d1=(d/74);
           String s2=String.valueOf(d1);
           tf2.setText(s2);

        }
        if(st.equals("AED"))
        {
           double a=Double.parseDouble(tf1.getText());
           //converting rupees to AED
           double a1=(a/20);
           String s3=String.valueOf(a1);
           tf2.setText(s3);
        }
        if(st.equals("pound"))
        {
            double b=Double.parseDouble(tf1.getText());
            //converting rupees to pounds
            double b1=(b/100);
            String s4=String.valueOf(b1);
            tf2.setText(s4);
        }
        
    }

    public void textValueChanged(TextEvent e)
    {

    }
}
/*
<applet code="Dollar.class" width="1024" height="720">
</applet>
*/