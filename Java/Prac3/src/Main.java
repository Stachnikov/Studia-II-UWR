import struktury.Para;
import struktury.ZbiorNaTablicy;
import struktury.ZbiorNaTablicyDynamicznej;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        System.out.println("Co chcesz stworzyć? :\n" +
                "1. Zbiór na tablicy\n" +
                "2. Zbiór na tablicy dynamicznej\n" +
                "...");
        int komend;
        Scanner S = new Scanner(System.in);
        komend = S.nextInt();
        switch (komend){
            case 1 : {
                System.out.println("Podaj rozmiar zbioru: ");
                ZbiorNaTablicy tab = new ZbiorNaTablicy(S.nextInt());
                int i = 1;
                while (i != -1) {
                    System.out.println("Co chcesz zrobić? :\n" +
                            "1. Wstaw parę\n" +
                            "2. Ustaw parę\n" +
                            "3. Szukaj pary\n" +
                            "4. Czytaj parę\n" +
                            "5. Wyczysć zbiór\n" +
                            "6. Wyswietl rozmiar zbioru\n" +
                            "7. Wypisz zbiór\n" +
                            "0. ZAKONCZ\n" +
                            "...");
                    komend = S.nextInt();
                    switch (komend) {
                        case 1: {
                            System.out.println("Podaj klucz i wartość pary : \n...\n");
                            Para p = new Para(S.next(), S.nextDouble());
                            tab.wstaw(p);
                            break;
                        }
                        case 2: {
                            System.out.println("Podaj klucz i wartość pary : \n...\n");
                            Para p = new Para(S.next(), S.nextDouble());
                            tab.ustaw(p);
                            break;
                        }
                        case 3: {
                            System.out.println("Podaj klucz według którego chcesz szukać pary: \n...\n");
                            try{
                                System.out.println("Znaleziona para = " + tab.szukaj(S.next()));
                            }
                            catch (Exception e){
                                System.err.println("NIE ZNALEZIONO PARY...");
                            }
                            break;
                        }
                        case 4: {
                            System.out.println("Podaj klucz którego wartość chcesz odnaleźć: \n...\n");
                            System.out.println("Wartość pary o podanym kluczu = " + tab.czytaj(S.next()));
                            break;
                        }
                        case 5: {
                            System.out.println("Wyczyszczono zbiór");
                            tab.czysc();
                            break;
                        }
                        case 6: {
                            System.out.println("Wielkość zbioru to " + tab.ile());
                            break;
                        }
                        case 7: {
                            System.out.println(tab);
                            break;
                        }
                        case 0: {
                            i = -1;
                            break;
                        }
                    }
                }
                break;
            }
            case 2 : {
                ZbiorNaTablicyDynamicznej tab = new ZbiorNaTablicyDynamicznej();
                int i = 1;
                while (i != -1) {
                    System.out.println("Co chcesz zrobić? :\n" +
                            "1. Wstaw parę\n" +
                            "2. Ustaw parę\n" +
                            "3. Szukaj pary\n" +
                            "4. Czytaj parę\n" +
                            "5. Wyczyść zbiór\n" +
                            "6. Wyświetl rozmiar zbioru\n" +
                            "7. Wypisz zbiór\n" +
                            "0. ZAKONCZ\n" +
                            "...");
                    komend = S.nextInt();
                    switch (komend) {
                        case 1: {
                            System.out.println("Podaj klucz i wartość pary : \n...\n");
                            Para p = new Para(S.next(), S.nextDouble());
                            tab.wstaw(p);
                            break;
                        }
                        case 2: {
                            System.out.println("Podaj klucz i wartość pary : \n...\n");
                            Para p = new Para(S.next(), S.nextDouble());
                            tab.ustaw(p);
                            break;
                        }
                        case 3: {
                            System.out.println("Podaj klucz według którego chcesz szukać pary: \n...\n");
                            try{
                                System.out.println("Znaleziona para = " + tab.szukaj(S.next()));
                            }
                            catch (Exception e){
                                System.err.println("NIE ZNALEZIONO PARY...");
                            }
                            break;
                        }
                        case 4: {
                            System.out.println("Podaj klucz którego wartość chcesz odnaleźć: \n...\n");
                            System.out.println("Wartość pary o podanym kluczu = " + tab.czytaj(S.next()));
                            break;
                        }
                        case 5: {
                            System.out.println("Wyczyszczono zbiór");
                            tab.czysc();
                            break;
                        }
                        case 6: {
                            System.out.println("Wielkość zbioru to " + tab.ile());
                            break;
                        }
                        case 7: {
                            System.out.println(tab);
                            break;
                        }
                        case 0: {
                            i = -1;
                            break;
                        }
                    }
                }
                break;
            }
            default : {
                throw new Exception("Wybrano nieobsługiwany numer...");
            }
        }
    }
}

