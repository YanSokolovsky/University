package Row;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TeylorRowTest {
    @Test
    void bigEpsilon() {
        TeylorRow h = new TeylorRow();
        Assertions.assertTrue(Math.abs(h.BigEpsilon(1).doubleValue() - Math.pow(10, -1)) < Math.pow(10, -1));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(2).doubleValue() - Math.pow(10, -2)) < Math.pow(10, -2));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(3).doubleValue() - Math.pow(10, -3)) < Math.pow(10, -3));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(4).doubleValue() - Math.pow(10, -4)) < Math.pow(10, -4));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(5).doubleValue() - Math.pow(10, -5)) < Math.pow(10, -5));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(6).doubleValue() - Math.pow(10, -6)) < Math.pow(10, -6));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(7).doubleValue() - Math.pow(10, -7)) < Math.pow(10, -7));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(8).doubleValue() - Math.pow(10, -8)) < Math.pow(10, -8));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(9).doubleValue() - Math.pow(10, -9)) < Math.pow(10, -9));
        Assertions.assertTrue(Math.abs(h.BigEpsilon(10).doubleValue() - Math.pow(10, -10)) < Math.pow(10, -10));
    }

    @Test
    void epsilon() {
        TeylorRow h = new TeylorRow();
        Assertions.assertTrue(Math.abs(h.epsilon(1) - Math.pow(10, -1)) < Math.pow(10, -1));
        Assertions.assertTrue(Math.abs(h.epsilon(2) - Math.pow(10, -2)) < Math.pow(10, -2));
        Assertions.assertTrue(Math.abs(h.epsilon(3) - Math.pow(10, -3)) < Math.pow(10, -3));
        Assertions.assertTrue(Math.abs(h.epsilon(4) - Math.pow(10, -4)) < Math.pow(10, -4));
        Assertions.assertTrue(Math.abs(h.epsilon(5) - Math.pow(10, -5)) < Math.pow(10, -5));
        Assertions.assertTrue(Math.abs(h.epsilon(6) - Math.pow(10, -6)) < Math.pow(10, -6));
        Assertions.assertTrue(Math.abs(h.epsilon(7) - Math.pow(10, -7)) < Math.pow(10, -7));
        Assertions.assertTrue(Math.abs(h.epsilon(8) - Math.pow(10, -8)) < Math.pow(10, -8));
        Assertions.assertTrue(Math.abs(h.epsilon(9) - Math.pow(10, -9)) < Math.pow(10, -9));
        Assertions.assertTrue(Math.abs(h.epsilon(10) - Math.pow(10, -10)) < Math.pow(10, -10));
    }

    @Test
    void bigCalcCos() {
        TeylorRow h = new TeylorRow();
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(10)).doubleValue() - Math.cos(Math.toRadians(10))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(20)).doubleValue() - Math.cos(Math.toRadians(20))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(30)).doubleValue() - Math.cos(Math.toRadians(30))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(40)).doubleValue() - Math.cos(Math.toRadians(40))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(50)).doubleValue() - Math.cos(Math.toRadians(50))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(60)).doubleValue() - Math.cos(Math.toRadians(60))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(70)).doubleValue() - Math.cos(Math.toRadians(70))) < Math.pow(10, -15));
        Assertions.assertTrue(Math.abs(h.BigCalcCos(17,Math.toRadians(80)).doubleValue() - Math.cos(Math.toRadians(80))) < Math.pow(10, -15));
    }

    @Test
    void calcCos() {
        TeylorRow h = new TeylorRow();
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(50)) - new TeylorRow().calcCos(16, Math.toRadians(50))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(90)) - new TeylorRow().calcCos(16, Math.toRadians(90))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(180)) - new TeylorRow().calcCos(16, Math.toRadians(180))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(270)) - new TeylorRow().calcCos(16, Math.toRadians(270))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(360)) - new TeylorRow().calcCos(16, Math.toRadians(360))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(30)) - new TeylorRow().calcCos(16, Math.toRadians(30))) < Math.pow(10, -14));
        Assertions.assertTrue(Math.abs(Math.cos(Math.toRadians(45)) - new TeylorRow().calcCos(16, Math.toRadians(45))) < Math.pow(10, -14));
    }
}