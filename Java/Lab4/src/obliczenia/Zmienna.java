package obliczenia;

import java.util.Hashtable;

/**
 * Klasa reprezentujaca zmienna liczbowa
 */
public class Zmienna extends Wyrazenie{
    /**
     * Nazwa zmiennej liczbowej
     */
    String s;
    /**
     * Tablica posiadajaca nazwe zmiennej i jej wartosc
     */
    final static Hashtable<String, Double> tab = new Hashtable<String, Double>();

    /**
     * Konstruktor zmiennej
     * @param klucz nazwa zmiennej
     */
    public Zmienna(String klucz){
        this.s=klucz;
        tab.put(s,0.0);
    }

    /**
     * Metoda ustawiajaca wartosc danej zmiennej
     * @param klucz nazwa zmiennej ktorej wartosc chcemy ustawic
     * @param wart wartosc jaka chcemy nadac
     */
    public static void ustaw(String klucz, double wart){
        tab.replace(klucz,wart);
    }

    @Override
    public double oblicz() {
        return tab.get(s);
    }

    @Override
    public String toString() {
        return  s;
    }

    @Override
    public boolean equals(Object o) {
        Zmienna z = (Zmienna) o;
        return this.oblicz() == z.oblicz();
    }
}
