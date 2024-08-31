package CompositeDP.FileSystem;

public class Main {
    public static void main(String a[]){
        Directory directory1 = new Directory("movie");
        File file = new File("sholey");
        directory1.add(file);

        Directory directory2 = new Directory("comedy");
        File file2 = new File("dhol");
        directory2.add(file2);
        directory1.add(directory2);
        // directory2.ls();
        // System.out.println("directory 1");
        directory2.ls();

    }
}
