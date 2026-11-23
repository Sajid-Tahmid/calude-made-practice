import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {

        String filepath = "C:\\Users\\ASRAF IT\\Desktop\\yo.txt";

        try(BufferedReader reader = new BufferedReader(new FileReader(filepath));){
            String line;
            while((line = reader.readLine()) != null){
                System.out.println(line);
            }
        }
        catch (FileNotFoundException a){
            System.out.println("file not found");
        }
        catch (IOException a){
            System.out.println("io error");
        }
    }
}
