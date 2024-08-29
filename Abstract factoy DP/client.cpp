#include <iostream>
using namespace std;

class IButton{ //interface for button
    public:
    virtual void press()=0;
}; 

class MacButton:public IButton{
public:
    void press(){
        cout<<" mac button Pressed "<<endl;
    }
};
class WinButton:public IButton{
public:cd 
    void press(){
        cout<<" Win button Pressed "<<endl;
    }
};


class ITextBox{//interface for text box
    public:
    virtual void showText()=0;
}; 
class MacTextBox:public ITextBox{
public:
    void showText(){
        cout<<" mac Text box showing  "<<endl;
    }
};
class WinTextBox:public ITextBox{
public:
    void showText(){
        cout<<" Win Text box showing "<<endl;
    }
};



class IFactory{
public:
    virtual IButton* CreateButton()=0;
    virtual ITextBox* CreateTextBox()=0;
};
class Macfactory:public IFactory{
public:
    IButton* CreateButton(){
        return new MacButton();
    }
    ITextBox* CreateTextBox(){
        return new MacTextBox();
    }
};
class Winfactory:public IFactory{
public:
    IButton* CreateButton(){
        return new WinButton();
    }
    ITextBox* CreateTextBox(){
        return new WinTextBox();
    }
};
 
class GUIAbstctFactory{
public:
static IFactory* CreateFactory(string osType){
    if(osType=="Win"){
        return new Winfactory();
    }
    else if(osType=="Mac"){
        return new Macfactory();
    } 
    else {
        return new Macfactory();
    }
}
};


int main(){
    string osType;
    cout<<" Enter your machine : "<<endl;
    cin>>osType;
    //since we dont want to change code , we are going to inherit mac/win factory from an interface
    //and for creating the interface factory there will be abstract factory (GUIAbstctFactory) which we will use to return os factoy
    IFactory* fact = GUIAbstctFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* TextBox = fact->CreateTextBox();
    TextBox->showText();

       return  0;
}