package obliczenia;

import static java.lang.Double.max;

/**
 * Klasa reprezentujaca max {(Wyrazenie a) , (Wyrazenie b) }
 */
public class Maximum extends Operator2Arg{
    /**
     * Konstruktor maksimum
     * @param a Wyrazenie pierwsze
     * @param b Wyrazenie drugie
     */
    public Maximum(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }

    @Override
    public double oblicz() {
        return max(arg1.oblicz(),arg2.oblicz());
    }

    @Override
    public String toString() {
        return "max(" + arg1 + ", " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Maximum z = (Maximum) o;
        return this.oblicz() == z.oblicz();
    }
}
