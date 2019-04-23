package obliczenia;

/**
 * Klasa reprezentujaca liczbe
 */
public class Liczb extends Wyrazenie{
    private double wartosc;

    /**
     * Konstruktor liczby
     * @param war wartosc liczby
     */
    public Liczb(double war){
        wartosc=war;
    }
    @Override
    public double oblicz() {
        return wartosc;
    }

    @Override
    public String toString() {
        return String.valueOf(wartosc);
    }

    @Override
    public boolean equals(Object o) {
        Liczb z = (Liczb) o;
        return this.oblicz() == z.oblicz();
    }
}
