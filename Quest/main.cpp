#include <iostream>
#include "test.h"
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Person person;
    Ticket ticket;
    ofstream fout;
    ifstream fin;
    vector <Ticket> questions;
    fout.open("E:/hello.txt");
    ticket.addTicket(questions, fout);
    fout.close();
    fin.open("E:/hello.txt");
    runQuest(questions, person, ticket, fin);

    //, ios::app


}
