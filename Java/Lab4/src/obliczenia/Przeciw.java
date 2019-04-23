package obliczenia;

/**
 * Klasa reprezentujaca liczbe przeciwna do (Wyrazenie a)
 */
public class Przeciw extends Operator1Arg {

    /**
     * Konstruktor przeciwienstwa
     * @param a Wyrazenie ktorego przeciwienstwo chcemy otrzymac
     */
    public Przeciw(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        return (-arg1.oblicz());
    }

    @Override
    public String toString() {
        return "(-)(" + arg1 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Przeciw z = (Przeciw) o;
        return this.oblicz() == z.oblicz();
    }
}
