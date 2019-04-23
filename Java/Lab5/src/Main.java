import narzedzia.WyjatekONP;
import narzedzia.Zmienna;
import narzedzia.Wyrazenie;

import java.io.IOException;
import java.util.Scanner;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class Main {

    private static final Logger logger =
            Logger.getLogger(Main.class.getName());

    private static FileHandler fh;

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String line;
        String[] str;
        logger.setLevel(Level.INFO);
        logger.setUseParentHandlers(false);
        try {
            // This block configure the logger with handler and formatter
            fh = new FileHandler("C:/Users/Dell/Desktop/3 SEMESTR/Java/Lab5/calc.log");
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);
        } catch (SecurityException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }





        do{
            line=sc.nextLine();
            str = line.split(" ");
            if(str[0].matches("calc")){
                try {
                    Wyrazenie wyr = new Wyrazenie(java.util.Arrays.copyOfRange(str, 1, str.length));
                    System.out.println(wyr.oblicz());
                    logger.info(Double.toString(wyr.oblicz()));
                }catch(WyjatekONP ex){
                    System.out.println(ex);
                    logger.info(String.valueOf(ex));
                }
            }
            else if (str[0].matches("clear")){
                if(str.length==1){
                    Zmienna.wyczysc();
                }
                else
                    for(int i=1; i<str.length; i++) {
                        Zmienna.usun(str[i]);
                    }
            }
            else if (str[0].matches("exit")){
                break;
            }
            else {
                throw new AssertionError(str[0]);
            }
        } while(true);
    }
}
