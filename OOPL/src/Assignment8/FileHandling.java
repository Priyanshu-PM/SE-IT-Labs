package Assignment8;
import java.io.*;
import java.util.*;

public class FileHandling {

    public
    Scanner sc = new Scanner(System.in);
    String filename;
    File file;
    FileHandling() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the file name : ");
        filename = sc.next();
        file = new File(filename);
        
        try {
            if(file.createNewFile()) {
                System.out.println("File created successfully with name : "+filename);
            }
            else {
                System.out.println("File already exists !!");
            }
        }
        catch(Exception e) {
            System.out.println("Error occurred "+e.getMessage());
        }

    }

    void addRecord() {
        System.out.println("Enter the student id : ");
        String id = sc.next();

        System.out.println("Enter the student name : ");
        String name = sc.nextLine();
        name = sc.next();

        System.out.println("Enter the class of the student : ");
        String sclass = sc.next();

        System.out.println("Enter the marks of the student : ");
        String marks = sc.next();

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true));
            writer.write(id+", "+name+", "+sclass+", "+marks+"\n");
            System.out.println("Record entered successfully");
            writer.close();
        }
        catch(IOException e) {
            System.out.println("Exception occured !! "+e.getMessage());
        }

        
    }

    void displayRecord() {

        try {
            Scanner reader = new Scanner(file);
            while(reader.hasNextLine()) {
                String data = reader.nextLine();
                System.out.println(data);
                System.out.println();
            }
        }
        catch(FileNotFoundException e) {
            System.out.println("File not found exception occured : "+e.getMessage());
        }

    }

    void deleteRecord() {
        System.out.println("Enter the student id you want to delete : ");
        String id = sc.next();
        try {
            File newfile = new File("backup.txt");
            FileWriter fw = new FileWriter(newfile, true);

            Scanner reader = new Scanner(file);
            while(reader.hasNextLine()) {
                String line = reader.nextLine();
                String arr[] = line.split(",");
                if(!arr[0].equals(id)) {
                    fw.write(line+"\n");
                }
                else {
                    System.out.println("Found the record with given id !!");
                }
            }
            fw.close();

            // newfile.renameTo(file);
            PrintWriter pw = new PrintWriter(filename);
            pw.write("");
            pw.close();

            file = new File(filename);
            FileWriter writer = new FileWriter(file, true);

            Scanner reader1 = new Scanner(newfile);
            while(reader1.hasNextLine()) {
                String line = reader1.nextLine();
                writer.write(line+"\n");
            }
            
            writer.close();
            reader1.close();
            newfile.delete();

        }
        catch(IOException e) {
            System.out.println("Exception occured : "+e.getMessage());
        }
    }
}
