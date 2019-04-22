package com.company;


import javax.swing.*;

public class Game extends JFrame {

    Game(String p1, String p2){
        super("Checkers");
        setSize(660,700);
        Box box = new Box(BoxLayout.Y_AXIS);
        Board CheckersBoard = new Board(p1,p2);
        box.add(CheckersBoard);
        JLabel credits = new JLabel("MADE BY Mikołaj Stachnik");
        box.add(credits);
        add(box);
        setMaximumSize(getMinimumSize());
        setMinimumSize(getMinimumSize());
        setPreferredSize(getPreferredSize());

        setResizable(false);
        setVisible(true);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

}
