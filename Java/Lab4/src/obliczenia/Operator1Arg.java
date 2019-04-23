package obliczenia;

/**
 * Klasa reprezentujaca Operator 1 Argumentowy bedaca podstawa dla operacji w ktorych jest potrzebny jeden argument
 */
public abstract class Operator1Arg extends Wyrazenie {
    /**
     * Wyrazenie bedace pierwszym argumentem operacji
     */
    protected final Wyrazenie arg1;

    /**
     * Konstruktor Operatora1Arg
     * @param a1 Wyrazenie pierwsze
     */
    public Operator1Arg (Wyrazenie a1) {
        if (a1==null) throw new IllegalArgumentException();
        arg1 = a1;
    }

}
