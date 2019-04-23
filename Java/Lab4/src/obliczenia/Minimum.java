package obliczenia;

import static java.lang.Double.min;

/**
 * Klasa reprezentujaca min {(Wyrazenie a) , (Wyrazenie b) }
 */
public class Minimum extends  Operator2Arg {

    /**
     * Konstruktor minimum
     * @param a Wyrazenie pierwsze
     * @param b Wyrazenie drugie
     */
    public Minimum(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }

    @Override
    public double oblicz() {
        return min(arg1.oblicz(),arg2.oblicz());
    }

    @Override
    public String toString() {
        return "min(" + arg1 + ", " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Minimum z = (Minimum) o;
        return this.oblicz() == z.oblicz();
    }
}
