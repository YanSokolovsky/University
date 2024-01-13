package Row;

import java.math.*;

public class TeylorRow {
    public BigDecimal BigEpsilon(int k) {
        BigDecimal g = new BigDecimal(1);
        for (int i = 0; i < k; i++) {
            g = g.divide(BigDecimal.valueOf(10), k + 1, RoundingMode.HALF_UP);
        }
        return g;
    }

    public double epsilon(int k) {
        double g = 1;
        for (int i = 0; i < k; i++) {
            g = g / 10;
        }
        return g;
    }
    public BigDecimal BigCalcCos(int k, double x) {
        int numberForFactorial = 1;
        BigDecimal X = BigDecimal.valueOf(x).setScale(16, RoundingMode.HALF_UP);
        BigDecimal epsi = BigEpsilon(k);
        BigDecimal chlen = BigDecimal.valueOf(1);
        BigDecimal row = BigDecimal.valueOf(0);
        while (chlen.abs().compareTo(epsi) > -1) {
            row = row.add(chlen);
            chlen = chlen.
                    multiply(X).
                    multiply(X).
                    multiply(BigDecimal.valueOf(-1)).
                    divide(BigDecimal.valueOf(numberForFactorial), k + 10, RoundingMode.HALF_UP).
                    divide(BigDecimal.valueOf(numberForFactorial + 1), k + 10, RoundingMode.HALF_UP);
            numberForFactorial += 2;
        }
        return row.setScale(k + 1, RoundingMode.HALF_UP);
    }

    public double calcCos(int k, double x) {
        int numberForFactorial = 1;
        double epsi = epsilon(k);
        double chlen = 1;
        double row = 0;
        while (Math.abs(chlen) >= epsi) {
            row = row + chlen;
            chlen = chlen * x * x * (-1) / numberForFactorial / (numberForFactorial + 1);
            numberForFactorial += 2;
        }
        return row;
    }
    public double compar(int k, double x) {
        double kanon = Math.cos(x);
        double result;
        result = Math.abs(calcCos(k, x) - kanon);
        return result;
    }
}
