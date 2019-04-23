package obliczenia;

import static java.lang.Math.log;

/**
 * Klasa reprezentujaca logarytm o podstawie (Wyrazenie a) z (Wyrazenie b)
 */
public class Log extends Operator2Arg { //logw1 w2
    /**
     * Konstruktor logarytmu
     * @param a podstawa logarytmu
     * @param b wyrazenie logarytmowane
     */
    public Log(Wyrazenie a, Wyrazenie b){
        super(a,b);
    }

    @Override
    public double oblicz() {
        if ((arg2.oblicz() <= 0) || arg1.oblicz() == 1 || arg1.oblicz() <= 0)
            throw new IllegalArgumentException();

        return log(arg2.oblicz())/log(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "log(" + arg1 + ")(" + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Log z = (Log) o;
        return this.oblicz() == z.oblicz();
    }
}
