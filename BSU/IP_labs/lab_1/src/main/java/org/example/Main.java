package org.example;

import Row.TeylorRow;

import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Formatter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int k;
        Scanner in1 = new Scanner(System.in);
        System.out.println("Дорогой пользователь, введите точностиь с которой  будет вычисляться косинус: ");
        k = in1.nextInt();
        double digree;
        System.out.println("Дорогой пользователь, введите градусы, косинус которых вы зотите вычислить:");
        digree = in1.nextDouble();
        double result = new TeylorRow().calcCos(k, Math.toRadians(digree));
        System.out.println("форматированный вывод с помощью класса Formatter");
        Formatter frm = new Formatter();
        frm.format("Ваш результат: %#1.16f", result);
        System.out.println(frm);
        Formatter frm1 = new Formatter();
        frm1.format("Ваш результат: %+1.13f", result);
        System.out.println(frm1);
        Formatter frm2 = new Formatter();
        frm2.format("Ваш результат: %01.9f", result);
        System.out.println(frm2);
        System.out.println(result);
        System.out.println("Погрешность составила:" + new TeylorRow().compar(k, Math.toRadians(digree)));
        System.out.println("----------------------------------------------------------------------------");
        System.out.println("Форматированный вывод с помщью класса NumberFormat");
        NumberFormat nform = NumberFormat.getInstance();
        System.out.println("введите максимальное число цифр после запятой: ");
        int frac = in1.nextInt();
        nform.setMaximumFractionDigits(frac + 1);
        System.out.println(nform.format(result));
        System.out.println("------------------------------------------------------------------------------");
        System.out.println("Форматированный вывод с помощью класса BigDecimal");
        System.out.println("Дорогой пользователь, введите точностиь с которой  будет вычисляться косинус: ");
        k = in1.nextInt();
        System.out.println("Дорогой пользователь, введите градусы, косинус которых вы зотите вычислить:");
        digree = in1.nextDouble();
        BigDecimal result1 = new TeylorRow().BigCalcCos(k, Math.toRadians(digree));
        result1.setScale(k + 1);
        System.out.println(result1.setScale(k + 1).toString());
        System.out.println("хотите округлить вниз: d --- хотите округлить вверх u");
        String f = in1.next();
        if (f.equals("u")) {
            result1.setScale(k + 1, BigDecimal.ROUND_HALF_UP);
            System.out.println(result1.setScale(k + 1).toString());
        }else {
            result1.setScale(k + 1, BigDecimal.ROUND_HALF_DOWN);
            System.out.println(result1.setScale(k + 1).toString());
        }
    }
}