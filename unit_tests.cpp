/*
 *  unit_tests.cpp
 *  JOsh Lamothe
 *  DATE CREATED
 * 6/8/2022 
 *
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  testing of the functions in the char linked list
 *
 */
#include <iostream>
#include "CharLinkedList.h"

using namespace std;

int main()
{

    cout << "3rd constructor" << endl;
    char array[3] = {'a' , 'c' , 'e'};
    CharLinkedList test = CharLinkedList(array, 3);
    string testing = test.toString();
    cout << testing << endl;



    cout << "empty construct test" << endl;
    CharLinkedList empty = CharLinkedList();
    string empty_result = empty.toString();
    cout << empty_result << endl;
    bool empty_status = empty.isEmpty();
    if(empty_status){
        cout << "true" << endl;
    }
    int empty_size = empty.size();
    cout << empty_size << endl;

    cout << "single letter construct test" << endl;
    CharLinkedList single = CharLinkedList('A');
    string single_result = single.toString();
    cout << single_result << endl;
    bool single_status = single.isEmpty();
    if (single_status)
    {
        cout << "true" << endl;
    }
    

    cout << "three letter construct test" << endl;
    char characters[3] = {'a','c','e'};
    CharLinkedList three = CharLinkedList(characters, 3);
    string three_result = three.toString();
    cout << three_result << endl;

    cout << "testing alpha" << endl;
    three.insertInOrder('c');
    string ace_b = three.toString();
    cout << ace_b << endl;



    cout << "testing size" << endl;
    int third_size = three.size();
    cout << third_size << endl;
    


    cout << "testing first and last" <<endl;
    char first_of_three = three.first();
    //empty.first();
    cout << first_of_three << endl;
    //empty.last();
    char last_of_three = three.last();
    cout << last_of_three << endl;

    cout << "testing element at" << endl;
    char element_at_three = three.elementAt(1);
    cout << element_at_three << endl;

    cout << "copying three here" << endl;
   CharLinkedList copy_three = three;
    string copy_print = copy_three.toString();
    cout << copy_print << endl;
   

    cout << "testing push at front" << endl;
    three.pushAtFront('p');
    string three_with_p = three.toString();
    cout << three_with_p << endl;


    cout << "testing push at back" << endl;
    three.pushAtBack('d');
    string three_wit_d = three.toString();
    cout << three_wit_d << endl;

    cout << "insert at test" <<endl;
    three.insertAt('l',1);
    string three_placed = three.toString();
    cout << three_placed << endl;

    cout << "replace at test" <<endl;
    three.replaceAt('y',3);
    string three_played = three.toString();
    cout << three_played << endl;


    cout << "testing pop from front" << endl;
    three.popFromFront();
    string three_layed = three.toString();
    cout << three_layed << endl;

    cout << "testing pop from back" << endl;
    three.popFromBack();
    string three_laye = three.toString();
    cout << three_laye << endl;

    cout << "testing remove at" << endl;
    three.removeAt(2);
    string three_lae = three.toString();
    cout << three_lae << endl;

   single.removeAt(0);
   string single_empty = single.toString();
   cout << single_empty << endl;

    cout <<"testing operator" << endl;
    single = three;
    string single_as_three = single.toString();
    cout << single_as_three << endl;

  
    single.pushAtBack('c');
    string single_c = single.toString();
    cout << single_c << endl;


       string three_post_copy = three.toString();
       cout << three_post_copy << endl;


    cout << "testing concat" << endl;
    CharLinkedList concat = CharLinkedList('a');

    three.concatenate(&concat);
    string concate = three.toString();
    cout << concate << endl;


    cout << "testing concatenate" << endl;
    single.concatenate(&three);
    string concate_single = single.toString();
    cout << concate_single << endl;


    cout << "clear testing" << endl;
    three.clear();
    string three_clear = three.toString();
    cout << three_clear << endl;
    bool clear_status = three.isEmpty();
    if (clear_status)
    {
        cout << "three is now empty" << endl;
    }
    
   cout << "testing copy constructor " << endl;
   string copy_three_2 = copy_three.toString();
   cout << copy_three_2 << endl;

    cout << "meow " << endl;


    char comp[7] = {'c','o','m', 'p' ,' ','1' , '5'};
    CharLinkedList comp_test = CharLinkedList(comp, 7);
    string testing_test = comp_test.toString();
    cout << testing_test << endl;


    cout << "end" << endl;

   return 0;


}   
