package util;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.function.Function;

import static java.nio.file.StandardOpenOption.APPEND;
import static java.nio.file.StandardOpenOption.CREATE;

public class FileManager {

    public static boolean checkIfExists(String filename) {
        return new File(filename).exists();
    }

    public static void write(String filename, Object o) {
        try {
            Files.writeString(Path.of(filename), o.toString());
        } catch (IOException e) {
            System.out.println("Unable to write to file" + filename);
        }
    }

    public static void writeAppend(String filename, Object o) {
        try {
            Files.writeString(Path.of(filename), o.toString() + "\n", CREATE, APPEND);
        } catch (IOException e) {
            System.out.println("Unable to writeAppend to file" + filename);
        }
    }

    public static Object read(String filename, Function<String, Object> function) {
        try {
            String input = Files.readString(Path.of(filename));
            return function.apply(input);
        } catch (IOException e) {
            System.out.println("Unable to read from file" + filename);
            return null;
        }
    }

}
