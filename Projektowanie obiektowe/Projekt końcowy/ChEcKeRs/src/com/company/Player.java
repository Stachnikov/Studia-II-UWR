package com.company;

public class Player {
    int id;    // 1 for Player One      2 for Player Two
    String name;    //Player choose his name in the menu
    boolean turn=false;     // true if its his turn
    int StoneColor;     // int of his Stone

    Player(int PId, String nam, int color){
        id=PId;
        name=nam;
        StoneColor=color;
    }

    boolean isTurn(int turn){
        if(turn == id)
            return true;
        else
            return false;
    }
}
