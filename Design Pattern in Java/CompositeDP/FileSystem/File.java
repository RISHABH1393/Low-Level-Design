package CompositeDP.FileSystem;

public class File implements FileSystem{
    String name;
    File(String name){
        this.name = name;
    }
    public void  PrintName(){
        System.out.print(this.name+" ");
    }
    public void ls(){
        System.out.println(name);
    }
}
