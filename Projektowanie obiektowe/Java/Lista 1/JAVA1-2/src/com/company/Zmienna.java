package com.company;
import java.util.*;

public class Zmienna extends Wyrazenie{

    String s;
    Hashtable<String, Integer> Drzewo;

    public Zmienna(String s,Hashtable<String, Integer> Drzewo){
        this.s=s;
        this.Drzewo=Drzewo;
    }

    @Override
    public int oblicz() {
        return Drzewo.get(s);
    }

    @Override
    public String toString() {
        return  s;
    }
}
