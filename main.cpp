//
//  main.cpp
//  lab1
//
//  Created by Shakira Ali on 1/15/20.
//  Copyright © 2020 Shakira Ali. All rights reserved.
//

#include <iostream>
#include<stdlib.h> //to generate random numbers
#include <stdio.h>
#include <vector>
#include<assert.h>
#include<sys/time.h>
#include<time.h>
#define BILLION 1E9
using namespace std;

//Helper Functions:
//display the contents of vector
void PrintVector(vector<int> & intlist);

/* return true if elements in a is arranged in ascending order
   return false otherwise */
bool IsSorted (vector<int> a);
vector<int> GenerateRandomVector(int size);
void BubbleSort (vector <int> & intVector);
void SelectionSort(vector<int> & intVector);
void InsertionSort(vector<int> & intVector);
int gettimeofday(struct timeval *tv, struct timezone *tz);
int settimeofday(const struct timeval *tv, const struct timezone *tz);
int clock_getres(clockid_t clk_id, struct timespec *res);
void RecursiveBubbleSort (vector <int> & intVector, int end_index);
int smallestIndex(int intvector, int end, int index);
void recursiveSelectionSort(vector <int> & intvector, int end_index, int i=0);
void recursiveInsertionSort(vector <int> & intvector, int size);
void ReverseBubbleSort (vector <int> & intVector);
int main() {
    // insert code here...
    vector<int> intVector10=GenerateRandomVector(10);
       cout<<"Sorting Vector: ";
       PrintVector(intVector10);
       ReverseBubbleSort(intVector10);
       cout<<"After:";
       PrintVector(intVector10);
       if(IsSorted(intVector10))
           cout<<"Reverse BubbleSort passed testing!"<<endl;
       else
           cout<<"Reverse BubbleSort does not work!\n";
    vector<int> intVector=GenerateRandomVector(10);
    cout<<"Sorting Vector: ";
    PrintVector(intVector);
    BubbleSort(intVector);
    cout<<"After:";
    PrintVector(intVector);
    if(IsSorted(intVector))
        cout<<"BubbleSort passed testing!"<<endl;
    else
        cout<<"BubbleSort does not work!\n";
    vector<int> intVector2=GenerateRandomVector(10);
       cout<<"Sorting Vector: ";
       PrintVector(intVector2);
       SelectionSort(intVector2);
       cout<<"After:";
       PrintVector(intVector2);
       if(IsSorted(intVector2))
           cout<<"SelectionSort passed testing!"<<endl;
       else
           cout<<"SelectionSort does not work!\n";
    vector<int> intVector3=GenerateRandomVector(10);
    cout<<"Sorting Vector: ";
    PrintVector(intVector3);
    InsertionSort(intVector3);
    cout<<"After:";
    PrintVector(intVector3);
    if(IsSorted(intVector3))
        cout<<"InsertionSort passed testing!"<<endl;
    else
        cout<<"InsertionSort does not work!\n";
    //when intVector goes out of scope, its memory will be deallocated by its destructor
    cout<<"Now we will Measure and compare the running times of the three sorting algorithms"<<endl;

    struct timespec funcStart, funcEnd;
    
    double elapsed;
    cout<<"Let is start with the BubbleSort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    
    double sum=0;
    for (int i=0; i<30; i++) //repeat 30 times
    {
         
        //getto,epfday (&begin, NULL);
        clock_gettime(CLOCK_REALTIME, &funcStart);
        vector<int> intVector4=GenerateRandomVector(100); //generate a vector of size 100
        BubbleSort(intVector4);
        //gettimeofday(&t2, NULL);
        clock_gettime(CLOCK_REALTIME, &funcEnd);
        elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
        (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
        
        sum+=elapsed;//get the sum of the elapsed time to get the average running time of the bubblesort.
        cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
        
        
    }
    double average=0;
    average=(sum/30); //devide the sum of the elapsed time by 30 to get the average running time for the bubble sort
    cout<<"The average running time of the bubble sort is "<<average<<endl;
    cout<<"Testing runing time of selection Sort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    double sum1=0;
       for (int i=0; i<30; i++) //repeat 30 times
       {
            
           //getto,epfday (&begin, NULL);
           clock_gettime(CLOCK_REALTIME, &funcStart);
           vector<int> intVector4=GenerateRandomVector(100); //generate a vector of size 100
           SelectionSort(intVector4);
           //gettimeofday(&t2, NULL);
           clock_gettime(CLOCK_REALTIME, &funcEnd);
           elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
           (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
           
           sum1+=elapsed;//get the sum of the elapsed time to get the average running time of the selection sort.
           cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
           
           
       }
       double average1=0;
       average1=(sum1/30); //devide the sum of the elapsed time by 30 to get the average running time for the selection sort
       cout<<"The average running time of the selection sort is "<<average1<<endl;
    cout<<"Testing running time of the Insertion Sort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    double sum2=0;
    for (int i=0; i<30; i++) //repeat 30 times
    {
         
        //getto,epfday (&begin, NULL);
        clock_gettime(CLOCK_REALTIME, &funcStart);
        vector<int> intVector4=GenerateRandomVector(100); //generate a vector of size 100
        InsertionSort(intVector4);
        //gettimeofday(&t2, NULL);
        clock_gettime(CLOCK_REALTIME, &funcEnd);
        elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
        (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
        
        sum2+=elapsed;//get the sum of the elapsed time to get the average running time of the Insertion Sort.
        cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
        
        
    }
    double average2=0;
    average2=(sum2/30); //devide the sum of the elapsed time by 30 to get the average running time for the Insertion sort
    cout<<"The average running time of the Insertion sort is "<<average2<<endl;
    
    cout<<"Now we can test the recursive version of BubbleSort"<<endl;
    vector<int> intVector4=GenerateRandomVector(10);
       cout<<"Sorting Vector: ";
       PrintVector(intVector4);
       RecursiveBubbleSort(intVector4, intVector.size());
       cout<<"After:";
       PrintVector(intVector4);
       if(IsSorted(intVector4))
           cout<<"BubbleSort recursive version passed testing!"<<endl;
       else
           cout<<"BubbleSort recursive version does not work!\n";
    cout<<"Testing Running Time of Recursive BubbleSort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    double sum3=0;
       for (int i=0; i<30; i++) //repeat 30 times
       {
            
           //getto,epfday (&begin, NULL);
           clock_gettime(CLOCK_REALTIME, &funcStart);
           vector<int> intVector5=GenerateRandomVector(100); //generate a vector of size 100
           RecursiveBubbleSort(intVector5, intVector5.size());
           //gettimeofday(&t2, NULL);
           clock_gettime(CLOCK_REALTIME, &funcEnd);
           elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
           (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
           
           sum3+=elapsed;//get the sum of the elapsed time to get the average running time of the Recursive bubble sort.
           cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
        }
    double average3=0;
    average3=(sum3/30); //devide the sum of the elapsed time by 30 to get the average running time for the Reursive Bubble sort
    cout<<"The average running time of the recursive bubble sort is "<<average3<<endl;
    cout<<"Now we can test the recursive version of Selection Sort"<<endl;
       vector<int> intVector6=GenerateRandomVector(10);
          cout<<"Sorting Vector: ";
          PrintVector(intVector6);
          recursiveSelectionSort(intVector6, intVector.size());
          cout<<"After:";
          PrintVector(intVector6);
          if(IsSorted(intVector6))
              cout<<"Recursive SelectionSort passed testing!"<<endl;
          else
              cout<<"Recursive SelectionSort  does not work!\n";
           
    cout<<"Testing Running Time of Recursive SelectionSort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    double sum4=0;
       for (int i=0; i<30; i++) //repeat 30 times
       {
            
           //getto,epfday (&begin, NULL);
           clock_gettime(CLOCK_REALTIME, &funcStart);
           vector<int> intVector7=GenerateRandomVector(100); //generate a vector of size 100
           recursiveSelectionSort(intVector7, intVector7.size());
           //gettimeofday(&t2, NULL);
           clock_gettime(CLOCK_REALTIME, &funcEnd);
           elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
           (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
           
           sum4+=elapsed;//get the sum of the elapsed time to get the average running time of the Recursive bubble sort.
           cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
        }
    double average4=0;
    average4=(sum4/30); //devide the sum of the elapsed time by 30 to get the average running time for the Reursive Bubble sort
    cout<<"The average running time of the recursive selection sort is "<<average4<<endl;
  
       cout<<"Now we can test the recursive version of Recursive Insertion Sort"<<endl;
          vector<int> intVector8=GenerateRandomVector(10);
             cout<<"Sorting Vector: ";
             PrintVector(intVector8);
             recursiveInsertionSort(intVector8, intVector.size());
             cout<<"After:";
             PrintVector(intVector8);
             if(IsSorted(intVector8))
                 cout<<"Recursive Insertion Sort passed testing!"<<endl;
             else
                 cout<<"Recursive Selection Sort does not work!\n";
              
       cout<<"Testing Running Time of Recursive Insertion Sort"<<endl;
    cout<<"n      T(n) of BubbleSort (s)\n";
    double sum5=0;
       for (int i=0; i<30; i++) //repeat 30 times
       {
            
           //getto,epfday (&begin, NULL);
           clock_gettime(CLOCK_REALTIME, &funcStart);
           vector<int> intVector9=GenerateRandomVector(100); //generate a vector of size 100
           recursiveInsertionSort(intVector9, intVector9.size());
           //gettimeofday(&t2, NULL);
           clock_gettime(CLOCK_REALTIME, &funcEnd);
           elapsed = (funcEnd.tv_sec - funcStart.tv_sec)+
           (funcEnd.tv_nsec-funcStart.tv_nsec)/BILLION;
           
           sum5+=elapsed;//get the sum of the elapsed time to get the average running time of the Recursive bubble sort.
           cout<<i<<"\t"<<"\t"<<elapsed<<"\t"<<endl;
        }
    double average5=0;
    average5=(sum5/30); //devide the sum of the elapsed time by 30 to get the average running time for the Reursive Bubble sort
    cout<<"The average running time of the recursive insertion sort is "<<average5<<endl;
    return 0;
}

//display the contents of vector
/*
 @param intlist: the list to be sorted
 @precondition:there is already a vector filled with elements
 @post condition: the elements are outputed
 */
void PrintVector(vector<int> &intlist)
{
    for (int i=0; i<intlist.size(); i++)
        cout<<intlist.at(i)<<' ';
}

/* return true if elements in a is arranged in ascending order
   return false otherwise
 @param a: the vector of elements that will be checked if its sorted
 @precondition: there is a vector filled with elements already
 @post condition: true is returned if the vector of elements is sorted or else false
 */

bool IsSorted (vector<int> a)
{
    if (is_sorted(a.begin(), a.end()))
        return true;
    return false;
}
/* Generate an vector and fill it with random integers between 1 and 10,000
return the address of the array
@param size: the size of the array to be generated
@return the vector */
vector<int> GenerateRandomVector(int size)
{
    vector<int> a; //declared a vector
    for (int i=0; i<size; i++) //keep looping until size of vector is met
    {
        int number=rand()%1000+1; //this will generate a random number between 1 and 1000
        a.push_back(number); //push the random number into the vector
    }
    
    return a; //return generated vector
}
//input the vector and return a sorted vector by ordering through bubble passing in a for loop, comparing two numbers side by side over and over again
void BubbleSort (vector <int> & intVector) //its important to make the vector a reference so when it gets printed again the updated sorted vector is passed through the print vector function and the right new updated vector is printed instead of the old one
{
    
     
    for (int end_index=intVector.size(); end_index>0; end_index--) //outerloop goes through all the numbers
    {
        for (int i=0; i<=end_index-1; i++) //inner loop compares each of the numbers and swaps if the order is incorrect
        {
            if (intVector[i]>intVector[i+1])
                swap(intVector[i], intVector[i+1]);
        }
    
    }
}
void RecursiveBubbleSort (vector <int> & intVector, int end_index)
{
    if (end_index == 1)
        return;
     //size of the vector
    for (int i=0; i<end_index-1; i++)
    {
        if (intVector[i]>intVector[i+1])
            swap(intVector[i], intVector[i+1]);
    
    }
    RecursiveBubbleSort(intVector, end_index-1); //call the recursive bubble sort function over and over again by decrasing the size by 1 each time to decrease the amount of swaps and elements that we are working with since after each pass in a bubble sort, the largest element is already sorted
}
void SelectionSort(vector<int> & intVector)
{
    
    int minIndex;
    for (int i=0; i<intVector.size()-1; i++) //go through each element in the array to place the minimum value of the array in the right spot
    {      minIndex=i; //set the minIndex to the place in the array that we are working on.
        for (int k=i+1; k<intVector.size(); k++)
        {
            if (intVector[k]<intVector[minIndex]) //if second number is less than the first one, put the index of the second number as the minIndex or else do nothing. Go through all the numbers in the array to compare them to the minIndex
                minIndex=k;
        }
        if (minIndex!=i) //if the minIndex is not the same as the original, then swap the spot we are working on in the outerloop with the number of the new minIndex.
            swap(intVector[i], intVector[minIndex]); //intVector[i] is now the i-th smallest element.
        
    }
}
void InsertionSort(vector<int> & intVector)
{
    int value;
    for (int i=1; i<intVector.size(); i++) //traverse through the indexes in the array
    {
        value=intVector[i]; //save the number at the vector
        int j=i-1; //the index before index i;
        while (j>=0 && intVector[j]>value)//while the index has not selected a number outside of its bounds and the value of the index is greater than the saved value  move the element ahead of its current position
        {
            intVector[j+1]=intVector[j];
            j--; //decrement the j which stops if it reaches 0 or the value of j is not greater than the  saved value.
        
        }
    intVector[j++]=value;
    }
}

int smallestIndex(vector <int> & intvector, int end, int index)
{
    if (end==index) //return if end and the index are the same
        return end;
    int smallest=smallestIndex(intvector, end+1, index); //find the smallest index and it will be returned if end and index are teh same
    return (intvector[end]<intvector[smallest])? end:smallest; //compare the indexed element to the minimum and if the indexed value is smaller, return it
        
}
void recursiveSelectionSort(vector <int> & intvector, int end_index, int i)
{
    if (i==end_index) //return if the last element equals the index
        return;
    int smallest=smallestIndex(intvector, i, end_index-1); //find the minimum index
    if (smallest!=i)
        swap(intvector[smallest], intvector[i]); //swap if the smallest is not the index already
    recursiveSelectionSort(intvector, end_index, i+1); //recall until the end is reached for the index and everything is in order and it will stop being called
    
}
void recursiveInsertionSort(vector <int> & intvector, int size)
{
    if (size<2) //return if the size of the elements is only 1 or less, this is the base case as there is nothing to sort
        return;
    recursiveInsertionSort(intvector, size-1); //call the function and sort the elements as the size decreases by 1
    
    int key=intvector[size-1]; //make the last element the key
    int j=size-2; //make j the element before the key
    while (j>=0 && intvector[j]>key) //while the elements before the key are greater than it and the index is greater than 0, move the elements up by 1
    {
        intvector[j+1]=intvector[j];
        j--; //decrement the vector to go down the list and stop when the elements are no longer greater than the key
    }
    
    intvector[j+1]=key; //make the element that is in the right index the key
}

void ReverseBubbleSort (vector <int> & intVector) //its important to make the vector a reference so when it gets printed again the updated sorted vector is passed through the print vector function and the right new updated vector is printed instead of the old one
    {
        
         
        for (int end_index=0; end_index<intVector.size()-1; end_index++) //outerloop goes through all the numbers
        {
            for (int i=intVector.size()-1; i>0; i--) //inner loop compares each of the numbers and swaps if the order is incorrect
            {
                if (intVector[i]<intVector[i-1])
                    swap(intVector[i], intVector[i-1]);
            }
            
      
        }
    }

