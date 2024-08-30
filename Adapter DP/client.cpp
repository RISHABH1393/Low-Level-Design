#include <iostream>
using namespace std;

class XMLdata{
    string xmlData;
    public:
        XMLdata(string pXmlData){
            xmlData=pXmlData;
        }
    string getXMLdata(){
        return xmlData;
    }
};

class DataAnalyticsTool{
    string jsonData;
    public:
        DataAnalyticsTool(){} 
        DataAnalyticsTool(string pJsonData){
            jsonData=pJsonData;
        }
        virtual void  analysingData(){
            cout<<" Analysing json Data : "<<jsonData;
        }
};
class Client{//Process Data
    public:
    void ProcessData(DataAnalyticsTool* tool){//needs the data and the tool to process the data
        tool->analysingData();
    }

};
class Adapter:public DataAnalyticsTool{
    XMLdata* xmlData;
public: 
    Adapter(XMLdata* pXmlData)
    {//it will take the xmldata and convert it into json and then do analysis
         xmlData= pXmlData;
    }
    void analysingData() override{//we will use the xml data and do analysis on it as it derived from dataanalytic class.
        cout<<" Converting XML data /"<< xmlData->getXMLdata()<< "/ to json data "<<endl;
        DataAnalyticsTool::analysingData();
    } 

};

int main(){
//create objects of classes

XMLdata* xmlData = new XMLdata("sample XML DATA ..");
//DataAnalyticsTool* tool = new DataAnalyticsTool("json");
DataAnalyticsTool* tool = new Adapter(xmlData);  //we are changing the object so that client should not have bothered whenever tool changed
Client* client;
client->ProcessData(tool);
    return 0;
}