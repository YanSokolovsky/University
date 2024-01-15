package lfm.lfm.fw.r;

import java.io.*;
import java.io.Reader;
import java.util.ArrayList;

public class TXTReader extends lfm.lfm.fw.r.Reader {
    public TXTReader(String Input) {
        fileName = Input;
    }
    @Override
    public ArrayList<String> read() {
        ArrayList<String> expressions = new ArrayList<>();
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName));
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                expressions.add(line);
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return expressions;
    }
}
