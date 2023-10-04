# Dictionary in C++

An implementation of Dictionary in C++.</br>
>Dictionary is one of the important Data Structures that is usually used to store data in the key-value format. Each element presents in a dictionary data structure compulsorily have a key and some value
>associated with that particular key. In other words, we can also say that Dictionary data structure is used to store the data in key-value pairs.

Checkout `Example.cpp` for how to use it.

# Installation
Simply copy the `.h` file in your compiler's include path.
1. Windows- `C:\msys64\mingw64\include` or `C:\MinGW\include`
2. MacOS/Linux- `/usr/local/include/`

# Dependencies

1. `std::vector`

# Uses-
1. Declaration-
```c++
Dictionary<key-type, value-type> <variable-name>
```
<br/>For example-
```c++
Dictionary<std::string, int> datas;
```
This above declaration is for making a string to int dictionary.

2. Operations-
- Inserting/Appending datas into dictionary:
<br/>Dictionary library has different ways to append datas in it.
```c++

Dictionary<std::string, int> datas;

//using append method for different data types
datas.append("Jake", 24);

//using operator, but only for std::string type key : value pair
Dictionary<std::string, std::string> name_id;
name_id += "{Luke : 43}";

//using indexing
datas["Luke"] = 73;

//using std::cin or std::istream
//in console: {Linda : 90} or Linda : 90
std::cin>>datas;

```

- Removing datas from dictionary:<br/>
```c++

//to remove the value
int* val = datas.remove("Jake");

//if key "Jake" exists in the dictionary then pointer *val stores the address of the value
//if the key doesn't exists then the pointer *val is set to NULL

//to retrieve the value
if(val){std::cout<<*val;}

//removing value using operator
int *val = datas -= "Jake";
//this works similarly to the previous one
//if you don't want the value then

datas -= "Jake"; //will work too

```

- Retrieving stored data using key:<br/>
```c++

//getting data using indexing
auto val = datas["Jake"]; //val = 24

//for unknown keys
auto keys = datas.getKeys(); //returns a vector<key-data-type>

//access each element
for(auto key : keys)
    auto value = datas[key];

//print the whole dictionary using:
std::cout<<datas<<std::endl; //prints {...pairs...}

//getting the whole dictionary in string format
std::stringstream ss; //#include <sstream>
ss<<datas;
std::string str_dictionary = ss.str();

```

- Updating a data:
```c++

//using indexing
datas["Jake"] = 55; //24 to 55

```

# Version
>1.0.0
