package lfm.lfm;

import lfm.lfm.cry.dec.Decryptor;
import lfm.lfm.cry.enc.Encoder;
import lfm.lfm.fw.r.JSONReaderNonAPI;
import lfm.lfm.fw.r.TXTReader;
import lfm.lfm.fw.r.XMLReaderNonAPI;
import lfm.lfm.fw.wr.JSONWriterNonAPI;
import lfm.lfm.fw.wr.TXTWriter;
import lfm.lfm.fw.wr.XMLWriterNonAPI;
import lfm.lfm.rarzip.RarArchivator;
import lfm.lfm.rarzip.RarDearchivator;
import lfm.lfm.rarzip.ZipArchivator;
import lfm.lfm.rarzip.ZipDearchivator;

import java.io.File;
import java.util.ArrayList;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Commands {
    ArrayList<String> expressions = new ArrayList<>();
    ArrayList<String> filesToArchive = new ArrayList<>();
    void read(String inputFileName) {
        // Define the regex patterns for each file format
        String xmlFormat = "\\.xml$";
        String jsonFormat = "\\.json$";
        String txtFormat = "\\.txt$";
        // Compile the pattern for xml format
        Pattern pattern = Pattern.compile(xmlFormat);
        // Match the pattern with the input file name
        Matcher matcher = pattern.matcher(inputFileName);
        // If the file name ends with .xml, use the XMLReader class to read the file
        if (matcher.find()) {
            XMLReaderNonAPI xmlReader = new XMLReaderNonAPI(inputFileName);
            expressions = xmlReader.read();
        }
        // Compile the pattern for json format
        pattern = Pattern.compile(jsonFormat);
        // Match the pattern with the input file name
        matcher = pattern.matcher(inputFileName);
        // If the file name ends with .json, use the JSONReader class to read the file
        if (matcher.find()) {
            JSONReaderNonAPI jsonReader = new JSONReaderNonAPI(inputFileName);
            expressions = jsonReader.read();
        }
        // Compile the pattern for txt format
        pattern = Pattern.compile(txtFormat);
        // Match the pattern with the input file name
        matcher = pattern.matcher(inputFileName);
        // If the file name ends with .txt, use the TXTReader class to read the file
        if (matcher.find()) {
            TXTReader txtReader = new TXTReader(inputFileName);
            expressions = txtReader.read();
        }
    }
    // This method archives a file using the RarArchivator class
    // The file format can be rar or zip
    void archive(String name, String format) {
        // Define the regex patterns for each file format
        String shortname = getShortName(name);
        Pattern pat = Pattern.compile("^[^.]+");
        Matcher mat = pat.matcher(shortname);
        String nameoutform = new String();
        if (mat.find()) {
            nameoutform = shortname.substring(mat.start(), mat.end());
        }
        String archname;
        switch (format) {
            case "rar" -> {
                StringBuilder d = new StringBuilder();
                d.append(nameoutform);
                d.append(".rar");
                archname = d.toString();
                String path = getAddressOfFile(name);
                d = new StringBuilder(path);
                d.append("\\");
                d.append(archname);
                archname = d.toString();
                filesToArchive.add(name);
                RarArchivator rarArchivator = new RarArchivator(archname, filesToArchive);
                rarArchivator.archive();
                filesToArchive = new ArrayList<>();
            }
            case "zip" -> {
                StringBuilder d = new StringBuilder();
                d.append(nameoutform);
                d.append(".zip");
                archname = d.toString();
                String path = getAddressOfFile(name);
                d = new StringBuilder(path);
                d.append("\\");
                d.append(archname);
                archname = d.toString();
                filesToArchive.add(name);
                RarArchivator rarArchivator = new RarArchivator(archname, filesToArchive);
                rarArchivator.archive();
                filesToArchive = new ArrayList<>();
            }
        }
    }
    // This method dearchives a file using the RarDearchivator class
    // The file format can be rar or zip
    void dearchive(String inputFileName) {
        // Define the regex patterns for each file format
        String rarFormat = "\\.rar$";
        String zipFormat = "\\.zip$";
        // Compile the pattern for rar format
        Pattern pattern = Pattern.compile(rarFormat);
        // Match the pattern with the input file name
        Matcher matcher = pattern.matcher(inputFileName);
        // If the file name ends with .rar, use the RarDearchivator class to dearchive the file
        if (matcher.find()) {
            String winrarPath = "D:\\WinRAR.exe";
            String archivePath = inputFileName;
            String extractPath = getAddressOfFile(inputFileName) + "\\RarDearchiveResult\\"; //TODO измнить путь до екзе и место извлечения
            try {
                ProcessBuilder pb = new ProcessBuilder(winrarPath, "x", "-ibck", archivePath, extractPath);
                Process p = pb.start();
                p.waitFor();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        // Compile the pattern for zip format
        pattern = Pattern.compile(zipFormat);
        // Match the pattern with the input file name
        matcher = pattern.matcher(inputFileName);
        // If the file name ends with .zip, use the RarDearchivator class to dearchive the file
        if (matcher.find()) {
            ZipDearchivator zipDearchivator = new ZipDearchivator(inputFileName);
            zipDearchivator.dearchive();
        }
    }
    void write(String outputFileName) {
        // Define the regex patterns for different file formats
        String xmlFormat = "\\.xml$";
        String jsonFormat = "\\.json$";
        String txtFormat = "\\.txt$";
        // Create a pattern object for xml format
        Pattern pattern = Pattern.compile(xmlFormat);
        // Create a matcher object for the output file name
        Matcher matcher = pattern.matcher(outputFileName);
        // Check if the output file name matches the xml format
        if (matcher.find()) {
            // Create an XMLWriterNonAPI object with the output file path
            XMLWriterNonAPI xmlWriter = new XMLWriterNonAPI(outputFileName);
            // Write the expressions to the output file in xml format
            xmlWriter.write(expressions);
        }
        // Repeat the same process for json format
        pattern = Pattern.compile(jsonFormat);
        matcher = pattern.matcher(outputFileName);
        if (matcher.find()) {
            // Create a JSONWriter object with the output file path
            JSONWriterNonAPI jsonWriter = new JSONWriterNonAPI(outputFileName);
            // Write the expressions to the output file in json format
            jsonWriter.write(expressions);
        }
        // Repeat the same process for txt format
        pattern = Pattern.compile(txtFormat);
        matcher = pattern.matcher(outputFileName);
        if (matcher.find()) {
            // Create a TXTWriter object with the output file path
            TXTWriter txtWriter = new TXTWriter(outputFileName);
            // Write the expressions to the output file in txt format
            txtWriter.write(expressions);
        }
    }
    // This method removes any trailing slashes from the input file name
    public String removeTrailingSlashes(String inputFileName) {
        // Loop until the input file name does not end with a slash
        while (inputFileName.endsWith("\\")) {
            // Remove the last character from the input file name
            inputFileName = inputFileName.substring(0, inputFileName.length() - 1);
        }
        // Return the input file name without trailing slashes
        return inputFileName;
    }
    // This method returns the directory of the input file
    public String getFileDirectory(String inputFileName) {
        // Define the regex pattern for the file name
        String regex = "[^\\\\]*$";
        // Remove any trailing slashes from the input file name
        inputFileName = removeTrailingSlashes(inputFileName);
        // Create a pattern object for the file name
        Pattern pattern = Pattern.compile(regex);
        // Create a matcher object for the input file name
        Matcher matcher = pattern.matcher(inputFileName);
        // Declare a string variable for the directory
        String directory;
        // Check if the matcher finds the file name in the input file name
        if (matcher.find()) {
            // Get the substring before the file name as the directory
            directory = inputFileName.substring(0, matcher.start());
        } else {
            // If not, the input file name is the directory
            directory = inputFileName;
        }
        // Remove any trailing slashes from the directory
        directory = removeTrailingSlashes(directory);
        // Return the directory
        return directory;
    }
    public void encode(String name) {
        Encoder encoder = new Encoder(name, "kjshfkjhskdjfh kjsdhfk jhsdkjfh ikerh");
        encoder.encryptFile();
    }
    public void decode(String name) {
        Decryptor decryptor = new Decryptor(name, "kjshfkjhskdjfh kjsdhfk jhsdkjfh ikerh");
        decryptor.decryptFile();
    }
    public String getShortName(String fileName) {
        fileName = dellitingSlashes(fileName);
        String expression = "[^\\\\]*$";
        Pattern pattern = Pattern.compile(expression);
        Matcher matcher = pattern.matcher(fileName);
        if (matcher.find()) {
            return fileName.substring(matcher.start(), matcher.end());
        } else {
            return fileName;
        }
    }
    public String dellitingSlashes(String fileName) {
        while (fileName.endsWith("\\")) {
            fileName = fileName.substring(0, fileName.length() - 1);
        }
        return fileName;
    }
    public String getAddressOfFile(String fileName) {
        String expression = "[^\\\\]*$";
        fileName = dellitingSlashes(fileName);
        Pattern pattern = Pattern.compile(expression);
        Matcher matcher = pattern.matcher(fileName);
        String address;
        if (matcher.find()) {
            address = fileName.substring(0, matcher.start());
        } else {
            address = fileName;
        }
        address = dellitingSlashes(address);
        return address;
    }
}
