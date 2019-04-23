package com.company;

public class Pomnoz extends Wyrazenie {

    Wyrazenie w1;
    Wyrazenie w2;

    Pomnoz(Wyrazenie w1, Wyrazenie w2){
        this.w1=w1;
        this.w2=w2;
    }

    @Override
    public int oblicz() {
        return this.w1.oblicz() * this.w2.oblicz();
    }

    @Override
    public String toString() {
        return "(" + w1 + " * " + w2 + ")";
    }

}
