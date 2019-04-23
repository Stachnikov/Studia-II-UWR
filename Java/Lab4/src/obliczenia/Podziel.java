package obliczenia;

/**
 * Klasa reprezentujaca dzielenie (Wyrazenie w1) / (Wyrazenie w2)
 */
public class Podziel extends Operator2Arg {
    /**
     * Konstruktor klasy dzielenia
     * @param w1 Dzielna
     * @param w2 Dzielnik
     */
    public Podziel(Wyrazenie w1, Wyrazenie w2) {
        super(w1, w2);
    }

    @Override
    public double oblicz() {
        if(arg2.oblicz() == 0)
            try {
                throw new Exception("Dzielenie przez 0");
            } catch (Exception e) {
                e.printStackTrace();
            }
        return this.arg1.oblicz() / this.arg2.oblicz();
    }

    @Override
    public String toString() {
        return "(" + arg1 + " / " + arg2 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Podziel z = (Podziel) o;
        return this.oblicz() == z.oblicz();
    }

}
