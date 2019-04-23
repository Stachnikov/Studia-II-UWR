package struktury;

/**
 * Klasa bedaca rozszerzeniem klasy Zbior reprezentujaca zbior na tablicy statycznej
 */
public class ZbiorNaTablicy extends Zbior{


    /**
     * Konstruktor zbioru na tablicy statycznej
     * @param rozmiar wielkosc int musi byc wieksza niz 1
     * @throws Exception gdy rozmiar jest mniejszy od 2
     */
    public ZbiorNaTablicy(int rozmiar) throws Exception{
        if(rozmiar >=2)
            pary = new Para[rozmiar];
        else
            throw new Exception("Zbyt mały rozmiar tablicy...");
    }

    /**
     * Metoda szukajaca pary o podanym kluczu i zwracajaca te pare
     * @param k klucz pary
     * @return Para zawierajaca podany klucz
     * @throws Exception gdy nie ma szukanej pary
     */
    @Override
    public Para szukaj(String k) throws Exception{
        if(pary[0] != null) {
            for (Para p : pary) {
                if (p.klucz.equals(k)) {
                    return p;
                }
            }
        }
        throw new Exception("Nie znaleziono pary...");
    }

    /**
     * Metoda ma wstawiac do zbioru nowa pare
     * @param p Para ktora chcemy wstawic
     * @throws Exception gdy nie ma miejsca w zbiorze aby wstawic nowa pare lub klucz nowej pary jest taki sam jak jednej z istniejących
     */
    @Override
    public void wstaw(Para p) throws Exception {

        for (int i= 0; i<pary.length; i++) {
            if(pary[i] != null)
            {
                if(p.klucz.equals(pary[i].klucz))
                    throw new Exception("Nie można wstawić pary o tym samym kluczu...");
            }
        }

            int i =0;
            int dl = ile();
            while(i<dl && pary[i] != null){
                i++;
            }
            if(i>=dl)
                throw new Exception("NIE MA MIEJSCA NA NOWY ELEMENT...");
            else
                pary[i]=p;
    }

    /**
     * metoda ma odszukac pare i zwrocic wartosc zwiazana z kluczem
     * @param k klucz pary ktorej wartosc chcemy odczytac
     * @return wartosc przechowywana w parze z podanym kluczem
     * @throws Exception gdy nie ma takiej pary
     */
    @Override
    public double czytaj(String k) throws Exception {
        try{
            //double czytana = szukaj(k).getwartosc();
            return szukaj(k).getwartosc();
        }catch(Exception e){
            throw new Exception("Nie ma pary o podanym kluczu...");
        }
    }

    /**
     * Bezpieczne wstawianie, jezeli istnieje para o podanym kluczu nadpisuje ja, w przeciwnym przypadku wstawia za pomoca funkcji wstaw
     * @param p Para ktora chcemy wstawic do zbioru
     * @throws Exception gdy nie ma miejsca by wstawic
     */
    @Override
    public void ustaw(Para p) throws Exception {
        boolean check =false;
        for (int i= 0; i<pary.length; i++) {
            if(pary[i] != null)
            {
                if(p.klucz.equals(pary[i].klucz)) {
                    pary[i].setwartosc(p.getwartosc());
                    check=true;
                }
            }
        }
        if (!check)
            wstaw(p);
    }

    /**
     * Metoda usuwa wszystkie pary ze zbioru
     */
    @Override
    public void czysc() {
        for (int i = 0; i< ile(); i++){
            pary[i] = null;
        }
    }

    /**
     * Metoda zwracajaca ilosc elementow w zbiorze
     * @return wartosc int ile jest elementow w zbiorze
     */
    @Override
    public int ile() {
        return pary.length;
    }

    /**
     *  Wypisuje w przyjazny sposob nasza reprezentacje zbioru
     * @return String bedacy reprezentacja zbioru
     */
    public String toString(){
        StringBuilder str = new StringBuilder("Zbior :\n");
        int i = 0;
        for (Para x:pary) {
            str.append(i).append(". ").append(x).append("\n");
            i++;
        }
        return str.toString();
    }
}

