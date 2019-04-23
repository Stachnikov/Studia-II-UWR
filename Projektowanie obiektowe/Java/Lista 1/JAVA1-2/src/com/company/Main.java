package com.company;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Hashtable<String, Integer> Drzewo = new Hashtable<>();
        Drzewo.put("x",5);
        System.out.println("x = " + Drzewo.get("x"));
        Drzewo.put("y",10);
        System.out.println("y = " + Drzewo.get("y"));

        Wyrazenie wyr = new Odejmij(new Stala(15),new Zmienna("x",Drzewo));
        System.out.println(wyr.toString() + " = " + wyr.oblicz());
        wyr = new Pomnoz(new Stala(12),wyr);
        System.out.println(wyr.toString() + " = " + wyr.oblicz());
        wyr = new Podziel(wyr,new Zmienna("y",Drzewo));
        System.out.println(wyr.toString() + " = " + wyr.oblicz());
        wyr = new Dodaj(wyr,new Stala(2));
        System.out.println(wyr.toString() + " = " + wyr.oblicz());
    }
}
