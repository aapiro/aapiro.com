package com.aapiro.javapatterns.decorator;

public class Rectangulo implements Figura {


    @Override
    public void dibujar() {
        System.out.println("Figura: Rectangulo");
    }
}
