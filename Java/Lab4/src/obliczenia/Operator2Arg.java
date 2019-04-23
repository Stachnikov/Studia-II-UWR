package obliczenia;

/**
 * Klasa reprezentujaca operator dwu argumentowy bedaca podstawa dla operacji wymagajacej dwoch argumentow
 */
public abstract class Operator2Arg extends Operator1Arg {
    /**
     * Wyrazenie bedace drugim argumentem operacji
     */
    protected final Wyrazenie arg2;

    /**
     * Konstruktor Operatora2Arg
     * @param a1 pierwszy argument
     * @param a2 drugi argument
     */
    public Operator2Arg (Wyrazenie a1, Wyrazenie a2) {
        super(a1);
        if (a2==null) throw new IllegalArgumentException();
        arg2 = a2;
    }

}
