#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>

using namespace std;
typedef struct Node node_t;

struct Node{
    Node(string input):text(input),animalCheck(true){}
    string text;
    node_t *yes, *no;
    bool animalCheck;
    void addNode(string animal, string question);
    void ask(){
        if (animalCheck)
            cout<<"Is your animal "<<text<<"? ";
        else
            cout<<text<<' ';
    }
};
void Node::addNode(string animal, string question){
    no = new Node(text);
    question[0] = toupper(question[0]);
    if (question.back()!='?')
        question.push_back('?');
    text = question;
    yes = new Node(animal);
    animalCheck = false;
}
bool tf(){
    string feedback = " ";
    while (true){
        cin>>feedback;
        if (feedback[0]=='Y'||feedback[0]=='y')
            return true;
        else if (feedback[0]=='N'||feedback[0]=='n')
            return false;
        else
            cout<<"Please enter again: y or n ";
    }
}

int main(){
    node_t *root = new Node ("a leopluradon");
    string name;
    while (true){
        cout<<"You are thinking of an animal... "<<endl;
        node_t *current = root;
        char guess;
        while (true) {
            if (current->animalCheck) {
                current->ask();
                guess = tf();
                if (guess==true){
                    cout<<"Well I'll be. I know what animal you were thinking of."<<endl;
                }
                else {
                    string answer, question;
                    cout<<"What animal did you pick? ";
                    getline(ws(cin), answer);
                    cout<<"A question is true for "<<answer<<" is not true for "<<current->text<<"?\n";
                    getline(ws(cin), question);
                    current->addNode(answer, question);
                }
            }
            else {
                current->ask();
                guess = tf();
                if (guess == true)
                    current = current->yes;
                else
                    current = current->no;
            }
        }
    }
}
