//C++ choose to use RAII rather than finally, or C++ supports RAII does not support finally because
//because "encapsulated resource management provided by RAII in C++ is vastly superior to
//the client responsible approach of the try-catch-finally pattern" as in accu

//Below are the specific code examples where RAII works better than finally

//RAII is better a choice than finally since FileHandle class will close itself
//as the FileHandle destructor is guaranteed to run

//For instance in C++

class CPP_FileHandle {
public:
    FileHandle(const char* name, const char* mode) {
        f_resource = fopen(name, mode);
    }

    FILE* file() {
        return f_resource;
    }

    ~FileHandle() {
        if (f_ != nullptr) {
            fclose(f_resource);
        }
    }

private:
    FILE* f_resource;
};

//vesus in JAVA

void JAVA_FileHandle()
{
    try {
        Resource *resource = get_resource();
        do_something(resource);
    }
    finally {
        free_resource(resource);
        delete resource;
    }
}
