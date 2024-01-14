import java.util.*;

public class Main {
    public static void main(String[] args) {
        String input;
        String separator;
        Scanner scan = new Scanner(System.in);
        input = scan.nextLine();
        separator = scan.nextLine();
        String[] parts = input.split("\\(.*\\)");
        scan.close();
        String noBrackets;
        int len = parts.length;
        for (int i = 0; i < len - 1; i++)
        {
            parts[0] = parts[0].concat(parts[i + 1]);
        }
        noBrackets = parts[0];
        input = StringProcessor.removeConsecutive(noBrackets, separator);
        noBrackets = input;
        String regex = StringProcessor.makeRegex(separator);
        String[] array = noBrackets.split(regex);
        StringTokenizer token = new StringTokenizer(noBrackets, separator);
        String[] tokens = StringProcessor.tokenize(token);
        String[] numbers = StringProcessor.extractIntegers(tokens);
        String[] dates = StringProcessor.extractDates(tokens);
        String randomStr = StringProcessor.insertRandom(array);
        System.out.println("строка с удаленными скобками: " + noBrackets);
        System.out.println("массив чисел============================");
        for (String s : numbers) {
            System.out.println(s);
        }
        System.out.println("массив дат===============================");
        for (String s : dates) {
            System.out.println(s);
        }
        System.out.println("просто массив=============================");
        for (String s : array) {
            System.out.println(s);
        }
        System.out.println("массив с токанайзером===================================");
        for (String s : tokens) {
            System.out.println(s);
        }
        System.out.println("сторока со вставленным рандомным числом: " + randomStr);

    }
}