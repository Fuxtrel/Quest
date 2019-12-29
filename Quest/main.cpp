#include <iostream>
#include "test.h"
#include <vector>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Person person;
    Ticket ticket;
    ofstream fout;
    vector <Ticket> questions;
    ticket.addTicket(questions);
    runQuest(questions, person, ticket);
    fout.open("E:/hello.txt");
    for(int i = 0; i < ticket.number; i++){
        fout << questions[i].question << "\n";
        fout << questions[i].answer[0] << "\n";
        fout << questions[i].answer[1] << "\n";
        fout << questions[i].answer[2] << "\n";
        fout << "Ответ: " << questions[i].answer_correct_number << "\n";
    }


}
