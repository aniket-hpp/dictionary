#include <iostream>
#include <dictionary.h>

int main(){
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

    return 0;
}