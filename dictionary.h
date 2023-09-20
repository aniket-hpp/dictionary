#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <iostream>
#include <vector>

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

        // Pair* operator ++ (int){return this->next;}
        // bool operator != (Pair __another){return this->next != __another;}
    };

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
        front = new Pair(key, value, next);
    }

    /**
     * @name Constructor
     * @brief
     * Creates an Dictionary which points to another one
     * @param Dictionary
     * @return void
    */
    Dictionary(Dictionary& __dict){front = __dict.getHead();}

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
     * Removes the first key matching Pair from the list if it presents.
     * @param key
     * @return void
    */
    void remove(_key key);

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
void Dictionary<_key, _value>::remove(_key key){
    if(front != NULL){
        if(front->key == key){
            Pair* __tmp = front;
            front = front->next;

            delete __tmp;
            return;
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
            Pair* __tmp = __c_cpy;
            __p_cpy->next = __c_cpy->next;

            delete __tmp;
        }
    }
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

template <typename _key, typename _value> void Dictionary<_key, _value>::clear(){
    while(front != NULL){
        Pair* __tmp = front;
        front = front->next;
        delete __tmp;
    }
}

#endif