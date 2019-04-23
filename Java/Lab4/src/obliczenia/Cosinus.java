package obliczenia;

import static java.lang.Math.cos;

/**
 * Klasa reprezentujaca cosinus(Wyrazenie a)
 */
public class Cosinus extends Operator1Arg {

    /**
     * Konstruktor cosinusa
     * @param a Wyrazenie bedace parametrem cosinus
     */
    public Cosinus(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        return cos(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "cos(" + arg1 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Cosinus z = (Cosinus) o;
        return this.oblicz() == z.oblicz();
    }
}
