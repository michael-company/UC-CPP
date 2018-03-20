#include <iostream>

/*
 dynamic cast can convert pointers and references at run-time, such as casting a pointer or reference up or down in inheritance.

 dynamic_cast(expression)

 "The target type must be a pointer or reference type, and the expression must evaluate to a pointer or reference. Dynamic cast
 works only when the type of object to which the expression refers is compatible with the target type and the base class has at
 least one virtual member function. If not, and the type of expression being cast is a pointer, NULL is returned, if a dynamic
 cast on a reference fails, a bad_cast exception is thrown. When it doesn't fail, dynamic cast returns a pointer or reference of
 the target type to the object to which expression referred." - http://stackoverflow.com/questions/5313322/c-cast-to-derived-class

 */

struct AnimalBase {
    virtual void AnimalCreate() { }
};
struct DogAnimal : public AnimalBase { };
struct CatAnimal { };

void AnimalCreate () {
    AnimalBase a;
    DogAnimal b;

    AnimalBase* ap = &b;
    DogAnimal*  b1 = dynamic_cast<DogAnimal*> (&a);  // NULL, because 'a' is not a 'B'
    DogAnimal*  b2 = dynamic_cast<DogAnimal*> (ap);  // 'b'
    CatAnimal*  c  = dynamic_cast<CatAnimal*> (ap);  // NULL.

    AnimalBase& ar = dynamic_cast<AnimalBase&>(*ap); // Ok.
    DogAnimal&  br = dynamic_cast<DogAnimal&> (*ap); // Ok.
    CatAnimal&  cr = dynamic_cast<CatAnimal&> (*ap); // std::bad_cast
}


//Mover

class Animal {

    virtual void speak() const
    {
        std::cout<<"Base Class: Animal";
    }
};
class Dog: public Animal {};
class Cat: public Animal {};

int main()
{
    Animal  ani;
    Dog     dog;
    Cat     cat;

    Animal& AnimalReference0 = ani;
    Animal& AnimalReference1 = dog;
    Animal& AnimalReference2 = cat;

    Animal* AnimalPointer0 = &ani;
    Animal* AnimalPointer1 = &dog;
    Animal* AnimalPointer2 = &cat;

    Dog& dogRef0 = dynamic_cast<Dog&>(AnimalReference0); //Downcast reference
    Dog* dogPtr0 = dynamic_cast<Dog*>(AnimalPointer0);   //Downcast pointer

    Cat& catRef1 = dynamic_cast<Cat&>(AnimalReference1); //Throws exception  AnimalReference1 is a dog
    Cat* catPtr1 = dynamic_cast<Cat*>(AnimalPointer1);   //Returns NULL      AnimalPointer1 is a dog

    Cat& catRef2 = dynamic_cast<Cat&>(AnimalReference2); //Downcast reference
    Cat* catPtr2 = dynamic_cast<Cat*>(AnimalPointer2);   //Downcast pointer

}