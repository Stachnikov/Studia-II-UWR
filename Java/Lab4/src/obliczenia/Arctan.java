package obliczenia;


import javafx.scene.shape.Arc;

import static java.lang.Math.atan;

/**
 *  Klasa reprezentujaca Arctan
 */
public class Arctan extends Operator1Arg {
    /**
     * Konstruktor wyrazenia arctan
     * @param a Wyrazenie bedace argumentem funkcji arctan
     */
    public Arctan(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        return atan(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "arctan(" + arg1 + ")";
    }

    @Override
    public boolean equals(Object o) {
        Arctan z = (Arctan) o;
        return this.oblicz() == z.oblicz();
    }
}
