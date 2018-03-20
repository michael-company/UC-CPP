//valid C but not CPP.
//CPP is not subset of C

int main()
{
    int class = 5;
    printf(class);
    return 0;
}


//Explanation of what goes wrong when compiled under C++:
//The line int class = 5 causes a declaration of anonymous class must be a definition error.
//The line printf(class) causes a expected expression error.
//
//Moreover,
//
//Programming output in C  uses	 printf for output
//Programming output in C++ uses iostream, fstream (std::cin, std::cout)
//
//Lastly,
//Some key-feature differences
//http://www.diffen.com/difference/C_vs_C%2B%2B