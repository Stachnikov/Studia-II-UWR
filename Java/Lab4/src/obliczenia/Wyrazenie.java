package obliczenia;

/**
 * Klasa bedaca klasa bazowa dla wszystkich wyrazen
 */
public abstract class Wyrazenie implements Obliczalny {
// ...

    /**
     * Metoda sumujaca wyrazenia
     * @param wyr lista Wyrazen
     * @return suma wszystkich wyrazen na liscie wyr
     */
    public static double suma (Wyrazenie...wyr) {
        double sum = 0;

        for (Wyrazenie wyrazN : wyr) {
            sum += wyrazN.oblicz();
        }

        return sum;
    }
    /**
     * Metoda mnozaca wyrażenia
     * @param wyr lista Wyrazen
     * @return iloczyn wszystkich wyrazen na liscie wyr
     */
    public static double iloczyn (Wyrazenie...wyr) {
        double ilocz = 1;

        for (Wyrazenie wyrazN : wyr) {
            ilocz *= wyrazN.oblicz();
        }

        return ilocz;
    }
}
