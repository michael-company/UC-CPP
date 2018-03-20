# include <stdio.h>
# include <iostream>
# include <pthread.h>

# define arraySize 10

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
