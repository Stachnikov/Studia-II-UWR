package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;

public class Board extends JPanel{

    //  PLAYERS

    Player player1 = new Player(1,"Gracz 1",1);
    Player player2 = new Player(2,"Gracz 2", 2);

    //FREE = MOVE IS POSSIBLY
    Player free = new Player(3,"free",3);
    //EMPTY = WHITE FIELDS
    Player empty = new Player(0,"empty",0);

    //ARRAY OF STONES [BOARD]
    Stones[][] Pionki = new Stones[8][8];

    //HELPING VARIABLE
    int left1 = 12;
    int left2 =12;
    int turn=2;
    boolean mademove1=false;
    boolean mademove2=false;
    long start=0;
    long stop=0;


    Board(String p1, String p2){
        super();
        start=System.currentTimeMillis();
        Mouse Listener = new Mouse();
        this.addMouseListener(Listener);
        player1.name=p1;
        player2.name=p2;
        SetBoard();
    }




    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        int size=80;
        Dimension d = new Dimension(8*size,8*size);
        setSize(8*size,8*size);
        setMinimumSize(d);
        setMaximumSize(d);
        this.setBackground(new Color(200,140,60));
        drawboard(g,size);
    }

    public void drawboard(Graphics g, int size){
        for(int y=0; y<8; y++){
            for(int x=0; x<8; x++){
                if ((x + y) % 2 != 0) {
                    g.setColor(Color.WHITE);
                    g.fillRect(x*80,y*80, size,size);
                } else {
                    g.setColor(Color.BLACK);
                    if(Pionki[y][x].getAttackmove() == 11 || Pionki[y][x].getAttackmove() == 111)
                        g.setColor(new Color(80,140,180));
                    if(Pionki[y][x].getAttackmove() == 22 || Pionki[y][x].getAttackmove() == 222)
                        g.setColor(new Color(220,170,0));
                    g.fillRect(x*80,y*80, size,size);
                }
            }
        }
        drawstones(g,size);
    }
    public void drawstones(Graphics g, int size){
        for(int y=0; y<8; y++){
            for(int x=0; x<8; x++){
                if ((x + y) % 2 != 0) {
                } else {

                    switch (Pionki[y][x].getBoard()/*board[y][x]*/) {
                        case 1: {
                            g.setColor(new Color(170, 0, 0));
                            g.fillOval(x * 80 + 5, y * 80 + 5, 68, 68);
                            g.setColor(Color.RED);
                            g.fillOval(x * 80 + 10, y * 80 + 5, 60, 60);
                            break;
                        }

                        case 2: {
                            g.setColor(Color.DARK_GRAY);
                            g.fillOval(x * 80 + 5, y * 80 + 5, 68, 68);
                            g.setColor(Color.GRAY);
                            g.fillOval(x * 80 + 10, y * 80 + 5, 60, 60);
                            break;
                        }

                        case 3: {
                            g.setColor(Color.BLACK);
                            if(Pionki[y][x].getAttackmove()/*attackmove[y][x]*/ == 1)
                                g.setColor(new Color(113,221,183));
                            if(Pionki[y][x].getAttackmove()/*attackmove[y][x]*/ == 2)
                                g.setColor(new Color(222,222,38));
                            g.fillRect(x*80,y*80, size,size);
                            break;
                        }

                        case 111: {
                            g.setColor(new Color(170, 0, 0));
                            g.fillOval(x * 80 + 5, y * 80 + 5, 68, 68);
                            g.setColor(Color.RED);
                            g.fillOval(x * 80 + 10, y * 80 + 5, 60, 60);

                            g.setColor(Color.PINK);
                            char[] Queen =new char[1];
                            Queen[0] = 'O';
                            g.setFont(g.getFont() .deriveFont((float) 50));
                            g.drawChars(Queen,0,Queen.length,x*80 +20,y*80 +55);
                            break;
                        }

                        case 222: {
                            g.setColor(Color.DARK_GRAY);
                            g.fillOval(x * 80 + 5, y * 80 + 5, 68, 68);
                            g.setColor(Color.GRAY);
                            g.fillOval(x * 80 + 10, y * 80 + 5, 60, 60);

                            g.setColor(Color.WHITE);
                            char[] Queen =new char[1];
                            Queen[0] = 'O';
                            g.setFont(g.getFont() .deriveFont((float) 50));
                            g.drawChars(Queen,0,Queen.length,x*80 +20,y*80 +55);
                            break;
                        }

                        case 0: {

                            break;
                        }
                    }
                }
            }
        }
    }

    public void SetBoard(){
        for(int y=0; y<8; y++){
            for(int x=0; x<8; x++){
                if ((x + y) % 2 != 0) {
                    Pionki[y][x] = new Stones(empty,0,0);
                } else {
                    if(y>4)
                        Pionki[y][x] = new Stones(player2,2,0);
                    else if(y<3)
                        Pionki[y][x] = new Stones(player1,1,0);
                    else
                        Pionki[y][x] = new Stones(free,3,0);
                }
            }
        }
    }

    public void move1(int x, int y){
        mademove1=false;
        if(Pionki[y][x].getBoard()/*board[y][x]*/ == 1){
            cleanHighlight();

            Pionki[y][x].setAttackmove(11);/*attackmove[y][x] = 11;*/
            if (y + 1 <= 7) {
                if (x + 1 <= 7 && Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 3)
                    Pionki[y + 1][x + 1].setAttackmove(1);/*attackmove[y + 1][x + 1] = 1;*/
                if (x - 1 >= 0 && Pionki[y + 1][x - 1].getBoard()/*board[y+1][x-1]*/ == 3)
                    Pionki[y + 1][x - 1].setAttackmove(1);/*attackmove[y + 1][x - 1] = 1;*/
            }

            if(y+2 <=7){
                if ( x+2 <=7 && Pionki[y+2][x+2].getBoard()/*board[y+2][x+2]*/ == 3 && (Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 2 || Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 222)) {
                    Pionki[y + 2][x + 2].setAttackmove(1);/*attackmove[y + 2][x + 2] = 1;*/
                    Pionki[y + 1][x + 1].setAttackmove(55);/*attackmove[y + 1][x+1] = 55;*/
                }
                if (x-2 >=0 && Pionki[y+2][x-2].getBoard()/*board[y+2][x-2]*/ == 3 && (Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 2 || Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 222)) {
                    Pionki[y+2][x-2].setAttackmove(1);/*attackmove[y + 2][x - 2] = 1;*/
                    Pionki[y+1][x-1].setAttackmove(55);/*attackmove[y + 1][x - 1] = 55;*/
                }
            }
        }
        else if(Pionki[y][x].getBoard() == 111){
            cleanHighlight();

            Pionki[y][x].setAttackmove(111);/*attackmove[y][x] = 11;*/
            if (y + 1 <= 7) {
                if (x + 1 <= 7 && Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 3)
                    Pionki[y + 1][x + 1].setAttackmove(1);/*attackmove[y + 1][x + 1] = 1;*/
                if (x - 1 >= 0 && Pionki[y + 1][x - 1].getBoard()/*board[y+1][x-1]*/ == 3)
                    Pionki[y + 1][x - 1].setAttackmove(1);/*attackmove[y + 1][x - 1] = 1;*/
            }

            if(y-1>=0){
                if ( x+1 <=7 && Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 3)
                    Pionki[y-1][x+1].setAttackmove(1);/*attackmove[y-1][x+1] = 2;*/
                if (x-1 >=0 && Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 3)
                    Pionki[y-1][x-1].setAttackmove(1);/*attackmove[y-1][x-1] = 2;*/
            }

            if(y-2 >=0){
                if ( x+2 <=7 && Pionki[y-2][x+2].getBoard()/*board[y-2][x+2]*/ == 3 && (Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 2 || Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 222)) {
                    Pionki[y-2][x+2].setAttackmove(1);/*attackmove[y - 2][x + 2] = 2;*/
                    Pionki[y-1][x+1].setAttackmove(55);/*attackmove[y - 1][x+1] = 44;*/
                }
                if (x-2 >=0 && Pionki[y-2][x-2].getBoard()/*board[y-2][x-2]*/ == 3 && (Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 2 ||Pionki[y-1][x-1].getBoard()/*board[y-1][x+1]*/ == 222)) {
                    Pionki[y-2][x-2].setAttackmove(1);/*attackmove[y - 2][x - 2] = 2;*/
                    Pionki[y-1][x-1].setAttackmove(55);/*attackmove[y - 1][x - 1] = 44;*/
                }
            }

            if(y+2 <=7){
                if ( x+2 <=7 && Pionki[y+2][x+2].getBoard()/*board[y+2][x+2]*/ == 3 && (Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 2 || Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 222)) {
                    Pionki[y + 2][x + 2].setAttackmove(1);/*attackmove[y + 2][x + 2] = 1;*/
                    Pionki[y + 1][x + 1].setAttackmove(55);/*attackmove[y + 1][x+1] = 55;*/
                }
                if (x-2 >=0 && Pionki[y+2][x-2].getBoard()/*board[y+2][x-2]*/ == 3 && (Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 2 || Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 222)) {
                    Pionki[y+2][x-2].setAttackmove(1);/*attackmove[y + 2][x - 2] = 1;*/
                    Pionki[y+1][x-1].setAttackmove(55);/*attackmove[y + 1][x - 1] = 55;*/
                }
            }
        }
        else if(Pionki[y][x].getAttackmove()/*attackmove[y][x]*/ == 1){
            for(int yy=0; yy<8; yy++)
            for(int xx=0; xx<8; xx++){
                if(Pionki[yy][xx].getAttackmove()/*attackmove[yy][xx]*/ == 11){
                    Pionki[y][x].setBoard(1);/*board[y][x]=1;*/
                    if(y == 7)
                        Pionki[y][x].setBoard(111);/*board[y][x]=111;*/
                    Pionki[yy][xx].setBoard(3);/*board[yy][xx]=3;*/
                    Pionki[yy][xx].setAttackmove(0);/*attackmove[yy][xx]=0;*/

                    if(y-1 >=0 && x-1 >=0 && Pionki[y-1][x-1].getAttackmove()/*attackmove[y-1][x-1]*/ == 55){
                        left1--;
                        Pionki[y-1][x-1].setBoard(3);/*board[y-1][x-1] = 3;*/
                        Pionki[y-1][x-1].setAttackmove(0);/*attackmove[y-1][x-1]=0;*/
                    }else if(y-1 >=0 && x+1 <=7 && Pionki[y-1][x+1].getAttackmove()/*attackmove[y-1][x+1]*/ == 55){
                        Pionki[y-1][x+1].setBoard(3);/*board[y-1][x+1] = 3;*/
                        Pionki[y-1][x+1].setAttackmove(0);/*attackmove[y-1][x+1]=0;*/
                        left1--;
                    }else if(y+1 <=7 && x-1 >=0 && Pionki[y+1][x-1].getAttackmove()/*attackmove[y+1][x-1]*/ == 55){
                        Pionki[y+1][x-1].setAttackmove(3);/*board[y+1][x-1] = 3;*/
                        Pionki[y+1][x-1].setAttackmove(0);/*attackmove[y+1][x-1]=0;*/
                        left1--;
                    }else if(y+1 <=7 && x+1 <=7 && Pionki[y+1][x+1].getAttackmove()/*attackmove[y+1][x+1]*/ == 55){
                        Pionki[y+1][x+1].setBoard(3);/*board[y+1][x+1] = 3;*/
                        Pionki[y+1][x+1].setAttackmove(0);/*attackmove[y+1][x+1]=0;*/
                        left1--;
                    }
                    mademove1 =true;
                }
                if(Pionki[yy][xx].getAttackmove()/*attackmove[yy][xx]*/ == 111){
                    Pionki[y][x].setBoard(111);/*board[y][x]=1;*/
                    Pionki[yy][xx].setBoard(3);/*board[yy][xx]=3;*/
                    Pionki[yy][xx].setAttackmove(0);/*attackmove[yy][xx]=0;*/

                    if(y-1 >=0 && x-1 >=0 && Pionki[y-1][x-1].getAttackmove()/*attackmove[y-1][x-1]*/ == 55){
                        Pionki[y-1][x-1].setBoard(3);/*board[y-1][x-1] = 3;*/
                        Pionki[y-1][x-1].setAttackmove(0);/*attackmove[y-1][x-1]=0;*/
                        left1--;
                    }else if(y-1 >=0 && x+1 <=7 && Pionki[y-1][x+1].getAttackmove()/*attackmove[y-1][x+1]*/ == 55){
                        Pionki[y-1][x+1].setBoard(3);/*board[y-1][x+1] = 3;*/
                        Pionki[y-1][x+1].setAttackmove(0);/*attackmove[y-1][x+1]=0;*/
                        left1--;
                    }else if(y+1 <=7 && x-1 >=0 && Pionki[y+1][x-1].getAttackmove()/*attackmove[y+1][x-1]*/ == 55){
                        Pionki[y+1][x-1].setBoard(3);/*board[y+1][x-1] = 3;*/
                        Pionki[y+1][x-1].setAttackmove(0);/*attackmove[y+1][x-1]=0;*/
                        left1--;
                    }else if(y+1 <=7 && x+1 <=7 && Pionki[y+1][x+1].getAttackmove()/*attackmove[y+1][x+1]*/ == 55){
                        Pionki[y+1][x+1].setBoard(3);/*board[y+1][x+1] = 3;*/
                        Pionki[y+1][x+1].setAttackmove(0);/*attackmove[y+1][x+1]=0;*/
                        left1--;
                    }
                    mademove1 =true;
                }
            }
        cleanHighlight();
        repaint();
        }
    }

    public void move2(int x, int y){
        mademove2=false;
        if(Pionki[y][x].getBoard()/*board[y][x]*/ == 2){
            cleanHighlight();

            Pionki[y][x].setAttackmove(22);/*attackmove[y][x] = 22;*/
            if(y-1>=0){
                if ( x+1 <=7 && Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 3)
                    Pionki[y-1][x+1].setAttackmove(2);/*attackmove[y-1][x+1] = 2;*/
                if (x-1 >=0 && Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 3)
                    Pionki[y-1][x-1].setAttackmove(2);/*attackmove[y-1][x-1] = 2;*/
            }

            if(y-2 >=0){
                if ( x+2 <=7 && Pionki[y-2][x+2].getBoard()/*board[y-2][x+2]*/ == 3 && (Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 1 || Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 111)) {
                    Pionki[y-2][x+2].setAttackmove(2);/*attackmove[y - 2][x + 2] = 2;*/
                    Pionki[y-1][x+1].setAttackmove(44);/*attackmove[y - 1][x+1] = 44;*/
                }
                if (x-2 >=0 && Pionki[y-2][x-2].getBoard()/*board[y-2][x-2]*/ == 3 && (Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 1 || Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 111)) {
                    Pionki[y-2][x-2].setAttackmove(2);/*attackmove[y - 2][x - 2] = 2;*/
                    Pionki[y-1][x-1].setAttackmove(44);/*attackmove[y - 1][x - 1] = 44;*/
                }
            }
        }
        else if(Pionki[y][x].getBoard() == 222){
            cleanHighlight();

            Pionki[y][x].setAttackmove(222);/*attackmove[y][x] = 11;*/
            if (y + 1 <= 7) {
                if (x + 1 <= 7 && Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 3)
                    Pionki[y + 1][x + 1].setAttackmove(2);/*attackmove[y + 1][x + 1] = 1;*/
                if (x - 1 >= 0 && Pionki[y + 1][x - 1].getBoard()/*board[y+1][x-1]*/ == 3)
                    Pionki[y + 1][x - 1].setAttackmove(2);/*attackmove[y + 1][x - 1] = 1;*/
            }

            if(y-1>=0){
                if ( x+1 <=7 && Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 3)
                    Pionki[y-1][x+1].setAttackmove(2);/*attackmove[y-1][x+1] = 2;*/
                if (x-1 >=0 && Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 3)
                    Pionki[y-1][x-1].setAttackmove(2);/*attackmove[y-1][x-1] = 2;*/
            }

            if(y-2 >=0){
                if ( x+2 <=7 && Pionki[y-2][x+2].getBoard()/*board[y-2][x+2]*/ == 3 && (Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 1 || Pionki[y-1][x+1].getBoard()/*board[y-1][x+1]*/ == 111)) {
                    Pionki[y-2][x+2].setAttackmove(2);/*attackmove[y - 2][x + 2] = 2;*/
                    Pionki[y-1][x+1].setAttackmove(44);/*attackmove[y - 1][x+1] = 44;*/
                }
                if (x-2 >=0 && Pionki[y-2][x-2].getBoard()/*board[y-2][x-2]*/ == 3 && (Pionki[y-1][x-1].getBoard()/*board[y-1][x-1]*/ == 1 ||Pionki[y-1][x-1].getBoard()/*board[y-1][x+1]*/ == 111)) {
                    Pionki[y-2][x-2].setAttackmove(2);/*attackmove[y - 2][x - 2] = 2;*/
                    Pionki[y-1][x-1].setAttackmove(44);/*attackmove[y - 1][x - 1] = 44;*/
                }
            }

            if(y+2 <=7){
                if ( x+2 <=7 && Pionki[y+2][x+2].getBoard()/*board[y+2][x+2]*/ == 3 && (Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 1 || Pionki[y+1][x+1].getBoard()/*board[y+1][x+1]*/ == 111)) {
                    Pionki[y + 2][x + 2].setAttackmove(2);/*attackmove[y + 2][x + 2] = 1;*/
                    Pionki[y + 1][x + 1].setAttackmove(44);/*attackmove[y + 1][x+1] = 55;*/
                }
                if (x-2 >=0 && Pionki[y+2][x-2].getBoard()/*board[y+2][x-2]*/ == 3 && (Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 1 || Pionki[y+1][x-1].getBoard()/*board[y+1][x-1]*/ == 111)) {
                    Pionki[y+2][x-2].setAttackmove(2);/*attackmove[y + 2][x - 2] = 1;*/
                    Pionki[y+1][x-1].setAttackmove(44);/*attackmove[y + 1][x - 1] = 55;*/
                }
            }
        }
        else if(Pionki[y][x].getAttackmove()/*attackmove[y][x]*/ == 2){
            for(int yy=0; yy<8; yy++)
                for(int xx=0; xx<8; xx++){
                    if(Pionki[yy][xx].getAttackmove()/*attackmove[yy][xx]*/ == 22){
                        Pionki[y][x].setBoard(2);/*board[y][x]=2;*/
                        if(y == 0)
                            Pionki[y][x].setBoard(222);/*board[y][x]=222;*/
                        Pionki[yy][xx].setBoard(3);/*board[yy][xx]=3;*/
                        Pionki[yy][xx].setAttackmove(0);/*attackmove[yy][xx]=0;*/

                        if(y-1 >=0 && x-1 >=0 && Pionki[y-1][x-1].getAttackmove()/*attackmove[y-1][x-1]*/ == 44){
                            Pionki[y-1][x-1].setBoard(3);/*board[y-1][x-1] = 3;*/
                            Pionki[y-1][x-1].setAttackmove(0);/*attackmove[y-1][x-1]=0;*/
                            left2--;
                        }else if(y-1 >=0 && x+1 <=7 && Pionki[y-1][x+1].getAttackmove()/*attackmove[y-1][x+1]*/ == 44){
                            Pionki[y-1][x+1].setBoard(3);/*board[y-1][x+1] = 3;*/
                            Pionki[y-1][x+1].setAttackmove(0);/*attackmove[y-1][x+1]=0;*/
                            left2--;
                        }else if(y+1 <=7 && x-1 >=0 && Pionki[y+1][x-1].getAttackmove()/*attackmove[y+1][x-1]*/ == 44){
                            Pionki[y+1][x-1].setBoard(3);/*board[y+1][x-1] = 3;*/
                            Pionki[y+1][x-1].setAttackmove(0);/*attackmove[y+1][x-1]=0;*/
                            left2--;
                        }else if(y+1 <=7 && x+1 <=7 && Pionki[y+1][x+1].getAttackmove()/*attackmove[y+1][x+1]*/ == 44){
                            Pionki[y+1][x+1].setBoard(3);/*board[y+1][x+1] = 3;*/
                            Pionki[y+1][x+1].setAttackmove(0);/*attackmove[y+1][x+1]=0;*/
                            left2--;
                        }
                        mademove2=true;
                    }
                    if(Pionki[yy][xx].getAttackmove()/*attackmove[yy][xx]*/ == 222){
                        Pionki[y][x].setBoard(222);/*board[y][x]=2;*/
                        Pionki[yy][xx].setBoard(3);/*board[yy][xx]=3;*/
                        Pionki[yy][xx].setAttackmove(0);/*attackmove[yy][xx]=0;*/

                        if(y-1 >=0 && x-1 >=0 && Pionki[y-1][x-1].getAttackmove()/*attackmove[y-1][x-1]*/ == 44){
                            Pionki[y-1][x-1].setBoard(3);/*board[y-1][x-1] = 3;*/
                            Pionki[y-1][x-1].setAttackmove(0);/*attackmove[y-1][x-1]=0;*/
                            left2--;
                        }else if(y-1 >=0 && x+1 <=7 && Pionki[y-1][x+1].getAttackmove()/*attackmove[y-1][x+1]*/ == 44){
                            Pionki[y-1][x+1].setBoard(3);/*board[y-1][x+1] = 3;*/
                            Pionki[y-1][x+1].setAttackmove(0);/*attackmove[y-1][x+1]=0;*/
                            left2--;
                        }else if(y+1 <=7 && x-1 >=0 && Pionki[y+1][x-1].getAttackmove()/*attackmove[y+1][x-1]*/ == 44){
                            Pionki[y+1][x-1].setBoard(3);/*board[y+1][x-1] = 3;*/
                            Pionki[y+1][x-1].setAttackmove(0);/*attackmove[y+1][x-1]=0;*/
                            left2--;
                        }else if(y+1 <=7 && x+1 <=7 && Pionki[y+1][x+1].getAttackmove()/*attackmove[y+1][x+1]*/ == 44){
                            Pionki[y+1][x+1].setBoard(3);/*board[y+1][x+1] = 3;*/
                            Pionki[y+1][x+1].setAttackmove(0);/*attackmove[y+1][x+1]=0;*/
                            left2--;
                        }
                        mademove2=true;
                    }
                }
                cleanHighlight();
            repaint();
        }
    }

    public void cleanHighlight(){
        for(int yy = 0; yy <8; yy++) {
            for (int xx = 0; xx < 8; xx++) {
                Pionki[yy][xx].setAttackmove(0);/*attackmove[yy][xx] = 0;*/
            }
        }
    }

    public void koniec(){
        if(left1 == 0 || left2 ==0){
            if(left1 == 0) {
                stop=currentTimeMillis();
                HowLong time = new HowLong(start,stop);
                long help = time.Matchtime()/1000;
                JOptionPane.showMessageDialog(null, "Wygrana!" + "\n" + "Brawo " + player1.name + "\n" + "Zajęło to: " + help + " sekund");
            }
            else {
                stop=currentTimeMillis();
                HowLong time = new HowLong(start,stop);
                long help = (time.Matchtime()/1000);
                JOptionPane.showMessageDialog(null, "Wygrana!" + "\n" + "Brawo " + player2.name + "\n" + "Zajęło to: " + help + " sekund");
            }
            exit(0);
        }
    }

    private class Mouse implements MouseListener{

        @Override
        public void mouseClicked(MouseEvent e) {
            int x = (e.getX()/80);
            int y = (e.getY()/80);

            //cleanHighlight();
            if(player2.isTurn(turn)) {
                //Player two move
                    move2(x, y);
                if(mademove2)
                    turn = 1;
            }
            else if(player1.isTurn(turn)) {
                //Player one move
                    move1(x, y);
                if(mademove1)
                    turn = 2;
            }

            koniec();
            repaint();
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }


}
