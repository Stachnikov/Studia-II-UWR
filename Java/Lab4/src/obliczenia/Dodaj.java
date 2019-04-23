package obliczenia;

/**
 * Klasa reprezentujaca dodawanie dwoch wyrazen
 */
public class Dodaj extends Operator2Arg {
    /**
     * Konstruktor dodawania dwoch wyrazen
     * @param w1 wyrazenie pierwsze sumy
     * @param w2 wyrazenie drugie sumy
     */
    public Dodaj(Wyrazenie w1, Wyrazenie w2){
        super(w1,w2);
    }

    @Override
    public double oblicz() {
        return this.arg1.oblicz() + this.arg2.oblicz();
    }

    @Override
    public String toString() {
        return "(" + arg1 + " + " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Dodaj z = (Dodaj) o;
        return this.oblicz() == z.oblicz();
    }

}
