package com.company;

public class Stones {
    private Player Owner;   //      Player
    private boolean turn=false;   //      false = it is not his turn  true = it is his turn
    private boolean queen; //     false = normal stone         true = queen
    private int board;
    private int attackmove;


    Stones(Player p, int color, int attack){
        Owner=p;
        board=color;
        attackmove=attack;
    }

    int getBoard(){
        return board;
    }

    int getAttackmove(){
        return attackmove;
    }

    void setAttackmove(int attack){
        attackmove=attack;
    }

    void setBoard(int place){
        board=place;
    }

}
