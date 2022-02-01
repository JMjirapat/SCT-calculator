#include <iostream>
#include <vector>
#include <cmath>
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
    data = (T *)malloc(DEFAULT_ARRAY_SIZE * sizeof(T));
    if (!data)
        length = 0;
    else
        length = DEFAULT_ARRAY_SIZE;
}
template <typename T>
Vector<T>::~Vector(){
    free(data);
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
    auto tmp = (char*)malloc((length+1)*sizeof(char));
    if(!tmp)
        return nullptr;

    tmp[length]='\0';
    for (int i = 0; i < length; ++i) {
        tmp[i]=string[length-1-i];
    }
    return tmp;
}

float basic(const char* eq,char start,char end,const float* vars){
    if(end<=start)
        return NAN;

    Vector<float> numbers;
    Vector<char> plusIndex;
    Vector<char> multIndex;
    Vector<char> powIndex;

    auto tmp = (char*)malloc(MAX_NUMBER_LENGTH*sizeof(char));
    if(!tmp)
        return NAN;
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
                free(reversed);
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
                free(reversed);
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
                free(reversed);
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
                multIndex.push(numbers.push((float)1/strtod(reversed,nullptr)));
                free(reversed);
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
                free(reversed);
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
                        numbers.push(basic(eq, j + 1, i,vars));
                        i = j;
                        foundMatching = 1;
                    }
                }
            }
            if(!foundMatching)
                return NAN;
        }else{   
        //เพิ่มมันซะไอ้เจ           
    }

    if(tmpc>0)
    {
        reversed=reverseString(tmp,tmpc);
        if(!reversed)
            return NAN;
        numbers.push(strtod(reversed,nullptr));
        free(reversed);
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

    float result=*numbers.at(0);
    if(numbers.size()>1) {
        for (char i = 0; i < plusIndex.size(); ++i) {
            result += *numbers.at(*plusIndex.at(i));
        }
    }
    free(tmp);

    return result;
}