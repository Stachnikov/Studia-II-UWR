package com.company;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Menu extends JFrame {

    JPanel part = new JPanel();
    JLabel title = new JLabel();
    JPanel containerD = new JPanel();
    JPanel containerU = new JPanel();
    JPanel left = new JPanel();
    public JTextField Player1_name  = new JTextField("GRACZ 1");
    public JTextField Player2_name  = new JTextField("GRACZ 2");
    JPanel menu = new JPanel();
    JPanel right = new JPanel();
    JButton newGame = new JButton();
    JButton help = new JButton();
    JButton exit = new JButton();
    BoxLayout bLayout0 = new BoxLayout(containerD,0);
    BoxLayout bLayout1 = new BoxLayout(part,1);

    Menu(){
        super("CHECKERS");
        setSize(640,640);
        setResizable(false);
        setLocationByPlatform(true);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        part.setBackground(new Color(179,127,35));
        containerU.setBackground(new Color(179,127,35));

        left.add(Player1_name);
        right.add(Player2_name);
        BufferedImage img;
        {
            try {
                img = ImageIO.read(new File("C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//Title.png"));
                ImageIcon icon=new ImageIcon(img);
                title.setIcon(icon);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        {
            try {
                img = ImageIO.read(new File("C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//NG.png"));
                ImageIcon icon=new ImageIcon(img);
                newGame.setIcon(icon);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        {
            try {
                img = ImageIO.read(new File("C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//EXIT.png"));
                ImageIcon icon=new ImageIcon(img);
                exit.setIcon(icon);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        {
            try {
                img = ImageIO.read(new File("C://Users//Dell//Desktop//ChEcKeRs//out//production//ChEcKeRs//com//company//HELP.png"));
                ImageIcon icon=new ImageIcon(img);
                help.setIcon(icon);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        containerU.setLayout(new BoxLayout(containerU,0));
        containerU.add(left);
        containerU.add(title);
        containerU.add(right);

        part.setLayout(bLayout1);
        part.add(containerU);
        part.add(containerD);

        menu.setLayout(new BoxLayout(menu,1));
        containerD.setBackground(new Color(180,150,70));
        GAME NG = new GAME();
        HELP H = new HELP();
        EXIT E = new EXIT();
        newGame.setBorder(null);
        newGame.addActionListener(NG);
        help.setBorder(null);
        help.addActionListener(H);
        exit.setBorder(null);
        exit.addActionListener(E);
        menu.add(newGame);
        menu.add(help);
        menu.add(exit);

        containerD.setLayout(bLayout0);
        containerD.add(left);
        containerD.add(menu);
        containerD.add(right);
        left.setBackground(new Color(179,127,35));
        right.setBackground(new Color(179,127,35));
        add(part);
        setVisible(true);
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        new Menu();

    }

    public void close(){
        WindowEvent winclose = new WindowEvent(this, WindowEvent.WINDOW_CLOSING);
        Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winclose);
    }

    private class GAME implements ActionListener

    {
        @Override
        public void actionPerformed(ActionEvent e) {

            String p1 = Player1_name.getText();
            String p2 = Player2_name.getText();
            close();
            new Game(p1, p2);
        }
    }

    private class HELP implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e) {
                new Instructions();
        }
    }


    private class EXIT implements ActionListener

    {
        @Override
        public void actionPerformed(ActionEvent e) {
                System.exit(0);
        }
    }
}
