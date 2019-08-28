package com.aapiro.javapatterns.decorator;

public class DemoPatronDecorador {

    public static void main(String[] args) {

        Figura circulo = new Circulo();

        Figura circuloRojo = new DecoradorFiguraRoja(new Circulo());

        Figura rectanguloRojo = new DecoradorFiguraRoja(new Rectangulo());

        System.out.println("Circulo con borde normal");
        circulo.dibujar();

        System.out.println("\nCirculo de borde Rojo");
        circuloRojo.dibujar();

        System.out.println("\nRectangulo de borde Rojo");
        rectanguloRojo.dibujar();
    }
}
