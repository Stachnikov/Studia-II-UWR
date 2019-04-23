package obliczenia;

import java.util.Hashtable;

/**
 * Klasa reprezentujaca stala liczbowa
 */
public class Stala extends Wyrazenie {
    /**
     * Nazwa wlasna stalej
     */
    String nazwa;
    /**
     * Tablica w ktorej przechowujemy stale liczbowe i klucz czyli ich nazwe
     */
    private final static Hashtable<String,Double> tab = new Hashtable<String,Double>(){
            {
                put("π", 3.1415926535897932384);
                put("e", 0.5772156649015328606);
                put("ϕ", 1.6180339887498948482);
            }
    };

    /**
     * Konstruktor Stalej
     * @param n nazwa stalej ktora chcielibysmy uzyc
     * @throws Exception kiedy w naszej bazie danych nie mamy takiej stalej
     */
    public Stala(String n) throws Exception {
        if(tab.get(n)!= null){
            nazwa=n;
        }
        else
            throw new Exception("Nie ma takiej stalej...");
    }

    @Override
    public double oblicz(){
        return tab.get(nazwa);
    }

    @Override
    public String toString() {
        return nazwa;
    }

    @Override
    public boolean equals(Object o) {
        Stala z = (Stala) o;
        return this.oblicz() == z.oblicz();
    }
}
