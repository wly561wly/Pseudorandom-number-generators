import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.security.SecureRandom;
import java.util.concurrent.ThreadLocalRandom;

public class RandomSequenceGenerator {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java RandomSequenceGenerator <1|2|3|4>");
            return;
        }

        int option = Integer.parseInt(args[0]);
        String fileName = "random.txt";
        long targetSize = 10 * 1024 * 1024; // 10MB

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            switch (option) {
                case 1:
                    generateRandomSequence(new Random(), writer, targetSize);
                    break;
                case 2:
                    generateRandomSequence(new SecureRandom(), writer, targetSize);
                    break;
                case 3:
                    generateRandomSequence(ThreadLocalRandom.current(), writer, targetSize);
                    break;
                case 4:
                    generateRandomSequenceMathRandom(writer, targetSize);
                    break;
                default:
                    System.out.println("Invalid option. Please choose 1, 2, 3, or 4.");
                    break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void generateRandomSequence(Random random, BufferedWriter writer, long targetSize) throws IOException {
        long generatedSize = 0;
        while (generatedSize < targetSize) {
            int randomInt = random.nextInt(2);
            writer.write(randomInt == 0 ? '0' : '1');
            generatedSize += 1;
        }
    }

    private static void generateRandomSequenceMathRandom(BufferedWriter writer, long targetSize) throws IOException {
        long generatedSize = 0;
        while (generatedSize < targetSize) {
            int randomInt = (int) (Math.random() * 2);
            writer.write(randomInt == 0 ? '0' : '1');
            generatedSize += 1;
        }
    }
}