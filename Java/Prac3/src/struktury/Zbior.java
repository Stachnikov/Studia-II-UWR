package struktury;

/**
 * Abstrakcyjna klasa, ktora bedzie przechowywac rozne pary
 * Klasa bazowa dla klas imlementujacych zbiory.
 */
public abstract class Zbior {
    /**
     * Tablica par ktora reprezentujemy zbior
     */
    Para[] pary;


    /**
     * Metoda szukajaca pary o podanym kluczu i zwracajaca te pare
     * @param k klucz pary
     * @return Para zawierajaca podany klucz
     * @throws Exception gdy zbior jest pusty
     */
    public abstract Para szukaj (String k) throws Exception;
    /**
     * Metoda ma wstawiac do zbioru nowa pare
     * @param p Para ktora chcemy wstawic
     * @throws Exception gdy nie ma miejsca w zbiorze aby wstawic nowa pare lub klucz nowej pary jest taki sam jak jednej z istniejących
     */
    public abstract void wstaw (Para p) throws Exception;
    /**
     * Metoda ma odszukac pare i zwrocic wartosc zwiazana z kluczem
     * @param k klucz pary ktorej wartosc chcemy odczytac
     * @return wartosc przechowywana w parze z podanym kluczem
     * @throws Exception gdy nie ma takiej pary
     */
    public abstract double czytaj (String k) throws Exception;
    /**
     * Bezpieczne wstawianie, jezeli istnieje para o podanym kluczu nadpisuje ja, w przeciwnym przypadku wstawia za pomoca funkcji wstaw
     * @param p Para ktora chcemy wstawic do zbioru
     * @throws Exception gdy nie ma miejsca by wstawic
     */
    public abstract void ustaw (Para p) throws Exception;
    /**
     * Metoda usuwa wszystkie pary ze zbioru
     */
    public abstract void czysc ();
    /**
     * Metoda zwracajaca ilosc elementow w zbiorze
     * @return wartosc int ile jest elementow w zbiorze
     */
    public abstract int ile ();
}