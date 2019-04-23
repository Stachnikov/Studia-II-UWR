package obliczenia;

/**
 * Klasa reprezentujaca odwrotnosc wyrazenia
 */
public class Odwrotnosc extends Operator1Arg {

    /**
     * Konstruktor odwrotnosci
     * @param a wyrazenie
     */
    public Odwrotnosc(Wyrazenie a){
        super(a);
    }

    @Override
    public double oblicz() {
        if(arg1.oblicz() == 0)
            try {
                throw new Exception("Nie ma odwrotnosc zera");
            } catch (Exception e) {
                e.printStackTrace();
            }

        return 1.0/(arg1.oblicz());
    }

    @Override
    public String toString() {
        return "(1.0/(" + arg1 + "))";
    }

    @Override
    public boolean equals(Object o) {
        Odwrotnosc z = (Odwrotnosc) o;
        return this.oblicz() == z.oblicz();
    }

}
