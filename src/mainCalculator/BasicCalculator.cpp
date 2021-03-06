#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEFAULT_ARRAY_SIZE 10
#define DEFAULT_INCREMENT DEFAULT_ARRAY_SIZE
#define MAX_NUMBER_LENGTH 10

template <typename T>
class Vector{
    T *data;
    char length;
    char currentIndex;

public:
    Vector();
    ~Vector();
    char resize(char size = 0);
    T *at(int index);
    char push(T value);
    char pop();
    char size();
};

template <typename T>
Vector<T>::Vector() : currentIndex(0){
    //data = new T;
    data = (T *)malloc(DEFAULT_ARRAY_SIZE * sizeof(T));
    if (!data)
        length = 0;
    else
        length = DEFAULT_ARRAY_SIZE;
}
template <typename T>
Vector<T>::~Vector(){
    delete data;
}
template <typename T>
T *Vector<T>::at(int index){
    if (index < 0 || index >= length)
        return NULL;
    return &data[index];
}
template <typename T>
char Vector<T>::resize(char size){
    if (size == -1)
        size = DEFAULT_ARRAY_SIZE;
    if (!data){
        data = (T *)malloc(size * sizeof(T));
    }else{
        data = (T *)realloc(data, size * sizeof(T));
    }
    if (!data){
        length = 0;
        return 0;
    }else{
        length = size;
        return size;
    }
}

template <typename T>
char Vector<T>::size()
{
    return currentIndex;
}

template <typename T>
char Vector<T>::push(T value)
{
    if (currentIndex >= length)
    {
        if (!resize(length + DEFAULT_INCREMENT))
            return 0;
    }

    data[currentIndex] = value;
    return ++currentIndex;
}

template <typename T>
char Vector<T>::pop(){
    if (currentIndex > 0){
        return --currentIndex;
    }
    return 0;
}

char* reverseString(const char* string,char length){
    char* tmp = new char;

    tmp[length]='\0';
    for (int i = 0; i < length; ++i) {
        tmp[i]=string[length-1-i];
    }
    return tmp;
}

double basic(const char* eq,char start,char end, bool deg,const double* vars){
    if(end<=start)
        return NAN;

    Vector<double> numbers;
    Vector<char> plusIndex;
    Vector<char> multIndex;
    Vector<char> powIndex;

    char* tmp = new char;
    char tmpc=0;
    char* reversed;

    for (char i = end-1; i >= start; --i) {
        if((eq[i]>47 && eq[i]<58) || eq[i]==46){
            if(tmpc>=MAX_NUMBER_LENGTH)
                return NAN;

            tmp[tmpc++]=eq[i];
        }else if(eq[i] == '+'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                plusIndex.push(numbers.push(strtod(reversed,nullptr)));
                delete reversed;
                tmpc=0;
            }else if(i==end-1){
                return NAN;
            }else if(plusIndex.size() == 0 || (plusIndex.size() > 0 && numbers.size() != *plusIndex.at(plusIndex.size() - 1))){
                plusIndex.push(numbers.size());
            }
        }else if(eq[i] == '-'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                plusIndex.push(numbers.push(-strtod(reversed,nullptr)));
                delete reversed;
                tmpc=0;
            }else if(i==end-1){
                return NAN;
            }else if(plusIndex.size() == 0 || (plusIndex.size() > 0 && numbers.size()!= *plusIndex.at(plusIndex.size() - 1))){
                *numbers.at(numbers.size() - 1)*=-1;
                plusIndex.push(numbers.size());
            }else{
                *numbers.at(numbers.size() - 1)*=-1;
            }
        }else if(eq[i]=='*'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                multIndex.push(numbers.push(strtod(reversed,nullptr)));
                delete reversed;
                tmpc=0;
            }else if(i==end-1 || i==start){
                return NAN;
            }else if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()){
                plusIndex.pop();
                multIndex.push(numbers.size());
            }else{
                multIndex.push(numbers.size());
            }
        }else if(eq[i]=='/'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                multIndex.push(numbers.push(1.0/strtod(reversed,nullptr)));
                delete reversed;
                tmpc=0;
            }else if(i==end-1 || i==start){
                return NAN;
            }else if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()){
                plusIndex.pop();
                (*numbers.at(numbers.size() - 1)) = 1 / (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
            }else{
                (*numbers.at(numbers.size() - 1)) = 1 / (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
            }
        }else if(eq[i]=='^'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                multIndex.push(numbers.push(strtod(reversed,nullptr)));
                powIndex.push(numbers.size());
                delete reversed;
                tmpc=0;
            }else if(i==end-1 || i==start){
                return NAN;
            }else if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                plusIndex.pop();
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            }else{
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            }
        
        }
        else if(eq[i]=='_'){
            if(tmpc>0){
                reversed=reverseString(tmp,tmpc);
                if(!reversed)
                    return NAN;
                multIndex.push(numbers.push(1.0/strtod(reversed,nullptr)));
                powIndex.push(numbers.size());
                delete reversed;
                tmpc=0;
            }else if(i==end-1 || i==start){
                return NAN;
            }else if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                plusIndex.pop();
                (*numbers.at(numbers.size() - 1)) = 1 / (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            }else{
                (*numbers.at(numbers.size() - 1)) = 1 / (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            }
        }
        else if(eq[i]==')'){
            char numClosingBrackets=0;
            char foundMatching=0;
            for(char j=i-1;j>=start;--j){
                if(eq[j]==')')
                    ++numClosingBrackets;
                else if(eq[j]=='(' && numClosingBrackets>0)
                    --numClosingBrackets;
                else if(eq[j]=='(' && numClosingBrackets==0){
                    if(!foundMatching) {
                        numbers.push(basic(eq, j + 1, i, deg,vars));
                        i = j;
                        foundMatching = 1;
                    }
                }
            }
            if(!foundMatching)
                return NAN;
        }else{   
        if(i>2 && eq[i]=='n' && eq[i-1]=='i' && eq[i-2]=='s' && eq[i-3]=='a'){
                if(numbers.size())
                {
                    if(deg)
                        *numbers.at(numbers.size()-1) = asin(*numbers.at(numbers.size()-1))*180/M_PI;
                    else
                        *numbers.at(numbers.size()-1) = asin(*numbers.at(numbers.size()-1));
                }
                    //*numbers.at(numbers.size()-1) = asin(*numbers.at(numbers.size()-1));
                i-=3;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='n' && eq[i-1]=='i' && eq[i-2]=='s'){//3.14159
                if(numbers.size()){
                    if(deg)
                        *numbers.at(numbers.size()-1) = sin(*numbers.at(numbers.size()-1)*M_PI/180);
                    else
                        *numbers.at(numbers.size()-1) = sin(*numbers.at(numbers.size()-1));
                } 
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>2 && eq[i]=='s' && eq[i-1]=='o' && eq[i-2]=='c' && eq[i-3]=='a'){
                if(numbers.size()){
                    if(deg)
                        *numbers.at(numbers.size()-1) = acos(*numbers.at(numbers.size()-1))*180/M_PI;
                    else
                        *numbers.at(numbers.size()-1) = acos(*numbers.at(numbers.size()-1));
                }
                    //*numbers.at(numbers.size()-1) = acos(*numbers.at(numbers.size()-1));
                i-=3;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='s' && eq[i-1]=='o' && eq[i-2]=='c'){
                if(numbers.size()){
                    if(deg)
                        *numbers.at(numbers.size()-1) = cos(*numbers.at(numbers.size()-1)*M_PI/180);
                    else
                        *numbers.at(numbers.size()-1) = cos(*numbers.at(numbers.size()-1));
                }
                    //*numbers.at(numbers.size()-1) = cos(*numbers.at(numbers.size()-1));
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>2 && eq[i]=='n' && eq[i-1]=='a' && eq[i-2]=='t' && eq[i-3]=='a'){
                if(numbers.size()){
                    if(deg)
                        *numbers.at(numbers.size()-1) = atan(*numbers.at(numbers.size()-1))*180/M_PI;
                    else
                        *numbers.at(numbers.size()-1) = atan(*numbers.at(numbers.size()-1));
                }
                    //*numbers.at(numbers.size()-1) = atan(*numbers.at(numbers.size()-1));
                i-=3;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='n' && eq[i-1]=='a' && eq[i-2]=='t'){
                if(numbers.size()){
                    if(deg)
                        *numbers.at(numbers.size()-1) = tan(*numbers.at(numbers.size()-1)*M_PI/180);
                    else
                        *numbers.at(numbers.size()-1) = tan(*numbers.at(numbers.size()-1));
                }
                    //*numbers.at(numbers.size()-1) = tan(*numbers.at(numbers.size()-1));
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>0 && eq[i]=='n' && eq[i-1]=='l'){
                if(numbers.size())
                    *numbers.at(numbers.size()-1) = log(*numbers.at(numbers.size()-1));
                i-=3;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='g' && eq[i-1]=='o' && eq[i-2]=='l'){
                if(numbers.size())
                    *numbers.at(numbers.size()-1) = log10(*numbers.at(numbers.size()-1));
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='s' && eq[i-1]=='b' && eq[i-2]=='a'){
                if(numbers.size())
                    *numbers.at(numbers.size()-1) = abs(*numbers.at(numbers.size()-1));
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }else if(i>1 && eq[i]=='c' && eq[i-1]=='a' && eq[i-2]=='f'){
                if(numbers.size())
                    *numbers.at(numbers.size()-1) = tgamma(*numbers.at(numbers.size()-1)+1);
                i-=2;
                if(plusIndex.size()>0 && *plusIndex.at(plusIndex.size()-1) == numbers.size()) {
                    plusIndex.pop();
                }
            }

            else if(i>0 && eq[i]=='i' && eq[i-1]=='p'){
                numbers.push(M_PI);
                i-=1;
            }else if(eq[i]=='e'){
                numbers.push(M_E);

            }else if(i>1 && eq[i]=='s' && eq[i-1]=='n' && eq[i-2]=='a'){
                if(vars)
                    numbers.push(vars[0]);
                else
                    numbers.push(NAN);
                i-=2;
            }
            else
                return NAN;
        }          
    }

    if(tmpc>0)
    {
        reversed=reverseString(tmp,tmpc);
        if(!reversed)
            return NAN;
        numbers.push(strtod(reversed,nullptr));
        delete reversed;
        tmpc=0;
    }


    if(numbers.size()==0)
        return NAN;


    if(powIndex.size() > 0) {
        for (char i = powIndex.size()-1;i>=0; --i){

            if(*powIndex.at(i)>= numbers.size())
                return NAN;
            (*numbers.at(*powIndex.at(i)-1)) = pow((*numbers.at(*powIndex.at(i))),(*numbers.at(*powIndex.at(i)-1)));
            (*numbers.at(*powIndex.at(i))) = 1;
        }
    }

    if(multIndex.size() > 0) {
        for (char i = multIndex.size()-1;i>=0  ; --i){
            if(*multIndex.at(i)>= numbers.size())
                return NAN;
            (*numbers.at(*multIndex.at(i)-1)) *= (*numbers.at(*multIndex.at(i)));
        }
    }

    double result=*numbers.at(0);
    if(numbers.size()>1) {
        for (char i = 0; i < plusIndex.size(); ++i) {
            result += *numbers.at(*plusIndex.at(i));
        }
    }
    delete tmp;

    return result;
}