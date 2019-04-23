package com.company;

public class Main{

    public static void main(String[] args) throws InterruptedException {
        int tablica[] = {4,15,6,1,63,12,66,84,2,35,23,53,81,43,93,99,88,77,55,44,33,22,11};
        int ile_liczb = tablica.length;

        System.out.println("\n\nTablica przed posortowaniem:");
        for(int i=0; i<ile_liczb; i++)
            System.out.print(tablica[i]+" ");

        System.out.print("\n\n\n");
        Watek w1 = new Watek(tablica, 0, ile_liczb-1);
        w1.start();
        w1.join();

        System.out.println("\nTablica po posortowaniu:");

        for(int i=0; i<ile_liczb; i++)
            System.out.print(tablica[i]+" ");
    }
}

class Watek extends Thread{
    int pocz, sr, kon, tablica[];

    Watek(int tab[],int p, int k){
        pocz=p;
        kon=k;
        tablica=tab;
        sr = (pocz + kon) / 2;
    }

    protected static void merge (int tablica[], int pocz, int sr, int kon){
        int i, j, q;
        int t[] = new int[tablica.length];
        for (i = pocz; i <= kon; i++) t[i] = tablica[i];
        i = pocz;
        j = sr + 1;
        q = pocz;
        while (i <= sr && j <= kon) {
            if (t[i] < t[j])
                tablica[q++] = t[i++];
            else
                tablica[q++] = t[j++];
        }
        while (i <= sr)
            tablica[q++] = t[i++];
    }


    @Override
    public void run() {
        try {
            System.out.println("START:  " + getName());
            if (pocz < kon) {
                Watek sortL = new Watek(tablica, pocz, sr);
                Watek sortR = new Watek(tablica, sr + 1, kon);
                sortL.start();
                sortR.start();
                sortL.join();
                sortR.join();
                merge(tablica, pocz, sr, kon);
                System.out.println("END:  " + getName());
            }
        } catch (InterruptedException ex) {
            System.out.println("Pojawil sie problem z watkiem " + getName());
        }
    }
}
