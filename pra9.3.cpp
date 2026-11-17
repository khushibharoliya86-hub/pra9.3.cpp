//Practical 9.3
#include<iostream>
using namespace std;

//PART A-STACK AND HEAP MEMORY
void stackAndHeap()
{
    cout<<"**************************************************\n";
    cout<<"  MEMORY ORGANIZATION ANAALYZER   \n";
    cout<<"**************************************************\n\n";
//declare local variable
    int stackInt=100;
//Dynamiccally memory
    int *heapInt=new int(250);

    cout<<"-----------Stack Memory-----------\n";
    cout<<"Local Variable Value\n"<<stackInt<<endl<<"Memory Address\n"<<&stackInt<<endl;
    cout<<endl;
    cout<<"-------------------------------------\n\n";
    cout<<"--------Dynamically Allocated Memory----------\n";
    cout<<"Allocated Value\n"<<*heapInt<<endl<<"Memory Address(Heap)\n"<<heapInt<<endl<<"Pointer Address(Stack)\n"<<&heapInt<<endl;
    cout<<endl;
    cout<<"-------------------------------------\n\n";

//safe memory
    delete heapInt;
    heapInt=nullptr;
}

//PART B-MULTI LEVEL REFERENCING
void multiLevelRef()
{
    int basevalue=100;
//Single-level address variable
    int *ptr1=&basevalue;
// Double-level address variable
    int **ptr2=&ptr1;
// Triple-level address variable
    int ***ptr3=&ptr2;
    cout<<"----------Multi-level Referencing---------------\n";
    cout<<"Original Value         :"<<*ptr1<<endl;
    cout<<"Single-level Address   :"<<&ptr1<<endl;
    cout<<"Double-level Address   :"<<&ptr2<<endl;
    cout<<"Triple-level Address   :"<<&ptr3<<endl;
    cout<<"Value Accessed through Three Levels  :"<<***ptr3<<endl<<endl;
    cout<<"------------------------------------------------\n\n";

}

//PART C-MEMORY SAFETY
void memorySafety(){
    cout<<"----------Memory Safety------------\n\n";
//null reference
int *nullPtr=nullptr;
cout<<"Null Reference\n";
if(nullPtr==nullptr){
    cout<<"UnSafe (Reference is NULL)\n";
}
cout<<"---------------------------------------\n\n";

//invalid reference
int *newptr= new int(50);
delete newptr;//releases memory
cout<<"Invalid Reference\n"<<"Memory Released Successfully\n"<<"Reference Invalid\n";
cout<<"Pointer Address:"<<newptr<<endl;
cout<<"---------------------------------------------\n\n";
newptr=nullptr;//safe state

//uninitialized address
int *uniniPtr;
cout<<"Uninitialized Address Variable\n";
cout<<"Pointer Address :"<<uniniPtr<<endl;
cout<<"Unsafe to Access\n";
cout<<"-------------------------------------------------\n\n";

}

// Part D: Observations & Comparisons
void displayObservations() {
    cout << "        PART D: OBSERVATIONS              " << endl;
    cout << "1. Stack Memory vs Dynamically Allocated Memory:" << endl;
    cout << "   - Stack memory is automatically allocated and deallocated based on scope." << endl;
    cout << "   - Dynamically allocated memory (Heap) requires explicit `new` and `delete` management.\n" << endl;

    cout << "2. Single-level vs Multi-level Referencing:" << endl;
    cout << "   - Single-level referencing directly tracks a variable's address." << endl;
    cout << "   - Multi-level referencing chains pointers across multiple levels (ptr -> ptr to ptr -> ptr to ptr to ptr), allowing indirect access\n" << endl;

    cout << "3. Safe vs Unsafe Memory References:" << endl;
    cout << "   - Safe references point to valid, active memory locations with proper initialization and bounds." << endl;
    cout << "   - Unsafe references (such as null pointers, dangling pointers after deletion, and uninitialized pointers) result in crashes or undefined behavior." << endl;
}





int main()
{
    //part A..........
    stackAndHeap();
    //part B............
    multiLevelRef();
    //part C.............
    memorySafety();
    //part D............
    displayObservations();


    return 0;
}

