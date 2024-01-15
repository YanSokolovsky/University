package org.mlfm.tests;

import org.mlfm.forarchive.dearchivers.ZipDearchivator;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ZipDearchivatorTest {

    @Test
    void dearchive() {
        ZipDearchivator zip = new ZipDearchivator("D:\\testing\\output.zip");
        zip.dearchive();
    }

    @Test
    void testDearchive() {
        ZipDearchivator zip = new ZipDearchivator("D:\\testing\\output.zip");
        zip.dearchive("D:\\testing\\Ziptest");
    }
}