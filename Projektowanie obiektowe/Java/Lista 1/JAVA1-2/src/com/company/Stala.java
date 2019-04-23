package com.company;

public class Stala extends Wyrazenie {
    int wartosc;

    Stala(int war){
        this.wartosc=war;
    }

    @Override
    public int oblicz(){
        return wartosc;
    }

    @Override
    public String toString() {
        return Integer.toString(wartosc);
    }
}
