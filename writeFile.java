import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {

        String filepath = "X:\\no\\test.txt";


        String text = """
                My name is negar
                but my hoodie is bigger
                i dont like bitches
                but i do some hitches
                """;

        try(FileWriter writer = new FileWriter(filepath)) {
            writer.write(text);
            System.out.println("file done");
        } catch (IOException e) {
            System.out.println("problemas de occarion");
        } finally {
            System.out.println("finishacion");
        }


    }
}
