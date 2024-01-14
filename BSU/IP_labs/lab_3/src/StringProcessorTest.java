import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.StringTokenizer;
import java.util.Random;

public class StringProcessorTest {

    @Test
    public void testMakeRegex() {
        // Проверяем, что метод возвращает правильное регулярное выражение для разделителя
        assertEquals("//?1//?2//?3", StringProcessor.makeRegex("123"));
        assertEquals("//??//?p", StringProcessor.makeRegex("?p"));
        assertEquals("//?a//?b//?c", StringProcessor.makeRegex("abc"));
    }

    // Тест для метода removeConsecutive
    @Test
    public void testRemoveConsecutive() {
        // Проверяем, что метод удаляет повторяющиеся символы из строки
        assertEquals("abc", StringProcessor.removeConsecutive("aabbcc", "abc"));
        assertEquals("hello", StringProcessor.removeConsecutive("heelllloo", "elo"));
        assertEquals("123", StringProcessor.removeConsecutive("112233", "123"));
    }

    // Тест для метода tokenize
    @Test
    public void testTokenize() {
        // Проверяем, что метод возвращает массив токенов, разделенных по символам
        assertArrayEquals(new String[]{"hello", "world"}, StringProcessor.tokenize(new StringTokenizer("hello world", " ")));
        assertArrayEquals(new String[]{"java", "is", "fun"}, StringProcessor.tokenize(new StringTokenizer("java-is-fun", "-")));
        assertArrayEquals(new String[]{"one", "two", "three"}, StringProcessor.tokenize(new StringTokenizer("one,two,three", ",")));
    }

    // Тест для метода extractIntegers
    @Test
    public void testExtractIntegers() {
        // Проверяем, что метод возвращает массив чисел, извлеченных из массива строк
        assertArrayEquals(new String[]{"12", "22", "32"}, StringProcessor.extractIntegers(new String[]{"12", "a", "22", "b", "32", "c"}));
        assertArrayEquals(new String[]{"10", "20", "30"}, StringProcessor.extractIntegers(new String[]{"10", "hello", "20", "world", "30"}));
        assertArrayEquals(new String[]{"100", "200", "300"}, StringProcessor.extractIntegers(new String[]{"100", "200", "300"}));
    }

    // Тест для метода extractDates
    @Test
    public void testExtractDates() {
        // Проверяем, что метод возвращает массив дат, извлеченных из массива строк
        assertArrayEquals(new String[]{"01/01/23", "02/02/23", "03/03/23"}, StringProcessor.extractDates(new String[]{"01/01/23", "a", "02/02/23", "b", "03/03/23", "c"}));
        assertArrayEquals(new String[]{"10/10/23", "11/11/23", "12/12/23"}, StringProcessor.extractDates(new String[]{"10/10/23", "hello", "11/11/23", "world", "12/12/23"}));
        assertArrayEquals(new String[]{"20/20/23", "21/21/23", "22/22/23"}, StringProcessor.extractDates(new String[]{"20/20/23", "21/21/23", "22/22/23"}));
    }

    // Тест для метода insertRandom
    @Test
    public void testInsertRandom() {
        // Проверяем, что метод вставляет случайное число в начало или вместо первого элемента, соответствующего регулярному выражению
        Random rand = new Random();
        int random = rand.nextInt();
        assertNotEquals(random + "abc", StringProcessor.insertRandom(new String[]{"abc"}));
        assertNotEquals(random + "123", StringProcessor.insertRandom(new String[]{"123"}));
        assertNotEquals(random + "01/01/23", StringProcessor.insertRandom(new String[]{"01/01/23"}));
        assertNotEquals(random + "abc123", StringProcessor.insertRandom(new String[]{"abc", "123"}));
        assertNotEquals(random + "123abc", StringProcessor.insertRandom(new String[]{"123", "abc"}));
        assertNotEquals(random + "01/01/23abc", StringProcessor.insertRandom(new String[]{"01/01/23", "abc"}));
    }
}