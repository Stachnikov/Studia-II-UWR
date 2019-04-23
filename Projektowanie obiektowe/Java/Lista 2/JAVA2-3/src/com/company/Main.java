package com.company;


public class Main {

    public static void main(String[] args){

        Bufor<String> bufo = new Bufor<>(4);
        Producent p1 = new Producent(bufo,"1");
        Producent p2 = new Producent(bufo,"2");
        Producent p3 = new Producent(bufo,"3");
        Producent p4 = new Producent(bufo,"4");
        Producent p5 = new Producent(bufo,"5");
        Producent p6 = new Producent(bufo,"6");
        Producent p7 = new Producent(bufo,"7");
        Producent p8 = new Producent(bufo,"8");
        Producent p9 = new Producent(bufo,"9");
        Producent p10 = new Producent(bufo,"10");
        Konsument k1 = new Konsument(bufo);
        Konsument k2 = new Konsument(bufo);
        Konsument k3 = new Konsument(bufo);
        Konsument k4 = new Konsument(bufo);
        Konsument k5 = new Konsument(bufo);
        Konsument k6 = new Konsument(bufo);
        Konsument k7 = new Konsument(bufo);
        Konsument k8 = new Konsument(bufo);
        Konsument k9 = new Konsument(bufo);
        Konsument k10 = new Konsument(bufo);

        p1.start();
        p2.start();
        p3.start();
        p4.start();
        p5.start();
        p6.start();
        p7.start();
        p8.start();
        p9.start();
        p10.start();

        k1.start();
        k2.start();
        k3.start();
        k4.start();
        k5.start();
        k6.start();
        k7.start();
        k8.start();
        k9.start();
        k10.start();


    }

}

class Konsument extends Thread{
    Bufor<String> buf;

    public Konsument(Bufor<String> b){
        this.buf=b;
    }

    @Override
    public void run(){
            buf.get();
    }
}

class Producent extends Thread{
    Bufor<String> buf;
    String elem;

    public Producent(Bufor<String> b,String napis){
        this.buf=b;
        this.elem=napis;
    }

    @Override
    public void run(){
            buf.put(elem);
    }
}

class Bufor<T> {
    public static int rozmiar;
    public static int indeks;
    public T[] Bufor;

    Bufor(int r){
        rozmiar = r;
        indeks=-1;
        Bufor = (T[])new Object[rozmiar];
    }

    public synchronized  void put(T elem){

            while(indeks>=rozmiar-1){
                try{
                    System.out.println("Bufor pelny - czekam...");
                    wait();
                } catch(InterruptedException e) {}}
            System.out.println("Producent dodal: " + elem);
            indeks++;
            Bufor[indeks]=elem;
            notify();
        }

    public synchronized  T get(){

        //System.out.println("Konsument  chce zabrac");
        while(indeks<0){
            try{
                System.out.println("Bufor pusty - czekam...");
                wait();
            } catch(InterruptedException e) {}}
            System.out.println("Konsument zabral: " + Bufor[0]);
            T wynik = Bufor[0];
            indeks--;
            for(int i=0; i <= indeks; i++){
                Bufor[i]=Bufor[i+1];
            }
            notify();
            return wynik;
        }
    }