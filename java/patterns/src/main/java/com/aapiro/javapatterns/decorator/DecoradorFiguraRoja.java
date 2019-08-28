package com.aapiro.javapatterns.decorator;

public class DecoradorFiguraRoja extends DecoradorFigura {

    public DecoradorFiguraRoja(Figura figuraDecorada) {
        super(figuraDecorada);
    }

    @Override
    public void dibujar(){
        figuraDecorada.dibujar();
        setBordeRojo(figuraDecorada);
    }

    private void setBordeRojo(Figura figuraDecorada) {

        System.out.println("Color del borde: Rojo");
    }
}
