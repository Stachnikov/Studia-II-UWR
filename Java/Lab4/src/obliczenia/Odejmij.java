package obliczenia;

/**
 *  Klasa reprezentujaca Odejmowanie (Wyrazenie a) - (Wyrazenie b)
 */
public class Odejmij extends Operator2Arg {
    /**
     * Konstruktor Odejmowania
     * @param w1 Wyrazenie 1
     * @param w2 Wyrazenie 2
     */
    public Odejmij(Wyrazenie w1, Wyrazenie w2){
        super(w1,w2);
    }

    @Override
    public double oblicz() {
        return this.arg1.oblicz() - this.arg2.oblicz();
    }

    @Override
    public String toString() {
        return "(" + arg1 + " - " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Odejmij z = (Odejmij) o;
        return this.oblicz() == z.oblicz();
    }
}