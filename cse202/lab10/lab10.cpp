//Ryan Paglinawan
//CSE 202
//Homework 4

//I believe that this is working IDK
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>

class Mlist {
    public:
        Mlist();//creates the list
        T front();//returns the front of the list
        T end();//returns the end of the list and moves every x up one position;
        bool in(T x);//returns true if x is in the list and false otherwise
        bool empty();// returns true if the list is empty
        void addfront(T x);//in x to the back of the list
        void addend(T x);//in x to the back of the list
        void addorder(T x);//in x to an ordered list
        void removefront();//removes the front of the list
        void removeend();//removes the back of the list
        void remove(T x);//searches the list and removes the x with value n
    private:
        vector <T> mlist;
        void remove(typename vector<T>::iterator ix, T x);//uses an iterator and recursion to remove value n
        void addorder(typename vector<T>::iterator ix, T x);//uses an iterator and recursion to in value n in an ordered list
}; // Mlist
template<typename T>
Mlist<T>::Mlist(){
        //default constructor
    }
template<typename T>
T Mlist<T>::front(){
    return *(mlist.begin());
}
template<typename T>
T Mlist<T>::end(){
    return *(--mlist.end());
}
template<typename T>
bool Mlist<T>::in(T x){
    for (int i = 0; i < mlist.size(); ++i){
        if (x == mlist[i]) {
            return true;
        }
        else {
            return false;
        }
    }
}
template<typename T>
bool Mlist<T>::empty(){
    if (mlist.end()) {
        return true;
    }
    else {
        return false;
    }
}//done
template<typename T>
void Mlist<T>::addfront(T x){
    mlist.insert(mlist.begin(), x);
}//done
template<typename T>
void Mlist<T>::addend(T x){
    mlist.insert(mlist.end(), x);
}//done
template<typename T>
void Mlist<T>::removefront(){
    mlist.erase(mlist.begin());
}
template<typename T>
void Mlist<T>::removeend(){
    mlist.erase(--mlist.end());
    mlist.pop_back();
}
template<typename T>
void Mlist<T>::remove(T x){
    if(mlist.size() > 0) {
        remove(mlist.begin(), x);
    }
}
template<typename T>
 void Mlist<T>::remove(typename vector<T>::iterator ix, T x){
	if (ix == mlist.end()){
	   return;
  }
	else {
	   if (*ix == x) {
	      mlist.erase(ix);
	       remove(ix, x);
       }
       else {
         remove(++ix, x);
       }
    }
}
template<typename T>
void Mlist<T>::addorder(T x){
	typename vector<T>::iterator ix;
	ix = mlist.begin();
	while( (ix!= mlist.end()) && (x > *ix)){
		ix++;
	}
	mlist.insert(ix, x);
}

int main()
{
 Mlist<int> test1=Mlist<int>() ;
 test1.addfront(5);
 test1.addfront(7);
 test1.addend(4);
 test1.remove(7);
 cout << test1.front()<< endl;
 cout << test1.end()<< endl;

 Mlist<string> test2= Mlist<string>() ;
 test2.addfront("John");
 test2.addfront("Paul");
 test2.addfront("Mary");
 test2.addend("Kate");
 test2.remove("Paul");
 cout << test2.front()<< endl;
 cout << test2.end()<< endl;
}
