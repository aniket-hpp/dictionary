/*     
    An implementation of Dictionary in C++.
    #ver=1.1.0

      Created By: Aniket Biswas
      Github: https://github.com/thesmartaniket
      LinkedIn: https://www.linkedin.com/in/thesmartaniket/

    See Example.cpp for more.
*/

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <iostream>
#include <vector>
#include <exception>

/**
 * @name Dictionary
 * @brief
 * A class to create & store unordered datas using key-value pair.
 * @param <key-data-type
 * @param <value-data-type>
*/
template <typename _key,typename _value>
class Dictionary{
private:
    /**
     * @name Pair
     * @brief
     * A struct to create ket-value pair using linked list.
    */
    struct Pair{
        _key key;
        _value value;
        Pair *next;

        Pair(Pair* next = NULL){this->next = next;}
        Pair(_key key, Pair* next = NULL){
            this->key = key;
            this->next = next;
        }

        Pair(_key key, _value value, Pair* next = NULL){
            this->key = key;
            this->value = value;
            this->next = next;
        }

        bool isMyKey(_key& key){return this->key == key;}

        //[NOT IMPLEMENTED YET]
        // Pair* operator ++ (int){return this->next;}
        // bool operator != (Pair __another){return this->next != __another;}
    };

    std::vector<std::string> split_str(std::string& , const char );

    /**
     * Pointers for linked list 
    */
    Pair* front;
    Pair* rear;

public:
    /**
     * @name Constructor
     * @brief
     * Creates an empty Dictionary
     * @param void
     * @return void
    */
    Dictionary(void){front = rear = NULL;}

    /**
     * @name Constructor
     * @brief
     * Creates 1 Dictionary element with an extension to add new Pairs next to it.
     * @param key
     * @param value
     * @param Pair*
     * @return void
    */
    Dictionary(_key key, _value value, Pair* next = NULL){
        front = rear = new Pair(key, value, next);
    }

    /**
     * @name Constructor
     * @brief
     * Creates an Dictionary which points to another one
     * @param Dictionary
     * @return void
    */
    Dictionary(Dictionary& __dict){front = rear = __dict.getHead();}

    /**
     * @name Destructor
     * @param void
     * @return void
    */
    ~Dictionary(void){clear();}

    friend std::ostream& operator << (std::ostream& cout, Dictionary& __dict){
        cout<<"{";

        Pair* _cpy = __dict.getHead();
        while(_cpy != NULL){
            cout<<_cpy->key<<" : "<<_cpy->value<<((_cpy->next)?", ":"");
            _cpy = _cpy->next;
        }

        cout<<"}";

        return cout;
    }

    friend std::istream& operator >> (std::istream& cin, Dictionary& __dict){
        std::string __f_str;
        std::string __str;

        std::getline(cin, __str);

        if(__str[0] != '{' && __str[__str.length() - 1] != '}'){
            __f_str.push_back('{');
            __f_str.append(__str);
            __f_str.push_back('}');
        }else{
            __f_str = __str;
        }

        __dict += __f_str;

        return cin;
    }

    void operator += (std::string );
    void operator += (const char* );
    void operator = (const char* );
    _value* operator -= (_key );
    _value& operator [](_key key);

    /**
     * @name haveKey()
     * @brief
     * Get the Pair struct which matches with the Key.
     * @param key
     * @return Pair*
    */
    Pair* haveKey(_key key);

    /**
     * @name append()
     * @brief
     * Inserts a new Pair at the end of the list.
     * @param key
     * @param value
     * @return void
    */
    void append(_key key, _value value);

    /**
     * @name remove()
     * @brief
     * Removes the first ocuurence of key-value Pair from the list if it presents.
     * @param key
     * @return value*
    */
    _value* remove(_key key);

    /**
     * @name getKeys()
     * @brief
     * Get all the keys present in current Dictionary.
     * @param void
     * @return std::vector<key-data-type>
    */
    std::vector<_key> getKeys(void);

    /**
     * @name getHead()
     * @brief
     * Get the first node of Dictionary.
     * @param void
     * @return Pair*
    */
    Pair* getHead(void){return front;}

    /**
     * @name isEmpty()
     * @brief
     * Check if Dictionary is empty or not.
     * @param void
     * @return std::vector<keyValue>
    */
    bool isEmpty(){return front == NULL;}

    /**
     * @name clear()
     * @brief
     * Removes all pair from Dictionary.
     * @param void
     * @return void
    */
   void clear(void);
};

template <typename _key, typename _value> 
_value& Dictionary<_key, _value>::operator [](_key key){
    if(front == NULL){
        front = rear = new Pair(key);
        return front->value;
    }

    Pair* test = haveKey(key);
    if(test){return test->value;}

    rear->next = new Pair(key);
    rear = rear->next;

    return rear->value;
}

template <typename _key, typename _value> 
typename Dictionary<_key, _value>::Pair* Dictionary<_key, _value>::haveKey(_key key){
    Pair* _cpy = this->front;

    while(_cpy != NULL){
        if(_cpy->key == key)
            return _cpy;

        _cpy = _cpy->next;
    }

    return NULL;
}

template <typename _key, typename _value> 
void Dictionary<_key, _value>::append(_key key, _value value){
    if(front != NULL){
        Pair* __test = haveKey(key);

        if(__test){
            __test->value = value;
            return;
        }

        rear->next = new Pair(key, value);
        rear = rear->next;

        return;
    }

    front = rear = new Pair(key, value);
}

template <typename _key, typename _value> 
_value* Dictionary<_key, _value>::remove(_key key){
    if(front != NULL){
        _value __x;

        if(front->key == key){
            Pair* __tmp = front;
            front = front->next;

            __x = __tmp->value;

            delete __tmp;
            return new _value(__x);
        }

        Pair *__c_cpy = front;
        Pair* __p_cpy = NULL;

        while(__c_cpy != NULL){
            if(__c_cpy->key == key)
                break;

            __p_cpy = __c_cpy;
            __c_cpy = __c_cpy->next;
        }

        if(__c_cpy){
            if(__c_cpy == rear){
                Pair* __tmp = front;
                while(__tmp->next->next != NULL){
                    __tmp = __tmp->next;
                }

                rear = __tmp;
            }

            Pair* __tmp = __c_cpy;
            __p_cpy->next = __c_cpy->next;

            __x = __tmp->value;

            delete __tmp;
            return new _value(__x);
        }
    }

    return NULL;
}

template <typename _key, typename _value> 
std::vector<_key> Dictionary<_key, _value>::getKeys(){
    std::vector<_key> __tmp_v;

    if(front == NULL){return __tmp_v;}

    Pair* __tmp = front;

    while(__tmp != NULL){
        __tmp_v.push_back(__tmp->key);
        __tmp = __tmp->next;
    }

    return __tmp_v;
}

template <typename _key, typename _value> 
void Dictionary<_key, _value>::clear(){
    while(front != NULL){
        Pair* __tmp = front;
        front = front->next;
        delete __tmp;
    }
}

template <typename _key, typename _value>
std::vector<std::string>  Dictionary<_key, _value>::split_str(std::string& __str, const char __split_chr){
    std::vector<std::string> _vec_str;
    std::string _split_str;
    bool __flag_split_chr_found = false;

    for(auto ch = __str.begin(); ch != __str.end(); ch++){
        if(*ch != ' '){
            if(*ch == '{'){
                continue;
            }else if(*ch == __split_chr){
                _vec_str.push_back(_split_str);
                _split_str.clear();
                __flag_split_chr_found = true;
            }else if(*ch == '}'){
                _vec_str.push_back(_split_str);
            }else{
                _split_str.push_back(*ch);
            }
        } 
    }

    if(!__flag_split_chr_found){
        throw std::invalid_argument("Incomplete/Invalid dictionary: All dictionary must have ':' to separate the key, value pair.");
        exit(-1);
    }

    return _vec_str;
}

template <typename _key, typename _value>
void Dictionary<_key, _value>::operator += (std::string __str){
    if(__str[0] == '{' && __str[__str.length() - 1] == '}'){
        auto vec = split_str(__str, ':');

        append(vec[0], vec[1]);
    }else{
        throw std::invalid_argument("Incomplete/Invalid dictionary: All dictionary must start with '{' and end with '}'.");
        exit(-1);
    }
}

template <typename _key, typename _value>
void Dictionary<_key, _value>::operator = (const char* __str){
    if(__str[0] == '{' && __str[1] == '}'){
        this->clear();
        return;
    }

    throw std::invalid_argument("Incomplete/Invalid dictionary: Wrong assignment'.");
    exit(-1);
}

template <typename _key, typename _value>
void Dictionary<_key, _value>::operator += (const char* __str){
    *this += std::string(__str); 
}

template <typename _key, typename _value>
_value* Dictionary<_key, _value>::operator -= (_key __key){
    return remove(__key);
}

#endif
