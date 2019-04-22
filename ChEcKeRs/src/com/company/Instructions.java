package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;

public class Instructions extends JFrame{

    int x = 1;
    String[] INFO_TO_DISPLAY = {
            "C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//INFO1.png",
            "C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//INFO2.png",
            "C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//INFO3.png",
            "C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//INFO4.png"
    };
    JPanel p = new JPanel();
    JLabel pic = new JLabel();
    JButton go = new JButton("NEXT");

    Instructions() {
        super("How to play");
        setSize(720, 720);
        setMaximumSize(getMinimumSize());
        setMinimumSize(getMinimumSize());
        setPreferredSize(getPreferredSize());

        Box box = new Box(1);
        box.add(go);
        box.add(pic);
        pic.setBounds(0,0,640,640);
        Set_Image(0);

        Next next = new Next();
        go.addActionListener(next);
        //add(pic);
        //add(go);
        add(box);
        setResizable(false);
        setVisible(true);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }

    public void Set_Image(int i){
        ImageIcon icon = new ImageIcon(INFO_TO_DISPLAY[i]);
        Image img = icon.getImage();
        Image newimg = img.getScaledInstance(pic.getWidth(),pic.getHeight(),Image.SCALE_SMOOTH);
        ImageIcon newImg = new ImageIcon(newimg);
        pic.setIcon(newImg);
    }

    private class Next implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(x == 4){
                close();
            }
            else{
                Set_Image(x);
                x += 1;
            }
        }
    }

    public void close(){
        WindowEvent winclose = new WindowEvent(this, WindowEvent.WINDOW_CLOSING);
        Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winclose);
    }
}
