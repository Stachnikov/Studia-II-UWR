package struktury;

/**
 * Klasa bedaca rozszerzeniem klasy ZbiorNaTablicy reprezentujaca zbior na tablicy dynamicznej
 */
public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy{

    /**
     * Konstruktor Zbioru na tablicy dynamicznej
     * @throws Exception nie wystapi poniewaz 2 nie wywola Exception w konstruktorze ZbiorNaTablicy
     */
    public ZbiorNaTablicyDynamicznej() throws Exception{
        super(2);
    }

    /**
     * metoda ma wstawiac do zbioru nowa pare
     * @param p Para ktora chcemy wstawic
     * @throws Exception gdy podamy pare o tym samym kluczu
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
            if(i>=dl){
                dl *= 2;
                Para[] tmp = new Para[dl];
                System.arraycopy(pary, 0, tmp, 0, i);
                tmp[i] = p;
                pary = tmp;
            }
            else
                pary[i]=p;
    }

    /**
     * Bezpieczne wstawianie, jezeli istnieje para o podanym kluczu nadpisuje ja, w przeciwnym przypadku wstawia za pomoca funkcji wstaw
     * @param p Para ktora chcemy wstawic do zbioru
     * @throws Exception gdy nie uda się wstawic
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
     * Metoda przywraca bazowy rozmiar zbioru przy tym usuwajac wszystkie elementy
     */
    @Override
    public void czysc() {
        pary = new Para[2];
    }
}
