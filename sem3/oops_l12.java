// Name: CS20B1107, CHEERLA SRIRAM REDDY
// Date: 07/11/2021
//   Calculator program implemented with event handling in java
//   (java applets)

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class oops_l12 extends Applet implements ActionListener,KeyListener
{
    Button b9,b8,b7, b6,b5,b4, b3,b2,b1, b0,bdot,bclear,bplus,bequal,bdiv,bmul,bmin;
    Button b[]=new Button[17];
    TextField tf;
    String num1="";
    String num2="";
    String Op="";

    public void init()
    {
        tf=new TextField();  
        tf.setBounds(100,40,300,60);  

        
        b9=new Button("9");
        b9.setBounds(100,120,60,50);
        b8=new Button("8");
        b8.setBounds(160,120,60,50);  
        b7=new Button("7");  
        b7.setBounds(220,120,60,50);
        bdiv = new Button("/");
        bdiv.setBounds(280, 120, 60, 50);

        b6=new Button("6");
        b6.setBounds(100,170,60,50);
        b5=new Button("5");
        b5.setBounds(160,170,60,50);
        b4=new Button("4");
        b4.setBounds(220,170,60,50);
        bmul = new Button("*");
        bmul.setBounds(280, 170, 60, 50);

        b3=new Button("3");  
        b3.setBounds(100,220,60,50);
        b2=new Button("2");  
        b2.setBounds(160,220,60,50);
        b1=new Button("1");  
        b1.setBounds(220,220,60,50);
        bmin = new Button("-");
        bmin.setBounds(280, 220, 60, 50);

        b0=new Button("0");  
        b0.setBounds(100,270,60,50);
        bdot=new Button(".");  
        bdot.setBounds(160,270,60,50);
        bclear=new Button("C");  
        bclear.setBounds(220,270,60,50);
        bplus = new Button("+");
        bplus.setBounds(280, 270, 60, 50);
        bequal=new Button("=");  
        bequal.setBounds(340,270,60,50);
       
        add(b9);
        add(b8);
        add(b7);
        add(bdiv);

        add(b6);
        add(b5);
        add(b4);
        add(bmul);
        
        add(b3);
        add(b2);
        add(b1);
        add(bmin);
        
        add(b0);
        add(bdot);
        add(bclear);
        add(bplus);
        add(bequal);

        add(tf);  

        b9.addActionListener(this);
        b8.addActionListener(this);
        b7.addActionListener(this);
        bdiv.addActionListener(this);

        b6.addActionListener(this);  
        b5.addActionListener(this);
        b4.addActionListener(this);
        bmul.addActionListener(this);

        b3.addActionListener(this);
        b2.addActionListener(this);
        b1.addActionListener(this);
        bmin.addActionListener(this);

        b0.addActionListener(this);
        bdot.addActionListener(this);
        bclear.addActionListener(this);
        bplus.addActionListener(this); 
        bequal.addActionListener(this);   

        b9.addKeyListener(this);
        b8.addKeyListener(this);  
        b7.addKeyListener(this);
        bdiv.addKeyListener(this);
        
        b6.addKeyListener(this);
        b5.addKeyListener(this);
        b4.addKeyListener(this);
        bmul.addKeyListener(this);

        b3.addKeyListener(this);
        b2.addKeyListener(this);
        b1.addKeyListener(this);
        bmin.addKeyListener(this);

        b0.addKeyListener(this);
        bdot.addKeyListener(this);
        bclear.addKeyListener(this);
        bplus.addKeyListener(this);  
        bequal.addKeyListener(this);

        tf.addKeyListener(this); 
    
        setLayout(null);  
    }

    public void keyTyped(KeyEvent e) 
    { 
            //
    }  
    public void keyReleased(KeyEvent e) 
    { 
                //
    }  
    public void keyPressed(KeyEvent e) 
    { 
        //
    }

    public void actionPerformed(ActionEvent e)
    {
	    String button = e.getActionCommand();
        char ch = button.charAt(0);
	    if(ch>='0' && ch<='9'|| ch=='.') 
	    { 
	        if (!Op.equals("")) 
		        num2 = num2 + button; 
	        else
		        num1 = num1 + button;   
	        tf.setText(num1+Op+num2); 
	    } 
	    else if(ch=='C') 
	    { 
	        num1 = Op = num2 = ""; 
	        tf.setText(""); 
	    }
	    else if (ch =='=') 
	    { 
	        if(!num1.equals("") && !num2.equals(""))
	        {
		    double temp;
		    double n1=Double.parseDouble(num1);
		    double n2=Double.parseDouble(num2);
		    if(n2==0 && Op.equals("/"))
		    {
		        tf.setText(num1+Op+num2+" = Zero Division Error");
		        num1 = Op = num2 = "";
		    }
		    else
	 	    {
		        if (Op.equals("+")) 
		            temp = n1 + n2; 
		        else if (Op.equals("-")) 
		            temp = n1 - n2;
		        else if (Op.equals("/")) 
	  	            temp = n1/n2; 
		        else
		            temp = n1*n2; 
		        tf.setText(num1+Op+num2+" = "+temp); 
		        num1 = Double.toString(temp);
		        Op = num2 = ""; 
	        }
            }
	        else
	        {
		    num1 = Op = num2 = ""; 
		    tf.setText("");
	        }
        } 
	else 
	{ 
	    if (Op.equals("") || num2.equals("")) 
		Op = button; 
	    else 
	    { 
		double temp;
		double n1=Double.parseDouble(num1);
		double n2=Double.parseDouble(num2);
		if(n2==0 && Op.equals("/"))
		{
		    tf.setText(num1+Op+num2+" = Zero Division Error");
		    num1 = Op = num2 = "";
		}
		else
		{
		    if (Op.equals("+")) 
		        temp = n1 + n2; 
		    else if (Op.equals("-")) 
		        temp = n1 - n2; 
		    else if (Op.equals("/")) 
	  	        temp = n1/n2; 
		    else
		        temp = n1*n2; 
		    num1 = Double.toString(temp); 
		    Op = button; 
		    num2 = ""; 
	        }
            }
	    tf.setText(num1+Op+num2);
        }
    }
}

/* 
<applet code="oops_l12.class" width="800" height="600"> 
</applet> 
*/  
