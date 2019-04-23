package obliczenia;

import static java.lang.Math.pow;

/**
 * Klasa reprezentujaca (Wyrazenie a) do potegi (Wyrazenie b)
 */
public class Potega extends Operator2Arg { //POTEGA w1^w2

    /**
     * Konstruktor potegowania
     * @param w1 Argument 1
     * @param w2 Argument 2
     */
    public Potega(Wyrazenie w1, Wyrazenie w2){
       super(w1,w2);
    }

    @Override
    public double oblicz() {
        return pow(arg1.oblicz(),arg2.oblicz());
    }

    @Override
    public String toString() {
        return "(" + arg1 + "^(" + arg2 + "))";
    }

    @Override
    public boolean equals(Object o) {
        Potega z = (Potega) o;
        return this.oblicz() == z.oblicz();
    }
}
