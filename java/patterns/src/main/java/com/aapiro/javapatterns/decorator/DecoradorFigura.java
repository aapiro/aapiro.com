package com.aapiro.javapatterns.decorator;

public abstract class DecoradorFigura implements Figura {

    protected Figura figuraDecorada;

    public DecoradorFigura(Figura figuraDecorada){
        this.figuraDecorada = figuraDecorada;
    }

    public void dibujar(){
        figuraDecorada.dibujar();
    }
}

