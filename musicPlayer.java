import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        String filepath = "C:\\Users\\ASRAF IT\\Desktop\\soundtrack.wav";



        File file = new File(filepath);

        try(Scanner scanner = new Scanner(System.in);
            AudioInputStream audiostream = AudioSystem.getAudioInputStream(file)){
            Clip clip = AudioSystem.getClip();
            clip.open(audiostream);

            String response ="";

            while(!response.equals("Q")){

                System.out.println("P = Play");
                System.out.println("S = Stop");
                System.out.println("R = Replay");
                System.out.println("Q = Quit");
                System.out.println("Enter your chice: ");

                response = scanner.next().toUpperCase();

                switch (response){
                    case "P" -> clip.start();
                    case "S" -> clip.stop();
                    case "R" -> clip.setMicrosecondPosition(0);
                    case "Q" -> clip.close();
                    default -> System.out.println("Invalid Input");

                }
            }
        }
        catch (UnsupportedAudioFileException e){
            System.out.println("not supported format audio");
        }
        catch (LineUnavailableException e){
            System.out.println("line not available");
        }
        catch (IOException e){
            System.out.println("something went wrong");
        }

    }
}
