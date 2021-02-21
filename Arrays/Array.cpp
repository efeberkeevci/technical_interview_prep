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
        arr = new int[arr_capacity];
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
        if(index>(arr_size-1)){
            cerr<<"Index out of bound"<<endl;
            return -1;
        }else{
            return arr[index];
        }
    }

    void push(int item){
        if(arr_size == arr_capacity){
            resize(arr_capacity*2);
        }
        arr[arr_size] = item;
        arr_size++;
        return;
    }

    void insert(int index, int item){
        if(arr_size == arr_capacity){
            resize(arr_capacity*2);
        }
        for(int i = arr_size-1; i>=index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = item;
        arr_size++;
        return;
    }

    void prepend(int item){
        push(item);
        return;
    }
    
    int pop(){
        int popped_element = arr[arr_size-1];
        //TODO: How to remove the element
        arr_size--;
        return popped_element;
    }

    void delete_element(int index){
        for(int i = index; i<arr_size-1; i++){
            arr[i] = arr[i+1];
        }
        arr_size--;
        return;
    }

    void remove(int item){
        for(int i = 0; i<arr_size; i++){
            if(arr[i] == item){
                delete_element(i);
                i--;
            }
        }
        return;
    }

    int find(int item){
        for(int i = 0; i<arr_size; i++){
            if(arr[i] == item){
                return i;
            }
        }
        return -1;
    }

    private:
        void resize(int new_capacity){
            int * double_sized_array = new int[new_capacity];
            for(int i = 0; i<arr_size; i++){
                double_sized_array[i] = arr[i];
            }
            //TODO: Check how to free space from old array
            arr = double_sized_array;
            arr_capacity = new_capacity;
            return;
        }
};
void print_array(Array my_arr){
    for(int i = 0; i<my_arr.size(); i++){
        cout<<"Index " <<i<<" : "<<my_arr.at(i)<<endl;
    }
}
int main(){
    cout<<"Testing array implementation"<<endl;

    Array my_arr;

    //Check array is_empty
    cout<<"Array size: "<<my_arr.size()<<endl;
    cout<<"Is empty: "<<my_arr.is_empty()<<endl;

    cout<<"Pushing elements to the array"<<endl;
    my_arr.push(12);
    my_arr.push(244);
    my_arr.push(244);
    my_arr.push(244);
    my_arr.push(244);
    my_arr.push(243);
    my_arr.push(249192);
    my_arr.insert(my_arr.size(),99);

    //Basic array push and insert success check
    print_array(my_arr);
    cout<<"Array size: "<<my_arr.size()<<endl;
    cout<<"Is empty: "<<my_arr.is_empty()<<endl;
    
    //Single element delete
    cout<<"Deleting element at index 3"<<endl;
    my_arr.delete_element(3);
    print_array(my_arr);
    
    //Delete multiple occurences of a value
    cout<<"Deleting all 244 in array"<<endl;

    my_arr.remove(244);
    print_array(my_arr);





    return 1;
};