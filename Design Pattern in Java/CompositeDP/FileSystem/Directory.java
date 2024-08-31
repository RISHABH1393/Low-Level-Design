package CompositeDP.FileSystem;

import java.util.ArrayList;
import java.util.List;

public class Directory implements FileSystem{
    public String name;
    List<FileSystem> fileSystemList;

    Directory(String name){
        this.name = name;
        fileSystemList = new ArrayList<>();
    }
    public void add(FileSystem fileSystem){
            fileSystemList.add(fileSystem);
    }
    public void  PrintName(){
        System.out.print(this.name+" ");
    }
    public void ls(){
        System.out.println(name+"/");
        for(FileSystem FsObj:fileSystemList){
            FsObj.PrintName();
        }
    }
}
