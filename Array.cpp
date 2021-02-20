#include<iostream>  
  
using namespace std; 

class Array{
    private:
        int arr_capacity;
        int arr_size;
    public:
        //int * arr = (int *)malloc(sizeof(int));
        int * arr;
    //Constructor
    Array(){
        arr_capacity = 4;
        arr_size = 0;
    }
    //Deconstructer
    //Frees up memory space
    ~Array(){

    }
    
    int size(){
        return arr_size;
    }

    int capacity(){
        return arr_capacity;
    }
    
    bool is_empty(){
        return arr_size == 0 ? true : false;
    }

    int at(int index){
        try{
            return arr[index];
        }catch(const char * msg){
            cerr<<msg<<endl;
            return -1;
        }
    }

    void push(int item){
        return;
    }

    void insert(int index, int item){
        return;
    }

    void prepend(int item){
        return;
    }
    
    int pop(){
        return 1;
    }

    void delete_element(int index){
        return;
    }

    void remove(int item){
        return;
    }

    int find(int item){
        return 1;
    }

    private:
        void resize(int new_capacity){
            return;
        }
};

int main(){
    cout<<"Testing array implementation"<<endl;
    Array my_arr;
    cout<< my_arr.size()<<endl;
    cout<<my_arr.capacity()<<endl;
    return 1;
};