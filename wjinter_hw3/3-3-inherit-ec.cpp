int main()
{
    int i;
    int *ip = new int[10];

    //Since i is unused variable. there is no need to delete &i;
    delete[] ip;
}