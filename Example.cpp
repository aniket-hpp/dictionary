#include <iostream>
#include "dictionary.h"

int main(){
    //features in ver: 1.0.0
    //name to phone-number dictionary
    Dictionary<std::string, long> contacts;

    //prints {} , which represents empty Dictionary
    if(contacts.isEmpty())
        std::cout<<"Empty Dictionary: "<<contacts<<std::endl;

    //adding new datas
    contacts["Jake"] = 35429534;
    contacts.append("Luthor", 45772389);

    std::cout<<"\nOnly PhNo: ";
    //getting the datas of known Keys
    auto Jake_PhNo = contacts["Jake"];
    std::cout<<Jake_PhNo<<"\n\n";

    //getting the datas of unknown Keys
    auto keys = contacts.getKeys();
    for(auto k : keys){
        auto name = k;
        auto phNo = contacts[k];

        std::cout<<k<<" "<<phNo<<std::endl;
    }

    //updating the data of a key
    contacts["Jake"] = 12345678;

    //printing the whole Dictionary
    std::cout<<"\n"<<contacts<<std::endl;

    //removing an element from Dictionary
    auto removed_no = contacts.remove("Luthor");
    std::cout<<"Removed Value: "<<*removed_no<<std::endl;

    //adding another data
    contacts["Jini"] = 43998712;

    std::cout<<"\n"<<contacts<<std::endl;

    //clears whole Dictionary
    contacts.clear();

    //new features in ver: 1.1.0
    //using this features requires both key & value to be of std::string
    std::cout<<"\nNew in 1.1.0\n";

    //{name:id}
    Dictionary<std::string, std::string> data;

    //assign datas directly [appends to exisiting dictionary]
    data += "{Jake : 04}";
    std::string myData = "{Luke:75}"; //space is optional

    data += myData;

    std::cout<<data<<std::endl;

    //takes datas directly through streams
    //ways to enter :-
    //              1. {Linda : 81}
    //              2. Linda : 81
    std::cin>>data;

    //remove any value with key using -= operator
    //val stores the removed value
    auto val = data -= "Jake";

    std::cout<<data<<" "<<*val<<std::endl;
    
    //clearing all data using {}
    data = "{}";

    return 0;
}