package obliczenia;

import static java.lang.Math.abs;

/**
 * Klasa reprezentujaca wartosc bezwzgledna (Wyrazenie a)
 */
public class WartBezw extends Operator1Arg {

    /**
     * Konstruktor wartosci bezwzglednej
     * @param a Wyrazenie
     */
    public WartBezw(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        return abs(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "|" + arg1 + "|";
    }

    @Override
    public boolean equals(Object o) {
        WartBezw z = (WartBezw) o;
        return this.oblicz() == z.oblicz();
    }
}
