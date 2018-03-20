# include <stdio.h>
# include <iostream>
# include <pthread.h>

# define arraySize

//created a template version of array that works on as general of ranges as possible (not just vectors of ints)
template <class T>
class Vector
{
private:
    int size,capacity;
    T *dynamic_Array;
public:
    Vector()
    {
        size = capacity = 0;
        dynamic_Array = NULL;
    }

    ~Vector()
    {
        delete [] dynamic_Array;
    }
    Vector(int a)
    {
        size = a;
        dynamic_Array = new T[size];

        for(int i = 0 ; i<size; i++)
        {
            dynamic_Array[i] = NULL;
        }
    }

    T& operator[](int);
    T at(int);
    void insert(int,T);
};

template<class T>
T& Vector<T>::operator[](int index)
{
    return dynamic_Array[index];
}

template<class T>
T Vector<T>::at(int i)
{
    return dynamic_Array[i];
}

template<class T>
void Vector<T>::insert(int i, T e)
{
    dynamic_Array[i] = e;
}

//created a template version of finding max that works on as general of ranges as possible (not just vectors of ints)
template <class findMax> findMax max_element ( findMax first, findMax last )
{
    if (first==last) return last;
    findMax largest = first;
    
    while (++first!=last)
        if (*largest<*first)
            largest=first;
    return largest;
}

struct StructMax
{
    int iMax;
};

int array[arraySize];

void *thread_find_largest(void *);

int main()
{
    pthread_t tid;
    struct StructMax *st_main,*st_th;
    int largest;
    
    st_main=(struct StructMax*)malloc(sizeof(struct StructMax));
    
    int userInput, index;
    
    for(index=0;index<arraySize;index++)
    {
        //typesafe, as in my c++
        std::cout << "Enter Number "<<index+1<<":";
        std::cin >> userInput;
        array[index] = userInput;
    }
    
    pthread_create(&tid,NULL,thread_find_largest,NULL);
    
    std::cout<<"Thread ID: "<<tid<<std::endl;
    
    pthread_create(&tid,NULL,thread_find_largest,NULL);
    
    std::cout<<"Thread ID: "<<tid<<std::endl;
    
    pthread_create(&tid,NULL,thread_find_largest,NULL);
    
    std::cout<<"Thread ID: "<<tid<<std::endl;
    
    st_main->iMax=array[0];
    
    for(index=1;index<arraySize/2;index++)
    {
        if(array[index] > st_main->iMax)
        {
            st_main->iMax=array[index];
        }
        
    }
    
    pthread_join(tid,(void**)&st_th);
    
    if(st_main->iMax >= st_th->iMax)
    {
        largest=st_main->iMax;
    }
    else
    {
        largest=st_th->iMax;
    }
    
    printf("Largest Number: %d \n",largest);
    return 0;
}

void *thread_find_largest(void *)
{
    struct StructMax *st;
    st=(struct StructMax*)malloc(sizeof(struct StructMax));
    
    int index;
    st->iMax=array[arraySize/2];
    
    for(index=arraySize/2 + 1;index<arraySize;index++)
    {
        if(array[index] > st->iMax)
        {
            st->iMax=array[index];
        }
    }
    pthread_exit((void*)st);
}
