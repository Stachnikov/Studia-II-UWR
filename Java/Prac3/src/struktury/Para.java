package struktury;

/**
 * Klasa reprezentujaca Pare (String klucz, Double wartosc)
 */
public class Para {

    /**
     *  klucz do kodowania pary
     */
    public final String klucz;

    private double wartosc;

    /**
     * Konstruktor pary
     * @param key klucz pary
     * @param val wartosc przechowywana
     */
    public Para(String key,double val) {
        klucz = key;
        wartosc=val;
    }

    /**
     * Getter do pola wartosc
     * @return wartosc typu double
     */
    public double getwartosc(){
        return wartosc;
    }

    /**
     * Setter pola wartosc
     * @param val wartosc jaką chcemy ustawic
     */
    public void setwartosc(double val){
        wartosc=val;
    }

    /**
     * Wypisuje w przyjazny sposób nasza reprezentacje pary
     * @return String bedacy reprezentacja pary
     */
    public String toString(){
        StringBuilder str = new StringBuilder("( Wartosc = ");
        str.append(wartosc);
        str.append(" , klucz = ");
        str.append(klucz);
        str.append(" )");
        return str.toString();
    }

    /**
     * Czy para jest rowna parze p2
     * @param p2 para do ktorej chcemy porwnac nasza pare
     * @return boolean zaleznosci czy pary są sobie rowne(true) czy nie(false)
     */
    public boolean equals(Para p2){
        return this.klucz.equals(p2.klucz);
    }
}

