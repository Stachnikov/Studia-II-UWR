package obliczenia;

import static java.lang.Math.sin;

/**
 * Klasa reprezentujaca sinus (Wyrazenie a)
 */
public class Sinus extends Operator1Arg{
    /**
     * Konstruktor sinus(a)
     * @param a argument sinusa
     */
    public Sinus(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        return sin(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "sin(" + arg1 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Sinus z = (Sinus) o;
        return this.oblicz() == z.oblicz();
    }
}
