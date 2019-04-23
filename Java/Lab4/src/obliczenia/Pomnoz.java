package obliczenia;

/**
 * Klasa reprezentujaca mnozenie (Wyrazenie w1) * (Wyrazenie w2)
 */
public class Pomnoz extends Operator2Arg {

    /**
     * Konstruktor mnozenia
     * @param w1 Argument 1
     * @param w2 Argument 2
     */
    public Pomnoz(Wyrazenie w1, Wyrazenie w2){
     super(w1,w2);
    }

    @Override
    public double oblicz() {
        return this.arg1.oblicz() * this.arg2.oblicz();
    }

    @Override
    public String toString() {
        return "(" + arg1 + " * " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Pomnoz z = (Pomnoz) o;
        return this.oblicz() == z.oblicz();
    }

}
