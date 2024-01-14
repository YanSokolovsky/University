import java.util.Random;
import java.util.StringTokenizer;

public class StringProcessor {
    public static String makeRegex(String delimiter)
    {
        StringBuilder regex = new StringBuilder();
        for (int i = 0 ; i < delimiter.length(); i++)
        {
            regex.append("//?");
            regex.append(delimiter.charAt(i));
        }
        return regex.toString();
    }
    public static String removeConsecutive(String text, String chars) {
        for(int i = 0 ; i < text.length(); i++)
        {
            if (chars.indexOf(text.charAt(i)) > -1)
            {
                if (chars.indexOf(text.charAt(i + 1)) > -1)
                {
                    StringBuilder sb = new StringBuilder(text);
                    sb.deleteCharAt(i);
                    text = new String(sb);
                }
            }
        }
        return text;
    }
    public static String[] tokenize(StringTokenizer st)
    {
        int n = st.countTokens();
        String[] tokens = new String[st.countTokens()];
        for (int i = 0; i < n; i++)
        {
            tokens[i] = st.nextToken();
        }
        return tokens;
    }
    public static String[] extractIntegers(String[] array)
    {
        int counter = 0;
        String reg = "^\\d+$";
        for (String s : array) {
            if (s.matches(reg)) {
                counter++;
            }
        }
        int c = 0;
        String[] integers = new String[counter];
        for (String s : array) {
            if (s.matches(reg)) {
                integers[c] = s;
                c++;
            }
        }
        return integers;
    }
    public static String[] extractDates(String[] array)
    {
        int counter = 0;
        String reg = "^\\d\\d/\\d\\d/\\d\\d$";
        for (String s : array) {
            if (s.matches(reg)) {
                counter++;
            }
        }
        String[] dates = new String[counter];
        int c = 0;
        for (String s : array) {
            if (s.matches(reg)) {
                dates[c] = s;
                c++;
            }
        }
        return dates;
    }
    public static String insertRandom(String[] array)
    {
        Random rand = new Random();
        String reg = "^\\d+&";
        int g = array.length;
        int index = -1;
        for (int i = 0 ; i < g; i++)
        {
            if (array[i].matches(reg))
            {
                index = i;
                break;
            }
        }
        String result = "";
        int random = rand.nextInt();
        if (index == -1)
        {
            result = result.concat(String.valueOf(random));
            for (String s : array) {
                result = result.concat(s);
            }
        }
        else
        {
            for (int i = 0; i < g; i++)
            {
                if (i == index)
                    result = result.concat(String.valueOf(random));
                result = result.concat(array[i]);
            }
        }
        return result;
    }
}
