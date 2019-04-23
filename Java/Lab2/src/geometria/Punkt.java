package geometria;

class Punkt{
    private double x,y;


    Punkt(double px,double py){
        this.x=px;
        this.y=py;
    }

    double getx(){
        return x;
    }

    double gety(){
        return y;
    }

    void przesun(Wektor v){
        x=x+v.dx;
        y=y+v.dy;
    }

    void obroc(Punkt p, double kat){
        double xx,yy;
        xx = (this.getx() - p.getx()) * Math.cos(Math.toRadians(kat)) - (this.gety() - p.gety()) * Math.sin(Math.toRadians(kat)) + p.getx() ;
        yy = (this.getx() - p.getx()) * Math.sin(Math.toRadians(kat)) + (this.gety() - p.gety()) * Math.cos(Math.toRadians(kat)) + p.gety();
        x=xx;
        y=yy;
    }

    void odbij(Prosta p) throws Exception{

        Prosta p11 = Prosta.prostopadla(p,this);
        Punkt S = Prosta.przeciecie(p11,p);

        Punkt kon = new Punkt(2*S.getx() - this.getx(),2*S.gety() - this.gety());

        this.x=kon.x;
        this.y=kon.y;
    }
    //To do toString
}

